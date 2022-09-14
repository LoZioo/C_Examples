#include <stdio.h>

int calcPow(int base, int exp, int *val){
	if(exp == 0)
		return base;

	int tmp = base * (*val);

	return calcPow(tmp, exp - 1, &tmp);
}

int main(){
	int base = 2;
	int exp = 5;

	printf("%d\n", calcPow(base, exp, &base));
	return 0;
}
