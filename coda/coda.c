#include <stdio.h>

#define MAX_DIM 100

void enque(int);
int deque();
void shift(int*, int);

int arr[MAX_DIM];
int arr_index = 0;		//Punta al prossimo spazio libero nell'array (stack pointer).

int main(){
	enque(10);
	enque(15);
	enque(20);

	int tmp;

	tmp = deque();
	printf("deque(): %d, arr_index = %d\n", tmp, arr_index);

	tmp = deque();
	printf("deque(): %d, arr_index = %d\n", tmp, arr_index);

	tmp = deque();
	printf("deque(): %d, arr_index = %d\n", tmp, arr_index);

	return 0;
}

void enque(int n){
	arr[arr_index] = n;
	arr_index++;
}
		
int deque(){
	int ret = arr[0];
	shift(arr, arr_index);

	arr_index--;
	return ret;
}

void shift(int *a, int n){
	for(int i=1; i<n; i++)
		a[i-1] = a[i];
}
