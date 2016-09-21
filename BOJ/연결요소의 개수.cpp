#include<iostream>
using namespace std;
int arr[1001];

int find(int a)
 {
	if (a == arr[a])
		return a;
	else
	{
		int b = find(arr[a]);
		arr[a] = b;
		return b;
	}
}



void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	arr[b] = a;
	
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}
	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		uni(a, b);
	}
	bool visit[1001] = { 0 };
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		arr[i] = find(i);
		if (!visit[arr[i]])
		{
			cnt++;
			visit[arr[i]] = 1;
		}
	}

	printf("%d", cnt);



}