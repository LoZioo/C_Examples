#include <stdlib.h>
#include <stdio.h>

typedef struct content node_content_t;
typedef struct node node_t;

int size(node_t *list);																//Torna la dimensione della lista.
int isEmpty(node_t *list);														//Torna 1 se la lista è vuota, 0 altrimenti.

node_content_t get(node_t *list, int index);					//Ritorna l'elemento di posto "index", se esiste.

node_t* append(node_t *list, node_content_t content);	//Appende in coda alla lista il nodo "node"; torna il puntatore alla testa della lista.
int delete(node_t *list, int index);									//Cancella l'elemento di posto "index", se esiste e ritorna il risultato dell'operazione.

int search(node_t *list, node_content_t *searched);		//Cerca l'elemento searched all'interno della lista, restituendo -1 in caso di insuccesso
																											//oppure l'indice dell'elemento trovato nel caso di successo.
																											//Inoltre, "searched" dovrà contenere, solamente nel caso di successo, il puntatore all'elemento trovato.
/**
 * Gestire i seguenti casi limite:
 * 	Cancellare/Get di un elemento che non esiste.
 * 	Inserimento del primo elemento.
 * 	Size della lista vuota.
*/

typedef struct content{
	int key;
} node_content_t;

typedef struct node{
	node_content_t data;
	node_t *next;
} node_t;

node_t *begin = NULL;

int main(){
	node_content_t data;
	data.key = 2;

	printf("%s\n", isEmpty(begin) ? "true" : "false");
	begin = append(begin, data);
	printf("%s\n", isEmpty(begin) ? "true" : "false");

	return 0;
}

int size(node_t *list){
	if(isEmpty(list))
		return 0;
	
	int n = 0;
	node_t *current = list;

	while(current != NULL){
		current = current->next;
		n++;
	}

	return n;
}

int isEmpty(node_t *list){
	return begin == NULL ? 1 : 0;
}

node_content_t get(node_t *list, int index){}

node_t* append(node_t *list, node_content_t content){
	if(isEmpty(list)){
		list = malloc(sizeof(node_t));

		list->data = content;
		list->next = NULL;

		return list;
	}

	//Caso di lista non vuota.
}

int delete(node_t *list, int index){}

int search(node_t *list, node_content_t *searched){}
