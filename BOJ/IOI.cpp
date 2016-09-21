#include<cstdio>
typedef long long ll;
using namespace std;
int N, M,len=1;
const int mod = 1e9 + 7;
char S[1000001] ,I[500002];
int p(int a, int b)
{
	if (b == 0)
		return 1;
	int tmp = p(a, b / 2);
	if (b & 1)
	{
		return(((ll)tmp*tmp) % mod*a) % mod;
	}
	return ((ll)tmp*tmp) % mod;
}
int main()
{
	scanf("%d%d%s", &N,&M,&S);
	I[0] = 'I';
	for (int i = 0; i < N; i++)
	{
		I[len] = 'O';
		I[len + 1] = 'I';
		len += 2;
	}
	int X = 0;
	int t = p(26, len-1);
	for (int i = 0; i < len; i++)
		X = ((ll)X * 26 + I[i]) % mod;
	int T = 0,ans=0;
	for (int i = 0; i + len < M+1; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < len; j++)
			{
				T = ((ll)T * 26 + S[j]) % mod;
			}
		}
		else
		{
			T = (mod + T - ((ll)S[i - 1] * (t)) % mod) % mod;
			T = ((ll)T * 26 + S[i + len - 1]) % mod;
		}
		if (X == T)
			ans++;

	}
	printf("%d",ans);
}