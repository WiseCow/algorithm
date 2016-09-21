#include<iostream>
#define min(a,b) ((a)>(b))?b:a
using namespace std;
int tc;
int visit[100001];

int main()
{
	scanf("%d", &tc);

	visit[1] = 1;
	for (int i = 2; i <= tc; i++)
	{
		if (visit[i] == 0)
			visit[i] = visit[i - 1] + 1;
		for (int j = 1; i-j*j >= 0; j++)
		{
			visit[i] = min(visit[i], visit[i - j*j]+1);
		}
	}

	cout << visit[tc]<<'\n';
}