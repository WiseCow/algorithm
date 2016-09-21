#include<cstdio>
bool cmap[21][21];
int map[21][21];
bool chk;
int N;
int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				if (map[j][k] > map[j][i] + map[i][k])
					chk = 1;
	if (!chk){
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= N; k++)
					if (i != j&&i != k&&map[j][k] == map[j][i] + map[i][k])
						cmap[j][k] = 1;
		int sum = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j < i; j++)
				if (!cmap[i][j]&&i!=j)
					sum += map[i][j];
		printf("%d", sum);
	}
	else
		printf("-1");
}