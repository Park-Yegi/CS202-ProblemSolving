/* 2017 ACM ICPC Asia Regional - Daejeon
 * Problem C */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int name;
	int neighbor[4000];
	int deg;
}Node;

typedef int (*compare)(const void*,const void*);
 
int CompareByNum(const void *v1, const void *v2)
{
   const Node *m1 = (const Node *)v1;
   const Node *m2 = (const Node *)v2;
   return m2->deg - m1->deg;
}

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

	/* sort the vertices in order of degree decreasing */
	qsort(Vertex,n,sizeof(Node),CompareByNum);

	/* 
	 * DP[i] = DP[j]+1 if j is adjacent node and has bigger degree
	 * DP[i] = 0 if there's no j with the condition
	 */
	for (i = 0; i < n; i++){
		v = Vertex[i].name;
		len = deg[v];
		max = 0;
		for (j = 0; j < len; j++){
			if (Vertex[Vertex[v].neighbor[j]].deg > len){
				if (DP[Vertex[v].neighbor[j]]+1 > max){
					max = DP[Vertex[v].neighbor[j]]+1;
					// printf("(%d, %d) %d\n", v, Vertex[v].neighbor[j], max);
				}
			}
		}
		if (max == 0)
			DP[i] = 1;
		else
			DP[i] = max;
	}

	/* find maximum in DP */
	max = DP[0];
	for (i = 1; i < n; i++){
		if (DP[i] > max)
			max = DP[i];
	}
	// for (i=0; i<n ; i++){
	// 	printf("%d\n", DP[i]);
	// }
	printf("%d\n", max);

	return 0;
}

