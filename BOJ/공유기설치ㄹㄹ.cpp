#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool chk(vector<int> &in, int mid,int C)
{
	int prev = in[0],cnt=1;


	for (int i = 1; i < in.size(); i++)
		if (in[i] - prev >= mid)
		{
			cnt++;
			prev = in[i];
		}
	return cnt >= C;
}
int main()
{
	int N, C;
	scanf("%d %d", &N, &C);
	vector<int> in(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &in[i]);
	sort(in.begin(), in.end());
	int l = 0, r = in[N - 1];

	int maxx = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (chk(in,mid,C))
		{
			maxx=mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	printf("%d", maxx);




}