#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int main()
{
	scanf("%d", &N);
	
	vector<int> a;

	for (int i = 0; i < N; i++)
	{
		int k;
		scanf("%d", &k);
		a.push_back(k);

	}
	sort(a.begin(), a.end());

	long long kk = 0;

	long long kkk = 0;
	for (int i = 0; i < N; i++)
	{
		kk += a[i];
		kkk += kk;
	}


	cout << kkk<<'\n';

}