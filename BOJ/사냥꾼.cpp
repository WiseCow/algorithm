#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int M, N, L;
vector<int> sa;
vector<pair<int, int>> ani;

int main()
{
	scanf("%d%d%d", &M, &N, &L);
	sa.resize(M);
	for (int i = 0; i < M; i++)scanf("%d", &sa[i]);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (b <= L)
			ani.push_back({ a,b });
	}
	sort(sa.begin(), sa.end());
	int res = 0;
	for (int i = 0; i < ani.size(); i++)
	{
		int x = ani[i].first, y = ani[i].second;
		int mini = x - (L - y), maxi = x + (L - y);
		int le = 0, ri = sa.size() - 1, mid;
		while (le <= ri)
		{
			mid = (le + ri) / 2;
			if (sa[mid]<mini)
			{
				le = mid + 1;
			}
			else if (sa[mid]>maxi)
			{
				ri = mid - 1;
			}
			else
			{
				res++;
				break;
			}
		}
	}
	printf("%d", res);
}