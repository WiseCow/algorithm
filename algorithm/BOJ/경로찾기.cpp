#include<cstdio>
#include<cstring>
#define inf 987654321
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	int map[101][101] = { 0 };

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				map[i][j] = inf;

		}


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
			{
				if (map[j][k] > map[j][i] + map[i][k])
					map[j][k] = map[j][i] + map[i][k];
			}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			if (map[i][j] == inf)
				printf("0 ");
			else
				printf("1 ");

		printf("\n");
	}


}