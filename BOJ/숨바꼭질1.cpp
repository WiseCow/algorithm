#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, K;
queue<pair<int,int>> q;
int arr[100001];
int bfs()
{

	int c = 0;
	while (q.size())
	{
		int a = q.front().first, b = q.front().second;
		q.pop();

		if (a + 1 <= 100000 && arr[a + 1] > b+1)
		{
			arr[a + 1] = b+1;
			q.push({ a + 1,b + 1 });
		}
		if (a - 1 >= 0 && arr[a - 1] > b+1)
		{
			arr[a - 1] = b+1;
			q.push({ a - 1,b + 1 });
		}
		if (a *2 <= 100000 && arr[a * 2] > b+1)
		{
			arr[a * 2] = b + 1;
			q.push({ a * 2,b + 1 });
		}
		if (a == K)
		{
			c = b;
			break;
		}
	}
	return c;
}
int main()
{
	scanf("%d %d", &N, &K);
	q.push({ N, 0});
	memset(arr, 0x7f, sizeof(arr));
	printf("%d", bfs());
}