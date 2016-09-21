#include<cstdio>
bool chk[200] = { 0 };
int arr[41];
int input[41];
int main()
{
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i < 41; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
		scanf("%d", &input[i]);
	int ans = 1;
	int prev = 0;
	for (int i = 1; i <= M; i++)
	{
		ans *= arr[input[i] - prev - 1];
		prev = input[i];
	}
	ans *= arr[N - prev];
	printf("%d", ans);
	return 0;
}