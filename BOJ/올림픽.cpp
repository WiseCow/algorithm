#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct cont
{
	int num, gold, silver, bronze;
};
int N, K;
vector <cont> vec;

bool cmp(const cont &a, const cont &b)
{
	if (a.gold > b.gold)
	{
		return 1;
	}
	else if (a.gold == b.gold)
	{
		if (a.silver > b.silver)
		{
			return 1;
		}
		else if (a.silver == b.silver)
		{
			if (a.bronze > b.bronze)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		vec.push_back({ a, b, c, d });
	}
	sort(vec.begin(), vec.end(), cmp);
	int cnt = 1,ncnt=1;
	int g = vec[0].gold;
	int s = vec[0].silver;
	int b = vec[0].bronze;
	if (vec[0].num == K)
	{
		printf("1");
		return 0;
	}
	for (int i = 1; i < N; i++)
	{
		cnt++;
		if (vec[i].gold == g&&vec[i].silver == s&&vec[i].bronze == b)
		{

		}
		else
		{
			ncnt = cnt;
		}
		 g = vec[i].gold;
		 s = vec[i].silver;
		 b = vec[i].bronze;

		if (vec[i].num == K)
		{
			printf("%d", ncnt);
			return 0;
		}
		
	}


}