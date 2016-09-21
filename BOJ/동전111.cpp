#include<cstdio>
int n, k,in[101], D[10001];
int main()
{
	scanf("%d%d", &n, &k);
	D[0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
		for (int j = in[i]; j <= k; j++)
			D[j] += D[j - in[i]];
	}
	printf("%d", D[k]);
}




