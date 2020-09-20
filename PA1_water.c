/* 
 * After receiving the capacity and desired final state as input, 
 * write a program that starts with both empty containers 
 * and determines the minimum number of operations to reach the final state. 
 */



#include <stdio.h>
int gcd(int a, int b);
int method(int a, int b, int c, int d);
int CheckFinish(int c, int d, int a_beaker, int b_beaker);

int main(void){
	int g;
	int a, b, c, d;
	int m1, m2, min;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	if (c==a && d==b){
		printf("%d \n", 2);
		return 0;
	}
	if (c==0 && d==0){
		printf("%d \n", 0);
		return 0;
	}
	if (!(a==c || c==0 || b==d || d==0)){
		printf("%d \n", -1);
		return 0;
	}

	g = gcd(a, b);
	if (c%g != 0 || d%g != 0){
		printf("%d \n", -1);
		return 0;
	}	

	m1 = method(a, b, c, d);
	m2 = method(b, a, d, c);
	min = m1;
	if (m2<m1)
		min = m2;
	printf("%d \n", min);
	return 0;
}

int CheckFinish(int c, int d, int a_beaker, int b_beaker){
	if ((c==a_beaker) && (d==b_beaker))
		return 1;
	return 0;
}

int gcd(int a, int b){
	int min = a;
	int g=1, i=1;
	if (a>b){
		min = b;
	}
	for (i = 1; i<= min; i++){
		if (a%i == 0 && b%i == 0)
		g = i;
	}
	return g;
}

int method(int a, int b, int c, int d){
	int count=1;
	int a_beaker = a, b_beaker = 0;
	int temp;

	while (!CheckFinish(c, d, a_beaker, b_beaker)){
		if (a_beaker + b_beaker <= b){
			b_beaker += a_beaker;
			a_beaker = 0;
			count++;
		}else{
			temp = b - b_beaker;
			b_beaker = b;
			a_beaker -= temp;
			count++;
		}
		
		if ((a_beaker == 0) && !CheckFinish(c, d, a_beaker, b_beaker)){
			a_beaker = a;
			count++;
		}
		if ((b_beaker == b) && !CheckFinish(c, d, a_beaker, b_beaker)){
			b_beaker = 0;
			count++;
		}
	}
	return count;
}

