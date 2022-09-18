#include <stdlib.h>
#include <stdio.h>

typedef struct content node_content_t;
typedef struct node node_t;

int size(node_t *list);																		//Torna la dimensione della lista.
int isEmpty(node_t *list);																//Torna 1 se la lista è vuota, 0 altrimenti.

node_content_t get(node_t *list, int index);							//Ritorna l'elemento di posto "index", se esiste.

node_t* append(node_t *list, node_content_t content);			//Appende in coda alla lista il nodo "node"; torna il puntatore alla testa della lista.
node_t* delete(node_t *list, int index);									//Cancella l'elemento di posto "index", se esiste, e ritorna il risultato dell'operazione.

int search(node_t *list, node_content_t *searched);				//Cerca l'elemento searched all'interno della lista, restituendo -1 in caso di insuccesso
																													//oppure l'indice dell'elemento trovato nel caso di successo.
																													//Inoltre, "searched" dovrà contenere, solamente nel caso di successo, il puntatore all'elemento trovato.

void print_list(node_t *list);														//Stampa la lista.

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
	data.key = 1;
	
	// printf("%s\n", isEmpty(begin) ? "true" : "false");
	begin = append(begin, data);

	data.key = 2;
	// printf("%s\n", isEmpty(begin) ? "true" : "false");
	append(begin, data);

	data.key = 3;
	append(begin, data);

	data.key = 6;
	append(begin, data);

	data.key = 9;
	append(begin, data);

	// printf("size: %d\n", size(begin));
	print_list(begin);

	int index = 2;
	// printf("%do elemento: %d\n", index, get(begin, index).key);

	index = 1;
	begin = delete(begin, index);
	print_list(begin);
	
	begin = delete(begin, index);
	print_list(begin);

	begin = delete(begin, index);
	print_list(begin);

	begin = delete(begin, index);
	print_list(begin);

	begin = delete(begin, 0);
	print_list(begin);

	begin = append(begin, data);
	begin = append(begin, data);
	begin = append(begin, data);
	begin = append(begin, data);
	begin = append(begin, data);
	print_list(begin);

	return 0;
}

int size(node_t *list){
	if(isEmpty(list))
		return 0;
	
	int n = 0;
	while(list != NULL){
		list = list->next;
		n++;
	}

	return n;
}

int isEmpty(node_t *list){
	return begin == NULL ? 1 : 0;
}

node_content_t get(node_t *list, int index){
	if(isEmpty(list)){
		node_content_t err;
		err.key = -1;

		return err;
	}

	if(index < 0 || index > size(list)){
		node_content_t err;
		err.key = -2;

		return err;
	}

	for(int i=0; i<index; i++)
		list = list->next;
	
	return list->data;
}

node_t* append(node_t *list, node_content_t content){
	//Caso di lista vuota.
	if(isEmpty(list)){
		list = malloc(sizeof(node_t));

		list->data = content;
		list->next = NULL;

		return list;
	}

	//Caso di lista non vuota.
	//Prendo l'ultimo nodo della lista.
	node_t *last = list;
	while(last->next != NULL)
		last = last->next;
	
	//Creo il nuovo nodo.
	node_t *node = malloc(sizeof(node_t));
	node->data = content;
	node->next = NULL;

	//Linko la lista.
	last->next = node;
	
	return list;
}

node_t* delete(node_t *list, int index){
	if(isEmpty(list) || index < 0 || index > size(list))
		return list;
	
	node_t *deleted_node;

	//Caso particolare con un solo elemento.
	if(index == 0){
		deleted_node = list;
		list = deleted_node->next;

		free(deleted_node);
		return list;
	}
	
	//Andiamo all'elemento di posto index - 1 (elemento prima dell'elemento da cancellare).
	for(int i=0; i<index - 1; i++)
		list = list->next;
	
	deleted_node = list->next;
	list->next = deleted_node->next;

	free(deleted_node);
	return list;
}

// int search(node_t *list, node_content_t *searched){
//     while(list != NULL && list->node_content_t != searched){
//         list = list->next;
//     }
//     *searched = list->node_content_t
//     return list;
// }

void print_list(node_t *list){
	if(isEmpty(list)){
		printf("Lista vuota.\n");
		return;
	}

	while(list != NULL){
		printf("%d, ", list->data.key);
		list = list->next;
	}

	printf("\n");
}
