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
	double slope[100000]; //사실 기울기의 역수임
	double query[100000];
	double intersect[100000];
	int intersect_segment[100000];
	double minX;
	int minX_of_maxY, prev, test;
	int count = 0, count_1 = 0;

	scanf("%d %d", &maxY, &minY);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		scanf("%d %d", &upperX[i], &lowX[i]);
		slope[i] = (double)(upperX[i] - lowX[i]) / (maxY - minY);
	}
	scanf("%d", &m);
	for (i = 0; i < m; ++i)
		scanf("%lf", &query[i]);


	for (j = 0; j < n; ++j)
		intersect[j] = ((query[0]-maxY)*(upperX[j]- lowX[j])/(maxY-minY)) +upperX[j];
	minX = FindMin_double(intersect, n);
	for (j = 0; j < n; ++j)
	{
		if (intersect[j] == minX)
		{
			sub_upperX[count] = j+1;
			count++;
		}
	}
	if (count == 1){
		printf("%d\n", sub_upperX[0]);
		prev = sub_upperX[0];
	}
	else{
		minX_of_maxY = FindMin_int(upperX, sub_upperX, count);
		for (j = 0; j < count; ++j)
		{
			if (minX_of_maxY == upperX[sub_upperX[j]-1]){
				printf("%d\n", sub_upperX[j]);
				prev = sub_upperX[j];
				break;
			}
		}
	}
	count = 0;



	for (i = 1; i < m; ++i) 
	{
		for (j = 0; j < n; ++j)
			if (((query[i]>query[i-1])&&((slope[j]<=0)||(slope[j]<slope[prev-1]))) || ((query[i]<query[i-1])&&((slope[j]>=0)||(slope[j]>slope[prev-1]))) || (prev == j+1)){
				intersect[count_1]=((query[i]-maxY)*(upperX[j]-lowX[j])/(maxY-minY)) +upperX[j];
				intersect_segment[count_1] = j+1;
				//printf("%d %d %lf\n", i, intersect_segment[count_1], intersect[count_1]);
				count_1++;
			}
		minX = FindMin_double(intersect, count_1);
		for (j = 0; j < count_1; ++j)
		{
			if (intersect[j] == minX)
			{
				sub_upperX[count] = intersect_segment[j];
				count++;
			}
		}

		if (count == 1){
			printf("%d\n", sub_upperX[0]);
			prev = sub_upperX[0];
		}
		else
		{
			minX_of_maxY = FindMin_int(upperX, sub_upperX, count);
			for (j=0; j<count; j++)
			{
				if (minX_of_maxY == upperX[sub_upperX[j]-1])
				{
					printf("%d\n", sub_upperX[j]);
					prev = sub_upperX[j];
					break;
				}
			}
		}
		count = 0;
		count_1 = 0;
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

