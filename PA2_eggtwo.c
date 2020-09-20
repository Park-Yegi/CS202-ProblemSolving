/* 
 * Ji-hoon has two specially made eggs. 
 * Suppose the strength of both eggs is the same. 
 * Ji-hoon dropped two eggs in an N-story building and wanted to know the intensity of the eggs. 
 * When you drop an egg from an N-story building to find the strength of an egg, 
 * the strength of the egg can be divided into N+1 sections. 
 * (First broken when dropped from the first floor 
 * / First broken when dropped from the second floor 
 * / ... 
 * / First break when dropping from floor N 
 * / Because it can be divided into the first break when falling from floor N.) 
 * When we used the method of making the egg drop the smallest in the worst case, 
 * we wondered how many times we should drop eggs in the worst case.
 */


#include <stdio.h>
#include <math.h>

int main(void){
	double floor;
	long x;
	scanf("%lf", &floor);
	
	x= (long)(ceil((-1.0+sqrt(8.0*floor+1.0))/2.0));

	printf("%ld \n", x);
	return 0;
}
