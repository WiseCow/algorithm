#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector <pair<int, int>> input;
int N, S,t1,t2,D[300000];
int sol(int idx)
{
	if (idx == N)
		return 0;
	int &ret = D[idx];
	if (ret != -1)return ret;
	ret = sol(idx + 1);
	int le=idx, ri=N-1, mid, nidx=N;
	while (ri >= le)
	{
		mid = (le + ri )/ 2;
		if (input[mid].first >= input[idx].first + S)
		{
			nidx = mid;
			ri = mid - 1;
		}
		else
			le = mid + 1;
	}
	ret = max(ret, sol(nidx) + input[idx].second);
	return ret;
}
int main()
{
	memset(D, -1, sizeof(D));
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &t1, &t2);
		input.push_back({ t1,t2 });
	}
	sort(input.begin(), input.end());
	printf("%d", sol(0));
	return 0;
}