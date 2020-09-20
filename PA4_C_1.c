/* 2017 ACM ICPC Asia Regional - Daejeon
 * Problem C */

#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000

int n, m;
int DP[MAXN];
int order[MAXN];
int deg[MAXN] = {0, };
int * nei[MAXN];

int compare(const void *a, const void *b){
	if (deg[*(int *)a] < deg[*(int *)b])
		return 1;
	else if (deg[*(int *)a > deg[*(int *)b]])
		return -1;
	else
		return 0;
}


int main(void){
	int i, j, a, b, v;
	int max, len;

	/* get standard input n, m and the information about edges */
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		*(nei[a] + deg[a]) = b;
		*(nei[b] + deg[b]) = a;
		deg[a] += 1;
		deg[b] += 1;
	}

	/* sort the vertices in order of degree decreasing */
	for (i = 0; i < n; i++)
		order[i] = i;
	qsort(order, n, 4, compare);

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