#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[4000], b[4000], c[4000], d[4000],cnt;
vector<int>A,B;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}
	int idx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			A.push_back(a[i] + b[j]);
			B.push_back(c[i] + d[j]);
		}
	sort(A.begin(),A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{

		}

	printf("%d", cnt);
}