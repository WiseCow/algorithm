#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
bool cmp(pair<int, int> const &a, pair<int, int>const &b)
{
	if (a.second > b.second)
		return 0;
	else if (a.second < b.second)
		return 1;
	else
	{
		if (a.first > b.first)
			return 0;
		else
			return 1;
	}
}
int main()
{

	scanf("%d", &n);
	
	vector<pair<int, int>> vec;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back(make_pair(a, b));
	}


	sort(vec.begin(), vec.end(), cmp);

	int res = 0;
	int ptr = 0;
	for (int i = 0; i < n; i++)
	{
		if (ptr <= vec[i].first)
		{
			ptr = vec[i].second;
			res++;
		}
	}

	cout << res <<'\n';
	return 0;

}