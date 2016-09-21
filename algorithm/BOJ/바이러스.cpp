#include<cstdio>
int arr[101];
int find(int a)
{
	if (a == arr[a])
		return a;
	else
		return arr[a] = find(arr[a]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	arr[b] = a;
}
int main()
{
	int C, I;
	scanf("%d", &C);
	scanf("%d", &I);

	for (int i = 0; i <= C; i++)
		arr[i] = i;
	for (int i = 0; i < I; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		uni(a, b);
	}
	int cnt = -1;
	for (int i = 1; i <= C; i++)
	{
		arr[i] = find(i);
		if (arr[i] == arr[1])
			cnt++;
	}
	printf("%d", cnt);
}