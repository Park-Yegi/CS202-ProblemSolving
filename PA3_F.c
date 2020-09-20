/* The 42th Annual ACM
 * International Collegiate Programming Contest
 * Asia Regional - Daejeon
 * Problem F */

#include <stdio.h>


double FindMin_double(double intersect[], int n);
int FindMin_int(int upperX[], int sub_upperX[], int count);


int main(void)
{
	int minY, maxY;
	int n, m, i, j;
	int upperX[100000];
	int sub_upperX[100000];
	int lowX[100000];
	double query[100000];
	double intersect[100000];
	double minX;
	int minX_of_maxY;
	int count = 0;

	scanf("%d %d", &maxY, &minY);
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d", &upperX[i], &lowX[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; ++i)
	{
		scanf("%lf", &query[i]);
	}

	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
			intersect[j]=((query[i]-maxY)*(upperX[j]-lowX[j])/(maxY-minY)) +upperX[j];
		minX = FindMin_double(intersect, n);
		for (j = 0; j < n; ++j)
		{
			if (intersect[j] == minX)
			{
				sub_upperX[count] = j+1;
				count++;
			}
		}

		if (count == 1)
			printf("%d\n", sub_upperX[0]);
		else
		{
			minX_of_maxY = FindMin_int(upperX, sub_upperX, count);
			for (j=0; j<count; j++)
			{
				if (minX_of_maxY == upperX[sub_upperX[j]-1])
				{
					printf("%d\n", sub_upperX[j]);
					break;
				}
			}
		}
		count = 0;
	}
	return 0;
}


double FindMin_double(double intersect[], int n)
{
	int i;
	double min = intersect[0];

	for (i = 1; i < n; i++)
	{
		if (intersect[i] < min)
			min = intersect[i];
	}
	return min;
}


int FindMin_int(int upperX[], int sub_upperX[], int count)
{
	int i;
	int min = upperX[sub_upperX[0]];

	for (i = 1; i < count; i++)
	{
		if (upperX[sub_upperX[i]-1] < min)
			min = upperX[sub_upperX[i]-1];
	}
	return min;
}

