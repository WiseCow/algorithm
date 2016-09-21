#include<cstdio>
int map[31];
int main()
{
	int N;
	scanf("%d", &N);
	map[0] = 1;
	map[2] = 3;
	map[4] = 11;
	for (int i = 6; i <= N; i+=2)
	{
		map[i] = map[i - 2] * 3;
		for (int j = 4; i - j >=0; j+=2)
			map[i] += map[i - j] * 2;
	}
	printf("%d", map[N]);
}