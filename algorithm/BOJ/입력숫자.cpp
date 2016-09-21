#include<cstdio>
int N, map[101], idx;
bool chk;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		if (map[idx])
		{
			while (map[idx]!= 0)
			{
				idx++;
				idx %= N;
			}
		}
		map[idx] = n;
		idx += n;
		idx %= N;
	}
	printf("%d\n", N);
	for (int i = 0; i < N; i++)
		printf("%d ", map[i]);
}