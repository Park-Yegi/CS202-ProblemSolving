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
int count_conti(int n, int size[6], int state[6]);

int main(void){
	int n, j;
	int size[6];
	char direction[6];
	int state[6];
	int num_flip;
	scanf("%d", &n);

	for (i=0; i<n; i++){
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


int count_flip(n, int size[6], int state[6]){
	int i;
	int now_conti = count_conti(n, size, state);
	int max_conti = now_conti;
	int max_conti_flip = 0;
	int temp_conti;

	if (now_conti == n)
		return 0;

	for (i=1; i<=n; i++){
		flip(i, size, state);
		temp_conti = count_conti(n, size, state);
		if (temp_conti > max_conti)
			max_conti_flip = i
		flip(i, size, state);
	}

	if (max_conti_flip == 0){
	
	}
	flip(max_conti_flip, size, state);
	return 1 + count_flip(n, size, state);
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
	if (j%2 == 1)
		state[j/2] = !(state[j/2]);
}


int count_conti(int n, int size[6], int state[6]){
	int i;
	int conti = 0;
	for (i=0; i<n-1; i++){
		if ((size[i+1]==size[i]+1 || size[i+1]==size[i]-1) && (state[i+1]==state[i]))
			conti += 1;
	}
	if (size[n-1]==n && state[n-1]==0)
		conti += 1;
	return conti;
}

