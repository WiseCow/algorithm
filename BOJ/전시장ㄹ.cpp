#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> vc;
int  N, S,D[300000];
int sol(int now)
{
	if (now == N)
		return 0;
	int &ret = D[now];
	if (ret != -1)return ret;
	ret = sol(now + 1);
	int k = N;
	for (int i = now + 1; i < N; i++)
		if (vc[now].first + S <= vc[i].first)
		{
			k = i;
			break;
		}

	ret = max(ret, vc[now].second + sol(k));

	return ret;
}
int main()
{
	scanf("%d%d", &N, &S);
	vc.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &vc[i].first, &vc[i].second);
	sort(vc.begin(), vc.end());
	memset(D, -1, sizeof(D));
	printf("%d", sol(0));
}