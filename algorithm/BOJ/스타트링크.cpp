#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int F, S, G, U, D;
queue<pair<int, int>> q;
int arr[1000001];
int bfs()
{

	int c = 987654321;
	while (q.size())
	{
		int a = q.front().first, b = q.front().second;
		q.pop();

		if (a + U <= F && arr[a + U] > b + 1)
		{
			arr[a + U] = b + 1;
			q.push({ a + U,b + 1 });
		}
		if (a - D >= 1 && arr[a - D] > b + 1)
		{
			arr[a - D] = b + 1;
			q.push({ a - D,b + 1 });
		}
	
		if (a == G)
		{
			c = b;
			break;
		}
	}
	return c;
}
int main()
{
	scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
	q.push({ S, 0 });
	memset(arr, 0x7f, sizeof(arr));
	int k = bfs();
	if (k < 987654321)
		printf("%d", k);
	else
		printf("use the stairs");
}