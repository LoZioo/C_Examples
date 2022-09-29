#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_MAXLEN 50

typedef struct content node_content_t;
typedef struct node node_t;

int size(node_t **list);																	//Torna la dimensione della lista.
int isEmpty(node_t **list);																//Torna 1 se la lista è vuota, 0 altrimenti.

node_content_t get(node_t **list, int index);							//Ritorna l'elemento di posto "index", se esiste, altrimenti torna un errore.

void append(node_t **list, node_content_t content);				//Appende in coda alla lista il nodo "node".
int delete(node_t **list, int index);											//Cancella l'elemento di posto "index", se esiste, e ritorna il risultato dell'operazione.

/*
	Cerca l'elemento con chiave key all'interno della lista, restituendo un errore in caso
	di insuccesso oppure l'indice dell'elemento trovato nel caso di successo.
	Inoltre, "searched" dovrà contenere, solamente nel caso di successo, il puntatore all'elemento trovato.
*/
int searchByKey(node_t **list, node_content_t *searched);

void print_list(node_t **list);														//Stampa la lista.

/**
 * Gestire i seguenti casi limite:
 * 	Cancellare/Get di un elemento che non esiste.
 * 	Inserimento del primo elemento.
 * 	Size della lista vuota.
*/

typedef struct content{
	int key;

	char nome[STRING_MAXLEN];
	char cognome[STRING_MAXLEN];

} node_content_t;

typedef struct node{
	node_content_t data;
	node_t *next;
} node_t;

node_t *begin = NULL;

int main(){
	node_content_t data;

	// printf("%s\n", isEmpty(&begin) ? "true" : "false");

	data.key = 1;
	strcpy(data.nome, "Davide");
	strcpy(data.cognome, "Scalisi");
	append(&begin, data);

	// printf("%s\n", isEmpty(&begin) ? "true" : "false");

	data.key = 2;
	strcpy(data.nome, "Cristian");
	strcpy(data.cognome, "Cocuz");
	append(&begin, data);

	data.key = 3;
	strcpy(data.nome, "Vincenzo");
	strcpy(data.cognome, "Pagano");
	append(&begin, data);

	data.key = 6;
	strcpy(data.nome, "Gabriele");
	strcpy(data.cognome, "Lovec");
	append(&begin, data);

	data.key = 9;
	strcpy(data.nome, "Simone");
	strcpy(data.cognome, "Alecci");
	append(&begin, data);

	// printf("size: %d\n", size(&begin));
	print_list(&begin);

	// int index = 2;
	// printf("%do elemento: %d\n", index, get(&begin, index).key);

	// index = 1;
	
	// delete(&begin, index);
	// print_list(&begin);

	// delete(&begin, index);
	// print_list(&begin);
	
	// delete(&begin, index);
	// print_list(&begin);

	// delete(&begin, index);
	// print_list(&begin);

	// delete(&begin, index);
	// print_list(&begin);

	// delete(&begin, 0);
	// print_list(&begin);

	node_content_t searched;
	searched.key = 9;

	int res = searchByKey(&begin, &searched);

	printf("Risultato ricerca: %d\n", res);

	if(res >= 0)
		printf("Nome: %s\nCognome: %s\n\n", searched.nome, searched.cognome);

	return 0;
}

int size(node_t **list){
	int n = 0;

	node_t *node = *list;
	while(node != NULL){
		node = node->next;
		n++;
	}

	return n;
}

int isEmpty(node_t **list){
	return (list == NULL || *list == NULL) ? 1 : 0;
}

node_content_t get(node_t **list, int index){
	if(isEmpty(list)){
		node_content_t err;
		err.key = -1;

		return err;
	}

	if(index < 0 || index >= size(list)){
		node_content_t err;
		err.key = -2;

		return err;
	}

	node_t *node = *list;
	for(int i=0; i<index; i++)
		node = node->next;
	
	return node->data;
}

void append(node_t **list, node_content_t content){
	//Caso di lista vuota.
	if(isEmpty(list)){
		*list = malloc(sizeof(node_t));

		(*list)->data = content;
		(*list)->next = NULL;

		return;
	}

	//Caso di lista non vuota.
	//Prendo l'ultimo nodo della lista.
	node_t *last = *list;
	while(last->next != NULL)
		last = last->next;
	
	//Creo il nuovo nodo.
	node_t *node = malloc(sizeof(node_t));
	node->data = content;
	node->next = NULL;

	//Linko la lista.
	last->next = node;
}

int delete(node_t **list, int index){
	if(isEmpty(list))
		return -1;
	
	if(index < 0 || index >= size(list))
		return -2;
	
	node_t *deleted_node;

	//Caso particolare in cui si vuole cancellare il primo elemento.
	if(index == 0){
		deleted_node = *list;
		*list = deleted_node->next;

		free(deleted_node);
		return 0;
	}
	
	//Andiamo all'elemento di posto index - 1 (elemento prima dell'elemento da cancellare).
	node_t *node = *list;

	for(int i=0; i<index - 1; i++)
		node = node->next;
	
	deleted_node = node->next;
	node->next = deleted_node->next;

	free(deleted_node);
	return 0;
}

int searchByKey(node_t **list, node_content_t *searched){
	if(isEmpty(list))
		return -2;

	if(searched == NULL)
		return -3;

	node_t *node = *list;
	int trovato = 0;
	int i = 0;

	while(node != NULL && !trovato){
		if(node->data.key == searched->key){
			trovato = 1;
			continue;
		}

		node = node->next;
		i++;
	}

	if(trovato){
		*searched = node->data;
		return i;
	}

	return -1;
}

void print_list(node_t **list){
	if(isEmpty(list)){
		printf("Lista vuota.\n");
		return;
	}

	node_t *node = *list;
	while(node != NULL){
		printf("key: %d\nnome: %s\ncognome: %s\n\n", node->data.key, node->data.nome, node->data.cognome);
		node = node->next;
	}
}
