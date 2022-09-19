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

#define STRING_SIZE 64

#define STRUTTURA_TXT "Struttura.txt"
#define PRENOTATI_TXT "prenotati.txt"

typedef struct node_content{
	char nome[STRING_SIZE];
	char cognome[STRING_SIZE];
	char operazione[STRING_SIZE];
} node_content_t;

typedef struct node{
	node_content_t data;
	struct node *next;
} node_t;

int sizelist(node_t *list);
node_t* enque (node_t *list, node_content_t *contenuto);

FILE *struttura, *prenotati;

int n_ops;

char **op;
node_t **code;

node_t *serviti;
 
 node_content_t dieta;


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

	for(int i=0; i<n_ops; i++)
		fscanf(struttura, "%s", op[i]);
	
	// for(int i=0; i<n_ops; i++)
	// 	printf("%s\n", op[i]);

	fclose(struttura);

	printf("%d", sizelist (code[1]));

	dieta.nome = piero;
 	dieta.cognome = fasulli;
 	dieta.operazione = pacco;
 

	enque(v[1], dieta);

	return 0;
}

int sizelist(node_t *list){
	int n=0;
	while(list != NULL){
		list = list->next;
		n++;
	}
	return n;
}

node_t* enque(node_t *list, node_content_t contenuto){
	node_t tmp;
	
	if(list==NULL){
		tmp.data = contenuto;
		list = list->next;

	}

	return list;
}

