#include<cstdio>
int N, input[1000], size;
long long cnt = 0;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
	}
	scanf("%d", &size);
	for (int i = 0; i < N; i++)
	{
		cnt += input[i] / size;
		if (input[i] % size)
		{
			cnt++;
		}
	}
	printf("%d", (long long)size*cnt);
}