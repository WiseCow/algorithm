#include<cstdio>
#include<cstring>
#define min(a,b) ((a)>(b))?b:a
int arr[126];
int arrtmp[125];
int D[300001];

int main()
{
	int N;
	scanf("%d", &N);
	memset(D, -1, sizeof(D));
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 2; i < 126; i++)
		arr[i] = arr[i - 1] + i;

	arrtmp[1] = 1;
	for (int i = 2; i < 125; i++)
		arrtmp[i] = arrtmp[i - 1] + arr[i];
	D[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		D[i] = i;
		for (int j = 1; arrtmp[j] <= i; j++)
			D[i] = min(D[i], D[i - arrtmp[j]] + 1);
	}
	printf("%d", D[N]);
}