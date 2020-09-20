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
	int stack_idx = 0, new_idx = 0, new_len;
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

	printf("-1\n");

	return 0;
}