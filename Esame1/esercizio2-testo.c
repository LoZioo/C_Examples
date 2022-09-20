/*
  Sviluppo di applicazione in ANSI C per gestire le code di un ufficio postale.

  In un file di testo ("prenotato.txt"), è memorizzato l'elenco dei prenotati.
  Per ciascuno dei prenotati è memorizzato il nome, il cognome e il tipo di
  operazione.

  Si assuma che il nome e cognome non contengano spazi.

  In un secondo file Struttura.txt contiene nella prima riga un intero che rappresenta il numero di operazioni
  previste e nelle righe successive, una per riga, una stringa senza bianchi che descrive il tipo
  di operazione

  Implementare le seguenti funzioni:

  1. CaricaOperazioni: carica le operazioni presenti nel file in un
  vettore. Il numero degli elementi del vettore è uguale al numero possibili di operazioni
  (presenti nel file Struttura.txt) e contiene in ciascun elemento la stringa che descrive il
  tipo di operazione e la code delle operazioni di quel tipo 

  2. Operazione: dato il tipo di operazione, rimuove il primo cliente
  dalla coda corrispondente e lo introduce nella lista delle operazioni
  effettuate. La lista delle operazioni effettuate contiene come informazione
  sia il cliente che il tipo di operazione.

  3. EstraiNumeroDiOperazioni: data la lista delle operazioni calcola il numero
  di operazione di un dato tipo.

  La descrizione dettagliata di ogni funzione è riportata come
  commento immediatamente prima della definizione della funzione.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 64

#define STRUTTURA_TXT "Struttura.txt"
#define PRENOTATI_TXT "prenotati.txt"

typedef struct node_content{
	char nome[STRING_SIZE];
	char cognome[STRING_SIZE];
	int operazione;
} node_content_t;

typedef struct node{
	node_content_t data;
	struct node *next;
} node_t;

int list_size(node_t **list);
void enque(node_t **list, node_content_t content);
node_content_t deque(node_t **list);
void list_print(node_t **list);

FILE *struttura, *prenotati;

int n_ops;

char **op;
node_t **code;

node_t *serviti;

int main(){
	struttura = fopen(STRUTTURA_TXT, "r");

	if(!struttura){
		printf("Errore nell'apertura di %s.\n", STRUTTURA_TXT);
		return -1;
	}

	fscanf(struttura, "%d", &n_ops);

	//Allocazione effettiva degli spazi in memoria.
	op = malloc(n_ops * sizeof(char*));
	for(int i=0; i<n_ops; i++)
		op[i] = malloc(STRING_SIZE);
	
	code = malloc(n_ops * sizeof(node_t*));

	//Lettura operazioni da Struttura.txt.
	for(int i=0; i<n_ops; i++)
		fscanf(struttura, "%s", op[i]);

	fclose(struttura);



	prenotati = fopen(PRENOTATI_TXT, "r");

	char nome[STRING_SIZE], cognome[STRING_SIZE], operazione[STRING_SIZE];
	int op_index;

	while(!feof(prenotati)){
		fscanf(prenotati, "%s %s %s", nome, cognome, operazione);

		op_index = 0;
		int trovato = 0;
		while(op_index < n_ops && !trovato){
			if(strcmp(op[op_index], operazione) == 0)
				trovato = 1;
			
			op_index++;
		}
		op_index--;

		//La ricerca finisce sempre con successo, quindi non c'è bisogno dell'if di verifica...
		node_content_t nuovo;

		strcpy(nuovo.nome, nome);
		strcpy(nuovo.cognome, cognome);
		nuovo.operazione = op_index;

		//Metto in coda l'elemento nuovo.
		enque(&code[op_index], nuovo);
	}

	fclose(prenotati);

	list_print(&code[0]);
	list_print(&code[1]);
	list_print(&code[2]);

	// for(int i=0; i<n_ops; i++)
	// 	printf("%s\n", op[i]);

	return 0;
}

int list_size(node_t **list){
	int n = 0;

	node_t *node = *list;
	while(node != NULL){
		node = node->next;
		n++;
	}

	return n;
}

void enque(node_t **list, node_content_t content){
	if(*list == NULL){
	  *list = malloc(sizeof(node_t));

		(*list)->data = content;
		(*list)->next = NULL;
		
		return;
	}

	//Creo il nuovo nodo.
	node_t *head = malloc(sizeof(node_t));

	head->data = content;
	head->next = *list;

	*list = head;
}

node_content_t deque(node_t **list){
	node_content_t tmp;
	
	if(*list == NULL){
		strcpy(tmp.nome, "");
		strcpy(tmp.cognome, "");
		tmp.operazione = -1;

		return tmp;
	}

	//Un solo elemento da estrarre.
	if(list_size(list) == 1){
		tmp = (*list)->data;
		
		free(*list);
		*list = NULL;

		return tmp;
	}

	//Dobbiamo fare puntare node al penultimo nodo.
	node_t *node = *list;
	while(node->next->next != NULL)
		node = node->next;
	
	tmp = node->next->data;

	free(node->next);
	node->next = NULL;

	return tmp;
}

void list_print(node_t **list){
	if(*list == NULL){
		printf("Lista vuota.\n");
		return;
	}

	while(*list != NULL){
		printf("%s, %s, %s\n", (*list)->data.nome, (*list)->data.cognome, op[(*list)->data.operazione]);
		(*list) = (*list)->next;
	}

	printf("\n");
}
