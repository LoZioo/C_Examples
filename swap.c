#include <stdio.h>

//Se torna void, si chiama procedura.
//Se torna qualche altro valore, si chiama funzione.

//Dichiarazione della funzione swap.
void swap(int*, int*);

int val1 = 10, val2 = 15;

int main(){
	printf("val1: %d, val2: %d\n", val1, val2);

	//Chiamata della funzione swap.
	//Questi si chiamano parametri attuali (attuali istanze di x = val1 ed y = val2)
	swap(&val1, &val2);

	printf("val1: %d, val2: %d\n", val1, val2);

	//Parametri attuali (attuali istanze di x = val2 ed y = val1)
	swap(&val2, &val1);

	printf("val1: %d, val2: %d\n", val1, val2);
	return 0;
}

//Definizione della funzione swap (i parametri qui' si chiamano parametri formali).
void swap(int *x, int *y){
	int tmp;		//Variabile di scambio.
	
	tmp = *x;
	*x = *y;
	*y = tmp;
}
