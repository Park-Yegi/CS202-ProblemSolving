/* 2017 ACM ICPC Asia Regional - Daejeon
 * Problem C */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int name;
	int neighbor[4000];
	int deg;
}Node;


int main(void){
	int n, m, i, j, a, b, v;
	int max, len;
	int DP[500];
	int deg[500] = {0, };
	Node Vertex[500];


	/* get standard input n, m and the information about edges */
	scanf("%d %d", &n, &m);
	for (i=0; i < n; i++){
		Vertex[i].deg = 0;
		Vertex[i].name = i;
	}

	for (i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		Vertex[a].neighbor[deg[a]] = b;
		Vertex[b].neighbor[deg[b]] = a;
		deg[a] += 1;
		deg[b] += 1;
		Vertex[a].deg += 1;
		Vertex[b].deg += 1;
	}
	printf("1\n");

	return 0;
}

