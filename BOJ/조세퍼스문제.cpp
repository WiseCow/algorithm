#include<iostream>
#include<queue>
using namespace std;

int main()
{

	int N, M;
	scanf("%d %d", &N, &M);

	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);



	printf("<");
	int a = 0;
	while (q.size())
	{
		if (a == M-1)
		{
			printf("%d", q.front());
			q.pop();
			if (q.size())
				printf(", ");
			a = 0;
		}
		else
		{
			q.push(q.front());
			q.pop();
			a++;
		}
	}
	printf(">\n");


}