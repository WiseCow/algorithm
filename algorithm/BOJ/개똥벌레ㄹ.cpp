#include<iostream>
#include<queue>
using namespace std;
int u[500001] = { 0 };
int d[500001] = { 0 };

int main()
{
	int N, H;
	scanf("%d %d", &N, &H);
	int a, b;
	for (int i = 0; i < N / 2; i++)
	{
		scanf("%d %d", &a, &b);
		d[a]++;
		u[b]++;
	}


	for (int i = H; i > 0; i--)
	{
		d[i - 1] += d[i];
		u[i - 1] += u[i];
	}

	priority_queue<int> q;
	for (a = 1; a <= H; a++)
		q.push(-(d[a] + u[H - a + 1]));
	int minn = -q.top();

	int cnt=0;
	while (-q.top() == minn)
	{
		cnt++;
		q.pop();
	}

	printf("%d %d", minn, cnt);

	return 0;
}