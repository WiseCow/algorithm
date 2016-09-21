#include<iostream>
#include<queue>
using namespace std;
queue<int> wait;
int arr[100001], N, cnt, endd[100001];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		wait.push(i);
	}
	while (wait.size())
	{
		cnt++;
		int now = wait.front();
		wait.pop();
		arr[now]--;
		if (arr[now])
			wait.push(now);
		else
			endd[now] = cnt;
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", endd[i]);
}