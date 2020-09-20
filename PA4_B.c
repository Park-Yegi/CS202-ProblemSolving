/* 2017 ACM ICPC Asia Regional - Daejeon
 * Problem B */

#include <stdio.h>
#define ALL 43046721
#define TONUM(Y, X) ((((Y)-1)*4)+((X)-1))

int Table[16] = {1, };
int X, a, b, ans;
char visit[ALL], checkvisit[ALL], cache[ALL];
int dy[4] = {0, 1, 1, 1};
int dx[4] = {1, 1, 0, -1};

int check(int now){
	int i, j, k, t, x, y, cnt;
	int A[5][5] = {0, };

	if (checkvisit[now])
		return cache[now];
	for (i = 1; i <= 4; i++){
		for (j = 1; j <= 4; j++){
			int t = TONUM(i, j);
			A[i][j] = now / Table[t] % 3;
		}
	}


	for (i = 1; i <= 4; i++){
		for (j = 1; j <= 4; j++){
			if (A[i][j]){
				for (k = 0; k < 4; k++){
					y = i;
					x = j;
					cnt = 0;
					for (;;){
						if ((y > 4) || (x < 1) || (x > 4) || (A[i][j] != A[y][x]))
							break;
						cnt++;
						y += dy[k];
						x += dx[k];
					}
					if (cnt > 2)
						return cache[now] = A[i][j];
				}
			}
		}
	}
	return cache[now] = 0;
}


void dfs(int now, int turn){
	int i, j, t, nxt, w;
	int A[5][5] = {0, };

	if (visit[now])
		return;
	visit[now] = 1;

	for (i = 1; i <= 4; i++){
		for (j = 1; j <= 4; j++){
			t = TONUM(i, j);
			A[i][j] = now / Table[t] % 3;
		}
	}

	for (j = 1; j <= 4; j++){
		for (i = 1; i <= 4; i++){
			if (!A[i][j]){
				t = TONUM(i, j);
				nxt = now + Table[t]*turn;
				w = check(nxt);
				if (w){
					if (w==2 && i==b && j==a)
						ans++;
					break;
				}
				dfs(nxt, 3-turn);
				break;
			}
		}
	}
}

int main(void){
	int i;
	for (i = 1; i < 16; i++)
		Table[i] = Table[i-1] * 3;
	scanf("%d %d %d", &X, &b, &a);
	dfs(Table[TONUM(1,X)], 2);
	printf("%d\n", ans);
	return 0;
}