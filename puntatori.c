#include <stdio.h>

int main(){
	//Un puntatore punta ad uno spazio in memoria o a niente (NULL).
	//Il puntatore in sé è grosso in generale, 32 bit se il sistema è a 32 bit o 64 bit se il sistema è a 64 bit.

	//Tipi puntatori classici.
	int *ptr;
	char *str;
	
	//I tipi puntatori a void sono puntatori generici (ad un generico tipo), ma non possono essere dereferenziati!
	int test = 100;
	void *general_pointer = &test;

	printf("%d\n", test);
	printf("%d\n", *((int*) general_pointer));

	//------------------------------------------------------------------------------------------------------------------------//

	int a = 10;
	int *b = &a;

	// a		il valore di a.
	// &a		l'indirizzo della locazione di memoria di a.
	// b		il puntatore b.
	// *b		il valore puntato dal puntatore di b (in questo caso il valore 10 contenuto in a).

	printf("%d\n", a);
	printf("%d\n", *b);

	struct tipo_del_mio_dato{
		int le;
		int sus;
		int sono;
		int belle;
	};

	typedef struct tipo_del_mio_dato bel_dato;

	struct tipo_del_mio_dato a1;
	bel_dato a2;

	return 0;
}
