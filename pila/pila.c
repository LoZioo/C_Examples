#include <stdio.h>

#define MAX_DIM 100

void push(int);
int pop();

int arr[MAX_DIM];
int arr_index = 0;			//Punta al prossimo spazio libero nell'array.

int main(){
	push(10);
	push(15);
	push(20);

	int tmp;

	tmp = pop();
	printf("pop(): %d, arr_index = %d\n", tmp, arr_index);

	tmp = pop();
	printf("pop(): %d, arr_index = %d\n", tmp, arr_index);

	tmp = pop();
	printf("pop(): %d, arr_index = %d\n", tmp, arr_index);

	push(30);

	tmp = pop();
	printf("pop(): %d, arr_index = %d\n", tmp, arr_index);

	return 0;
}

void push(int n){
	arr[arr_index] = n;
	arr_index++;
}

int pop(){
	arr_index--;
	return arr[arr_index];
}
