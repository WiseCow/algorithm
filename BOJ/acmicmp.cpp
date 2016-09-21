#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int score, team,ac;
	node(int a, int b,int c){
		ac = c;
		score = a;
		team = b;
	}

	bool operator<(const node &other)const
	{

		if (ac < other.ac)
			return 1;
		else if (ac == other.ac)
		{
			if (score > other.score)
				return 1;
			else if (score == other.score)
			{
				return (team > other.team);
			}
			else
				return 0;
		}
		else
			return 0;
	}
};
int main()
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);

	int totalscore[101] = { 0 };
	int wac[101][16] = { 0 };
	int acc[101] = { 0 };
	bool ac[101][16] = { 0 };

	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		char d[4];
		scanf("%d %d %d %s", &a, &b, &c, &d);

		if (ac[b][c] == 1)
			continue;
		else
		{
			if (d[0] == 'A')
			{
				ac[b][c] = 1;
				totalscore[b] += wac[b][c] * 20 + a;
				acc[b]++;
			}
			else
			{
				wac[b][c]++;
			}
		}
	}
	priority_queue<node> qq;
	for (int i = 1; i <= n; i++)
		qq.push(node(totalscore[i], i,acc[i]));

	while (qq.size())
	{
		printf("%d %d %d\n", qq.top().team, qq.top().ac, qq.top().score);
		qq.pop();
	}

}