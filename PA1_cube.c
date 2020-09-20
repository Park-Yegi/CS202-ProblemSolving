#include <stdio.h>
#include <math.h>

/* 
 * Output the number of kinds on the i-line 
 * that can represent Ni in the sum of two cubes. 
 */

int CubeSum(int a);

int main(void){
	int loop;
	scanf("%d", &loop);
	int input[10000];
	int result[10000];
	
	for (int i=0; i<loop; i++){
		int a;
		scanf("%d", &a);
		input[i] = a;
		result[i] = CubeSum(a);
	}
	
	for (int i=0; i<loop; i++)
		printf("%d \n", result[i]);

	return 0;

}

int CubeSum(int a){
	int count = 0;
	int x = (int)cbrt((double)a);
	double y = 1.0;
	while(1>0){
		int k = (int)(pow((double)x, 3.0)+pow(y, 3.0));
		if (k == a){
			count++;
			x = x - 1.0;
			y = y + 1.0;
		}else if (k > a){
			x = x - 1.0;
		}else{
			y = y + 1.0;
		}

		if (x < y)
			break;
	}
	return count;
}
