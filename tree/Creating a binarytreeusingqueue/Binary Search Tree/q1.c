#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define R 10
#define C 10

int checkSafe(int A[][C], int r, int c, bool v[][C])
{
	return (r >= 0) && (r < R) && (c >= 0) && (c < C) && (A[r][c] && !v[r][c]);
}

void DFS(int A[][C], int r, int c, bool v[][C])
{
	static int rNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int cNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	v[r][c] = true;
	for (int i = 0; i < 8; ++i)
		if (checkSafe(A, r + rNbr[i], c + cNbr[i], v))
			DFS(A, r + rNbr[i], c + cNbr[i], v);
}

int count(int A[][C])
{
	bool v[R][C];
	memset(v, 0, sizeof(v));
	int cnt = 0;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if (A[i][j] && !v[i][j]) 
			{ 
				DFS(A, i, j, v); 
				++cnt;
			}
	return cnt;
}

int main()
{
	int A[R][C],i,j;
	for(i=0;i<R;i++)
	    for(j=0;j<C;j++)
	        scanf("%d" ,&A[i][j]);
	printf("%d\n", count(A));
	return 0;
}