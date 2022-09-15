#include <stdio.h>

#define LEN 6

void stampa(int*, int);

int a[LEN] = { 0, 1, 2, 3, 4, 5 };

int main(){
	stampa(a, LEN);

	int i = 2;
	printf("%d = %d\n", a[i]);

	return 0;
}

//GLI ARRAY SONO SEMPRE PASSATI COME PUNTATORI!!!
void stampa(int *a, int n){
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);

	printf("\n");
}
