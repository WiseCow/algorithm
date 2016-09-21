#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int tc;
	scanf("%d", &tc);

	vector<int> pl, mi;
	int zero = 0, one = 0;


	for (int i = 0; i < tc; i++)
	{
		int a;
		scanf("%d", &a);

		if (a == 1)
			one++;
		else if (a > 0)
			pl.push_back(a);
		else if (a < 0)
			mi.push_back(a);
		else
			zero++;
	}

	sort(pl.begin(), pl.end());
	reverse(pl.begin(), pl.end());
	sort(mi.begin(), mi.end());


	if (pl.size() % 2 == 1)
		pl.push_back(1);

	if (mi.size() % 2 == 1)
	{
		mi.push_back(zero>0 ? 0 : 1);
	}

	int sum = one;

	for (int i = 0; i < pl.size(); i += 2)
	{
		sum += pl[i] * pl[i + 1];
	}
	for (int i = 0; i < mi.size(); i += 2)
	{
		sum += mi[i] * mi[i + 1];
	}



	cout << sum << '\n';




}