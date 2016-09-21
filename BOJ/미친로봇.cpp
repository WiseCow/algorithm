#include<cstdio>
double dist[4],ret;
int dx[4] = { 0, 0, 1, -1 },dy[4] = { 1, -1, 0, 0 }, N;
bool vis[100][100];
void sol(int len, int x, int y, double per)
{
	if (len == N)return;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!vis[nx][ny])
		{
			vis[nx][ny] = 1;
			sol(len + 1, nx, ny, per*dist[i]);
			vis[nx][ny] = 0else
		}
		;
			ret += per*dist[i];
	}


}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < 4; i++)
	{
		int t;
		scanf("%d",&t);
		dist[i] = (double)t*0.01;
	}
	vis[50][50] = 1;
	sol(0, 50, 50, 1);
	printf("%.10lf", 1-ret);
}