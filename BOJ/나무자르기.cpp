#include<cstdio>
int in[1000001];
int N, M;
bool cut(int len)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (in[i] > len)
		{
			sum += in[i] - len;
		}
	}

	return sum >= M;
}

int main()
{
	
	scanf("%d %d", &N, &M);
	int maxx = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &in[i]);
		maxx = maxx > in[i] ? maxx : in[i];
	}


	int l = 0, r = maxx;
	int res = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (cut(mid))
		{
			l = mid + 1;
			if (res < mid)
				res = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%d\n",res);

}