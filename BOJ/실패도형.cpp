#include<iostream>
using namespace std;
long long comb[51][51];
int numm[50001];
int numc[50001];
int input[51];
int ptr;
int K;
long long res;
long long combination(int n, int r)
{
	if ((r == 0) || (n == r))
	{
		comb[r][n] = 1;
		return 1;
	}
	if (comb[r][n] != 0)
		return comb[r][n];

	long long a = (combination(n - 1, r) + combination(n - 1, r - 1));
	comb[r][n] = a;
	return a;
}
void find(int a, int arr[10], int p, int cnt)
{
	if (K == cnt)
	{
		int summ = 0, maxx = 0;
		int countt[50] = { 0 };
		for (int i = 0; i < K; i++)
		{
			summ += input[arr[i]];
			countt[arr[i]]++;
			if (maxx < input[arr[i]])
				maxx = input[arr[i]];
		}

		if (maxx < summ - maxx)
		{
			long long temp = 0;
			for (int i = 0; i < ptr; i++)
			{
				int q = numm[input[i]];
				int p = countt[i];
				int a = 0;
				
				long long oo=0;
				if (q != 0)
				{
					oo= combination(q, p);
					if (temp == 0)
					{
						temp = oo;
					}
					else
					{
						temp *= oo;
					}
				}
			}
			res += temp;
		}
	}
	else
	{
		for (int i = a; i < ptr; i++)
		{
			if (numc[input[i]] != 0)
			{
				numc[input[i]]--;
				arr[p] = i;
				find(i, arr, p + 1, cnt + 1);
				numc[input[i]]++;
			}

		}
	}



}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int itr = 0; itr < tc; itr++)
	{
		int a;
		scanf("%d", &a);

		if (numc[a] == 0)
		{
			input[ptr++] = a;
		}
		numc[a]++;
		numm[a]++;
	}

	scanf("%d", &K);


	int tmp[10];
	for (int i = 0; i < ptr; i++)
	{
		numc[input[i]]--;
		tmp[0] = i;
		find(i, tmp, 1, 1);
		numc[input[i]]++;
	}
	cout << res << endl;

}