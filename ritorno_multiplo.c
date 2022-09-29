#include <stdio.h>

void somma_storta(int*, int);

int main(){
	int a = 2, b = 3;
	somma_storta(&a, b);

	printf("%d\n", a);
	return 0;
}

void somma_storta(int *primo_operando, int secondo_operando){
	*primo_operando = *primo_operando + secondo_operando;
}
