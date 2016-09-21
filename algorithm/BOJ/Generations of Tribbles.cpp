#include<cstdio>
#include<cstring>
long long D[100];
long long sol(int i)
{
	
	if (i < 2)
		return 1;
	else if (i == 2)
		return 2;
	else if (i == 3)
		return 4;

	long long &ret = D[i];

	if (ret!=-1)
		return ret;

	ret = sol(i - 1) + sol(i - 2) + sol(i - 3) + sol(i - 4);
	return ret;
}
int main()
{
	int n;
	scanf("%d ", &n);
	memset(D, -1, sizeof(D));
	D[0] = 1;
	D[1] = 1;
	D[2] = 2;
	D[3] = 3;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d ", &a);
		printf("%lld\n", sol(a));
	}
}