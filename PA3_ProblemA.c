/* The 42th Annual ACM
 * International Collegiate Programming Contest
 * Asia Regional - Daejeon
 * Problem A */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int compare(void *first, void *second);
int large_closest(int p[], int start, int last, int q);
int small_closest(int p[], int start, int last, int q);
int same(int p[], int start, int last, int q);


int main(void){
	int n, m, c1, c2, i, j;
	int p[500000];
	int q;
	int min, count, temp, prev;
	int start=0;
	int first_time=1;
	int diff_larger, diff_smaller;
	int same_diff=0;

	scanf("%d %d", &n, &m);
	scanf("%d %d", &c1, &c2);
	for (i=0; i<n; i++)
		scanf("%d", &p[i]);
	qsort(p, n, 4, compare);

	for (i=0; i<m; i++)
	{
		scanf("%d", &q);
		if (same(p, 0, n-1, q) == 1)
		{
			if (first_time)
			{
				min = 0;
				count = 1;
				first_time = 0;
			}
			else
			{
				if (min == 0)
					count++;
				else
				{
					count = 1;
					min = 0;
				}
			}
		}
		else
		{
			if (q < p[0])
				temp = p[0] - q;
			else if (q > p[n-1])
				temp = q - p[n-1];
			else
			{
				diff_larger = large_closest(p, 0, n-1, q) - q;
				diff_smaller = q - small_closest(p, 0, n-1, q);
				temp = MIN(diff_smaller, diff_larger);
				if (diff_larger == diff_smaller)
					same_diff = 1;
			}
			if (first_time)
			{
				min = temp;
				count = 1+same_diff;
				first_time = 0;
			}
			else
			{
				if (min == temp)
					count += 1+same_diff;
				else if (min > temp)
				{
					min = temp;
					count = 1+same_diff;
				}
			}
			same_diff = 0;
		}
	}

	min += abs(c1-c2);
	printf("%d %d\n", min, count);
	return 0;
}


int compare(void *first, void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}


int large_closest(int p[], int start, int last, int q)
{
	int mid = start + (last-start)/2;
	if (p[mid] <= q)
		return large_closest(p, mid+1, last, q);
	if (p[mid-1] <= q)
		return p[mid];
	else
		return large_closest(p, start, mid-1, q);
}


int small_closest(int p[], int start, int last, int q)
{
	int mid = start + (last-start)/2;
	if (p[mid] >= q)
		return small_closest(p, start, mid-1, q);
	if (p[mid+1] >= q)
		return p[mid];
	else
		return small_closest(p, mid+1, last, q);
}


int same(int p[], int start, int last, int q)
{
	if (last >= start)
	{
		int mid = start + (last-start)/2;

		if (p[mid] == q) return 1;
		if (p[mid] > q) return same(p, start, mid-1, q);
		return same(p, mid+1, last, q);
	}
	return 0;
}






