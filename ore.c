/**************************

Scrivete una funzione con prototipo void split_time ( long int tot_sec, int *h, int *m, int *s ) che,
dato un orario fornito in numero di secondi dalla mezzanotte, calcoli l’orario equivalente in ore, minuti, secondi, e lo
memorizzi nelle tre variabili puntate da (h), (m) e (s) rispettivamente.

***************************/
#include <stdio.h>

void split_time (long int, int*, int*, int*);

long int tot_sec;
int h=0, m=0, s=0;

int main()
{
    printf("inserisci numero di secondi passati dalla mezzanotte ");
    scanf("%ld", &tot_sec);
    
    split_time(tot_sec, &h, &m, &s);
    
    printf("%d:%d:%d", h, m, s);

    return 0;
}

void split_time (long int tot_sec, int *h, int *m, int *s){
    
    *s = tot_sec % 60;
    *m = tot_sec / 60;
    *h = *m / 60;
    
    
}