/* The 42th Annual ACM
 * International Collegiate Programming Contest
 * Asia Regional - Daejeon
 * Problem F */

#include <stdio.h>


int main(void)
{
	int minY, maxY;
	int n, m, i, j;
	int num_test, temp;
	int upperX[100000];
	int lowX[100000];
	int left_seg[100000];  // leftmost segment between intersect_y[i] and intersect_y[i+1]
 	int leftmost;  // the number of segment
 	int x_leftmost = 500000;
 	int leftmost_temp;
	int leftmost_hlower;  // the number of segment for h_lower
	int x_leftmost_hlower = 500000;
	int idx = 0;   // variable for index of left_seg and intersect_y
	int a;
	double query;
	double y_max;  // maximum y value for specific query
	double y_temp;
	double intersect_y[100000];


	scanf("%d %d", &maxY, &minY);
	scanf("%d", &n);
	num_test = n;
	for (i = 0; i < n; ++i){
		scanf("%d %d", &upperX[i], &lowX[i]);
		if (upperX[i] < x_leftmost){
			leftmost = i+1;
			x_leftmost = upperX[i];
		}
		if (lowX[i] < x_leftmost_hlower){
			leftmost_hlower = i+1;
			x_leftmost_hlower = lowX[i];
		}
	}

	// printf("leftmost at h_lower: %d \n", leftmost_hlower);
	// printf("leftmost at h_upper: %d \n", leftmost);

	intersect_y[0] = maxY;
	left_seg[0] = leftmost;
	idx = 1;

	while (leftmost != leftmost_hlower){
		y_max = minY;
		for (i=0; i<n; i++){
			a = upperX[leftmost-1]-lowX[leftmost-1]-upperX[i]+lowX[i];
			if (a != 0){
				y_temp = (double)(maxY*(lowX[i]-lowX[leftmost-1])+(upperX[leftmost-1]-upperX[i])*minY)/ (double)a;
				if ((y_temp > y_max) && (y_temp < (double)maxY)){
					y_max = y_temp;
					leftmost_temp = i+1;
					printf("%d %d\n", i+1, leftmost_temp);
				}
			}
		}

		leftmost = leftmost_temp;
		left_seg[idx] = leftmost;
		intersect_y[idx] = y_max;
		idx++;
		num_test--;
		printf("%d\n", leftmost);
	}


	for (i=0; i<m; i++){
		scanf("%lf", &query);
		for (j=0; j<idx; j++){
			if ((intersect_y[i] >= query) && (intersect_y[i+1] < query))
			{
				idx = i;
				break;
			}
		}
		printf("%d", left_seg[i]);
	}


	return 0;
}
