#include<cstdio>
#include<set>
using namespace std;

int main()
{
	int N, M,ans=0;
	scanf("%d %d", &N, &M);
	set<int> s;
	for (int i = 0; i < N; i++)
	{
		int in;
		scanf("%d", &in);
		if (s.find(M - in) != s.end())
		{
			ans++;
		}
		s.insert(in);
	}
	printf("%d", ans);
}