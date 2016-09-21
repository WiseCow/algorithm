#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int U[101];
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first > b.first)
		return 0;
	else
	{
		if (a.first == b.first)
		{
			if (a.second > b.second)
				return 0;
			else
				return 1;
		}
		else
			return 1;
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> in;
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		in.push_back({ a,b });
	}
	sort(in.begin(), in.end(), cmp);
	U[0] = 1;
	for (int i = 1; i < in.size(); i++)
	{
		int a = 0;
		for (int k = i - 1; k >= 0; k--)
		{
			if (in[k].first<in[i].first&&in[k].second<in[i].second&&U[k]>a)
				a = U[k];
		}
		U[i] = a + 1;
	}
	int i = 0;
	for (int k = 0; k < N; k++)
		if (U[k] > i)
			i = U[k];
	printf("%d", N - i);
	return 0;
}