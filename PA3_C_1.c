/* The 42th Annual ACM
 * International Collegiate Programming Contest
 * Asia Regional - Daejeon
 * Problem C */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int S_count = 0, L_count = 0, B_count = 0, node = 0;
	int W, i, len, back, front;
	int stack_idx = 0, new_idx = 0, new_len = 0;
	char s;
	char stack[70000];
	char str[70000];
	char new[70001];

	scanf("%d", &W);
	scanf(" %[^\n]", str);

	len = strlen(str);
	for (i=0; i<len; i++){
		if (str[i] != ' '){
			new[new_idx] = str[i];
			new_idx++;
			new_len++;
		}
	}
	
	for (i = 0; i < new_len; ++i)
	{
		s = new[i];

		if ((s != 'S') && (s != 'L') && (s != 'B') && (s != '(') && (s != ')') && (s != '[') && (s != ']') && (s != ' ') && (s != ',')){
			printf("-1\n");
			return 0;
		}

		if (s == ','){
			if ((new[i-1] != 'S') && (new[i-1] !=')') && (new[i-1] != ']')){  // before comma, S or ),]
				printf("-1\n");
				return 0;
			}
			if ((new[i+1] != 'S') && (new[i+1] != 'L') && (new[i+1] != 'B')){  // after comma, node
				printf("-1\n");
				return 0;
			}
		}
		else if (s == 'L'){
			L_count++;
			node += 2;
			if ((new[i+1] != '(') && (new[i+1] != '[')){   // after L, open parentheses
				printf("-1\n");
				return 0;
			}
			if (i != 0){
				if ((new[i-1] != ',') && (new[i-1] != '(') && (new[i-1] != '[')){   // before L, comma or open parentheses
					printf("-1\n");
					return 0;
				}
			}
		}
		else if (s == 'B'){
			B_count++;
			node += 2;
			if ((new[i+1] != '(') && (new[i+1] != '[')){ // after B, open parentheses
				printf("-1\n");
				return 0;
			}
			if (i != 0){
				if ((new[i-1] != ',') && (new[i-1] != '(') && (new[i-1] != '[')){ // before L, comma or open parentheses
					printf("-1\n");
					return 0;
				}
			}
		}
		else if (s == 'S'){
			S_count++;
			node++;
			if (i != new_len-1){
				if ((new[i+1] != ',') && (new[i+1] != ')') && (new[i+1] != ']')){  // after S, comma or closed parentheses
					printf("-1\n");
					return 0;
				}
			}
			if (i != 0){
				if ((new[i-1] != ',') && (new[i-1] != '(') && (new[i-1] != '[')){  // before S, comman or open parentheses
					printf("-1\n");
					return 0;
				}
			}
		}
		else if (s == '('){
			stack[stack_idx] = '(';
			stack_idx++;

			if ((new[i+1] != 'B') && (new[i+1] != 'L') && (new[i+1] != 'S')){    // after open parentheses, node
				printf("-1\n");
				return 0;
			}
			if ((new[i-1] != 'L') && (new[i-1] != 'B')){    // before open parentheses, L or B
				printf("-1\n");
				return 0;
			}
		}
		else if (s == '['){
			stack[stack_idx] = '[';
			stack_idx++;

			if ((new[i+1] != 'B') && (new[i+1] != 'L') && (new[i+1] != 'S')){
				printf("-1\n");
				return 0;
			}
			if ((new[i-1] != 'L') && (new[i-1] != 'B')){
				printf("-1\n");
				return 0;
			}
		}
		else if (s == ')'){
			if (stack[stack_idx-1] != '('){
				printf("-1\n");
				return 0;
			}
			else
				stack_idx--;

			if ((new[i-1] != ']') && (new[i-1] != ')') && (new[i-1] != 'S')){     // before closed parentheses, ] ) S
				printf("-1\n");
				return 0;
			}
			if (i != new_len-1){
				if ((new[i+1] != ']') && (new[i+1] != ')') && (new[i+1] != ',')){     // after closed parentheses, ] ) ,
					printf("-1\n");
					return 0;
				}
			}
		}
		else if (s == ']'){
			if (stack[stack_idx-1] != '['){
				printf("-1\n");
				return 0;
			}
			else
				stack_idx--;

			if ((new[i-1] != ']') && (new[i-1] != ')') && (new[i-1] != 'S')){
				printf("-1\n");
				return 0;
			}
			if (i != new_len-1){
				if ((new[i+1] != ']') && (new[i+1] != ')') && (new[i+1] != ',')){
					printf("-1\n");
					return 0;
				}
			}
		}
	}

	if (stack_idx != 0){
		printf("-1\n");
		return 0;
	}

	//printf("%d %d %d %d\n", S_count, B_count, L_count, node);

	back = L_count;
	front = B_count + (node-1);

	printf("%d\n", (front+(back*W)-node+2));

	return 0;
}
