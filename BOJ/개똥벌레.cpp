#include<iostream>
#include<queue>
int u[500001], d[500001];
int main()
{
	int N, H;
	scanf("%d %d", &N, &H);

	for (int i = 0; i < N / 2; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		d[a]++;
		u[b]++;
	}
	for (int i = H; i > 1; i--)
		d[i - 1] += d[i];
	for (int i = H; i >1; i--)
		u[i-1] += u[i];
	std::priority_queue<int> v;
	for (int i = 1; i <= H; i++)
		v.push(-(u[i] + d[H-i+1]));

	int top = -v.top();
	int cnt = 0;
	while (v.size())
	{
		if (-v.top() == top)
			cnt++;
		v.pop();
	}

	printf("%d %d",top,cnt);



	return 0;
}

