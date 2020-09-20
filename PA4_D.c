/* 2017 ACM ICPC Asia Regional - Daejeon
 * Problem D */

#include <stdio.h>
#include <math.h>

int func(int n);

int main(void){
	int n, n_keep, i;
	scanf("%d", &n);
	n_keep = n;

	// while(1){
	// 	n = func(n);
	// 	if (n == 1){
	// 		printf("HAPPY\n");
	// 		return 0;
	// 	}
	// 	if (n == n_keep){
	// 		printf("UNHAPPY\n");
	// 		return 0;
	// 	}
	// }
	for (i=0; i<1000; i++){
		n = func(n);
	}
	if (n == 1){
		printf("HAPPY\n");
	}
	else{
		printf("UNHAPPY\n");
	}

	return 0;
}


int func(int n){
	int result = 0;
	int n_divided = n;
	int mod, remainder;

	if (n == 0)
		return 0;

	while (n != 0){
		remainder = n % 10;
		result += pow((double)remainder, 2.0);
		n = n / 10;
	}

	return result;
}