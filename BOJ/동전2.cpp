#include<iostream>
#define min(a,b) ((a)<(b))?a:b
using namespace std;
int main()
{
	int n, k;
	int in[101] = { 0 };
	int D[10001] = { 0 };
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++)
		D[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &in[i]);
		for (int j = in[i]; j <= k; j++)
		{
			if (D[j - in[i]] != -1)
			{
				if (D[j] != -1)
					D[j] = min(D[j - in[i]] + 1, D[j]);
				else
					D[j] = D[j - in[i]] + 1;
			}
		}
	}
	cout << D[k] << '\n';
}