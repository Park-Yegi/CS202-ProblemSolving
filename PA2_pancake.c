/* 
 * Jihun made N (1 ≤ N ≤ 6) pancakes of different sizes. 
 * The pancake has a garnish on the front, so this pancake is front and back separated. 
 * The size of these N pancakes is 1, 2, ... , and N in order of size. 
 * Because Ji-hoon made pancakes without thinking, he stacked them in reverse order of the pancakes, and the order of the pancakes might not be the order of the size of the pancakes. 
 * Ji-hoon wants to make pancakes smaller as they go up, and all of them pile up in the right direction through at least a few turns. 
 */

#include <stdio.h>
int count_flip(int n, int size[6], int state[6]);
void flip(int j, int size[6], int state[6]);
int test(int n, int size[6], int state[6]);

int main(void){
	int n, i;
	int size[6];
	char direction[6];
	int state[6];
	int num_flip;
	scanf("%d", &n);

	for (i=0; i<n ; i++){
		scanf("%d %c", &size[i], &direction[i]);
		if (direction[i] == '+')
			state[i] = 0; //pancake is + state
		else
			state[i] = 1; //pancake is - state
	}
	
	num_flip = count_flip(n, size, state);
	printf("%d \n", num_flip);
	return 0;
}


int count_flip(int n, int size[6], int state[6]){
	int i;
	int not_sorted_index = test(n, size, state);
	int not_sorted =not_sorted_index+1;
	int max_index;
	int range_change = 0;
	int index_zero = size[0];
	
	if (not_sorted_index == -1)
		return 0;
	
	if (index_zero != not_sorted && state[0] == 1){
		for (i=1; i<not_sorted_index; i++){
			if (size[i]==index_zero+1 && state[i]==0){
				flip(i, size, state);
				return 1 + count_flip(n, size, state);
			}
			if (size[i] != size[i-1]-1 || size[i] == 0)
				break;
		}
	}

	if (size[0] == not_sorted){
		if (state[0] == 0){
			flip(1, size, state);
			flip(not_sorted, size, state);
			return 2 + count_flip(n, size, state);
		}
		else{
			flip(not_sorted+range_change, size, state);
			return 1 + count_flip(n, size, state);
		}
	}
	else{
		for (i=0; i<not_sorted; i++){
			if (size[i]==not_sorted){
				max_index = i;
				break;
			}
		}

		if (state[max_index] == 0){
			flip(max_index+1, size, state);
			flip(not_sorted, size, state);
			return 2 + count_flip(n, size, state);
		}
		else{
			for(i= max_index+1; i<n ; i++){
				if (size[i]==not_sorted-i+max_index && state[i]==1)
					range_change += 1;
				else
					break;
			}
			if (range_change !=0){
				flip(max_index+1+range_change, size, state);
				range_change = 0;
				return 1 +count_flip(n, size, state);
			}
			else{
				flip(max_index+1, size, state);
				flip(1, size, state);
				flip(not_sorted, size, state);
				return 3 + count_flip(n, size, state);
			}	
		}
	}
}


void flip(int j, int size[6], int state[6]){
	int i;
	for (i=0; i<j/2; i++){
		int temp;
		temp = size[i];
		size[i] = size[j-i-1];
		size[j-i-1] = temp;
		temp = state[i];
		state[i] = !(state[j-i-1]);
		state[j-i-1] = !temp;
	}
	if (j%2 ==1)
		state[j/2] = !(state[j/2]);
}


int test(int n, int size[6], int state[6]){
	int i;
	int sorted = 0;
	for (i=0; i<n; i++){
		if (size[n-i-1]==n-i && state[n-i-1]==0)
			sorted += 1;
		else
			break;
	}
	return n-sorted-1;  //max(index of not sorted pancake) 
	                    // -1 if sorting is finished
}

