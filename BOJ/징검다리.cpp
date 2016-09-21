#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000009
int N, K, L, map[50001];
long long D[50001];
int sol(int now,int prev)
{
	if (now == N)
		return 1;
	if (now > N)
		return 0;
	long long &ret = D[now];
	if (ret != -1)
		return ret; 
	ret = 0;
	for (int i = 1; i <= K; i++)
	{
		if (i != prev&&now + i <= N&&!map[now + i])
		{
			ret=(ret+sol(now + i, i))%mod;
		}
	}
	return ret;
}
int main()
{
	int tc;
	cin>>tc;
	for (int itr = 0; itr < tc; itr++)
	{
		cin>>N>>K>>L;

		memset(map, 0, sizeof(map));
		memset(D, -1, sizeof(D));
		for (int i = 0; i < L; i++)
		{
			int t;
			cin>>t;
			map[t]++;
		}
		cout<<"Case #"<<itr+1<<"\n"<<sol(0,0)<<"\n";
	}
}