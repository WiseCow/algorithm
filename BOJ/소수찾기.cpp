#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool chk[1001];
int main()
{
	int tc;

	scanf("%d", &tc);
	vector<int> ve;
	for (int i = 0; i < tc; i++)
	{
		int a;
		scanf("%d", &a);

		ve.push_back(a);
	}

	sort(ve.begin(), ve.end());

	chk[1] = 1;
	chk[2] = 0;
	for (int i = 2; i <= ve[tc - 1]; i++)
	{
		for (int j = 2; j*i <= ve[tc - 1]; j++)
			chk[i*j] = 1;
	}
	int a=0;
	for (int i = 0; i < tc; i++)
	{
		if (chk[ve[i]] == 0)
			a++;
	}

	cout << a << endl;
}