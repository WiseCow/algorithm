#include<iostream>
#include<queue>
using namespace std;
int main()
{

	int tc;
	scanf("%d",&tc);

	priority_queue<int> s;
	for (int i = 0; i < tc; i++)
	{
		int a;
		scanf("%d", &a);


		if (a == 0)
		{
			if (s.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n",-s.top());
				s.pop();
			}
		}
		else
		{
			s.push(-a);
		}
	}
}