#include<iostream>
using namespace std;
int n, k;
int in[101];
int sum[10001];
int main()
{
	scanf("%d %d", &n, &k);

	sum[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &in[i]);
		for (int j = in[i]; j <= k; j++)
			sum[j] += sum[j - in[i]];
	}
	cout << sum[k] << '\n';
}