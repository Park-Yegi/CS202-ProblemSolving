/* The 42th Annual ACM
 * International Collegiate Programming Contest
 * Asia Regional - Daejeon
 * Problem L */

#include <stdio.h>

int intensity(int path[][10000], int tele[][3000], int l, int m, int pos);

int main(void)
{
	int i, j;
	int n, l, m, W;
	int count = 0;
	int path[100][10000];
	int tele[100][3000];


	scanf("%d %d %d %d", &n, &l, &m, &W);
	for (i=0; i<m; i++){
		for (j=0; j<n; j++)
			scanf("%d", &path[i][j]);
	}
	for (i=0; i<m; i++){
		for (j=0; j<l; j++)
			scanf("%d", &tele[i][j]);
	}

	for (i=0; i<n-l+1; i++){
		if (intensity(path, tele, l, m, i) > W)
			count++;
	}

	printf("%d\n", count);

	return 0;
}


int intensity(int path[][10000], int tele[][3000], int l, int m, int pos)
{
	int sum = 0;
	int i, j;

	for (i=0; i<m; i++){
		for (j=0; j<l; j++)
			sum += path[i][j+pos]*tele[i][j];
	}

	return sum;
}