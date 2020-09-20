/* The 42th Annual ACM
 * International Collegiate Programming Contest
 * Asia Regional - Daejeon
 * Problem C */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int W, S_count, L_count, B_count, node;
	int i, j, len, back, front;
	int stack_idx = 0;
	char s;
	char stack[70000];
	char str[70000];

	scanf("%d", &W);
	scanf(" %[^\n]", str);

	len = strlen(str);
	for (i=0; i<len; i++)
	{
		s = str[i];

		if ((s != 'S') && (s != 'L') && (s != 'B') && (s != '(') && (s != ')') && (s != '[') && (s != ']') && (s != ' ') && (s != ',')){
			printf("-1\n");
			return 0;
		}

		if (s == ','){
			if (i == 0){
				printf("-1\n");
				return 0;
			}
			if (i == len-1){
				printf("-1\n");
				return 0;
			}
			for (j = i-1; j>=0; j--){
				if ((str[j] == 'S') || (str[j] == ')') || (str[j] == ']')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			for (j = i+1; j<len; j++){
				if ((str[j] == 'S') || (str[j] == 'B' || str[j] == 'L')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
		}
		else if (s == 'L'){
			if (i == len-1){
				printf("-1\n");
				return 0;
			}
			L_count++;
			if (i != 0){
				for (j = i-1; j>=0; j--){
					if ((str[j] == '(') || (str[j] == '[') || (str[j] == ',')){
						break;
					}
					else if (str[j] == ' '){
						continue;
					}
					else{
						printf("-1\n");
						return 0;
					}
				}
			}
			for (j = i+1; j<len; j++){
				if ((str[j] == '(') || (str[j] == '[')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
		}
		else if (s == 'B'){
			if (i == len-1){
				printf("-1\n");
				return 0;
			}
			B_count++;
			if (i != 0){
				for (j = i-1; j>=0; j--){
					if ((str[j] == '(') || (str[j] == '[') || (str[j] == ',')){
						break;
					}
					else if (str[j] == ' '){
						continue;
					}
					else{
						printf("-1\n");
						return 0;
					}
				}
			}
			for (j = i+1; j<len; j++){
				if ((str[j] == '(') || (str[j] == '[')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
		}
		else if (s == 'S'){
			S_count++;
			if (i != 0){
				for (j = i-1; j>=0; j--){
					if ((str[j] == '(') || (str[j] == '[') || (str[j] == ',')){
						break;
					}
					else if (str[j] == ' '){
						continue;
					}
					else{
						printf("-1\n");
						return 0;
					}
				}
			}
			for (j = i+1; j<len; j++){
				if (i == len-1)
					break;
				if ((str[j] == ',') || (str[j] == ')') || (str[j] == ']')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
		}
		else if (s == '('){
			if (i == 0){
				printf("-1\n");
				return 0;
			}
			for (j = i-1; j>=0; j--){
				if ((str[j] == 'B') || (str[j] == 'L')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			for (j = i+1; j<len; j++){
				if ((str[j] == 'S') || (str[j] == 'L') || (str[j] == 'B')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			stack[stack_idx] = '(';
			stack_idx++;
		}
		else if (s == '['){
			if (i == 0){
				printf("-1\n");
				return 0;
			}
			for (j = i-1; j>=0; j--){
				if ((str[j] == 'B') || (str[j] == 'L')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			for (j = i+1; j<len; j++){
				if ((str[j] == 'S') || (str[j] == 'L') || (str[j] == 'B')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			stack[stack_idx] = '[';
			stack_idx++;
		}
		else if (s == ')'){
			if (i == 0){
				printf("-1\n");
				return 0;
			}
			for (j = i-1; j>=0; j--){
				if ((str[j] == 'S') || (str[j] == ')') || (str[j] == ']')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			for (j = i+1; j<len; j++){
				if (i == len-1)
					break;
				if ((str[j] == ',') || (str[j] == ')') || (str[j] == ']')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			if (stack[stack_idx-1] != '('){
				printf("-1\n");
				return 0;
			}
			else
				stack_idx--;
		}
		else if (s == ']'){
			if (i == 0){
				printf("-1\n");
				return 0;
			}
			for (j = i-1; j>=0; j--){
				if ((str[j] == 'S') || (str[j] == ')') || (str[j] == ']')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			for (j = i+1; j<len; j++){
				if (i == len-1)
					break;
				if ((str[j] == ',') || (str[j] == ')') || (str[j] == ']')){
					break;
				}
				else if (str[j] == ' '){
					continue;
				}
				else{
					printf("-1\n");
					return 0;
				}
			}
			if (stack[stack_idx-1] != '['){
				printf("-1\n");
				return 0;
			}
			else
				stack_idx--;
		}
	}


	if (stack_idx != 0){
		printf("-1\n");
		return 0;
	}

	back = L_count;
	node = (2*L_count)+(2*B_count)+S_count;
	front = B_count+(node-1);

	printf("%d\n", (front+(back*W)-node+2));

	return 0;
}