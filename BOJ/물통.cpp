#include<iostream>
#include<queue>
using namespace std;
int visit[201];
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);



	queue<int> q;
	priority_queue <int> qq;
	q.push(c);
	qq.push(-c);
	while (q.size())
	{
		int tmp = q.front();
		q.pop();
		
		if (tmp > a)
		{
			q.push(a);
			q.push(tmp - a);
			qq.push(-a);
			qq.push(-(tmp - a));
		}
		if (tmp > b)
		{
			q.push(b);
			q.push(tmp - b);
			qq.push(-(b));
			qq.push(-(tmp - b));
		}
	}

	int last = 0;
	while (qq.size())
	{
		if (-qq.top() != last)
		{
			printf("%d ", -qq.top());
			last = -qq.top();
		}
		qq.pop();
	}

	return 0;

}