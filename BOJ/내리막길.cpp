#include<iostream>
using namespace std;
int M, N;
int in[501][501];
int D[501][501];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };


int solve(int x, int y)
{
	if (x == M && y == N)
		return 1;
	if (D[x][y])
		return D[x][y];

	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (0 < cx&&cx <= M && 0 < cy&&cy <= N)
			if (in[x][y] > in[cx][cy])
				D[x][y] += solve(cx, cy);
	}
	return D[x][y];
}


int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &in[i][j]);

	cout << solve(1, 1) << '\n';

}