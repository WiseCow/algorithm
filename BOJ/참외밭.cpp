#include<cstdio>
#define max(a,b) a>b?a:b
int K,res,rec[6];
int R[4][3],ridx;
int C[4][3],cidx;
int main()
{
	scanf("%d", &K);
	for (int tc = 0; tc < 6; tc++)
	{
		int t, k;
		scanf("%d%d", &t, &k);
		rec[tc] = k;
		if (t < 3)
		{

			R[ridx][2] = tc;
			R[ridx][1] = t-1;
			R[ridx++][0] = k;
		}
		else
		{
			C[cidx][2] = tc;
			C[cidx][1] = t-1; 
			C[cidx++][0] = k;
		}
	}
	int rm=0, ri,rix, cm=0, ci,cix;
	for (int i = 0; i < 3; i++)
	{
		if (rm < R[i][0])
		{
			rm = R[i][0];
			ri = R[i][1];
			rix = R[i][2];
		}
		if (cm < C[i][0])
		{
			cm = C[i][0];
			ci = C[i][1];
			cix = i;
		}
	}
	res = rm*cm;

	if (rec[(rix + 1) % 6] == cm)
		res -= (rec[(rix + 3) % 6] * rec[(rix + 4) % 6]);
	else
	res-= (rec[(rix + 2) % 6] * rec[(rix + 3) % 6]);

	printf("%d", res*K);
}