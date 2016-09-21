#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;

int cnt[200004] = { 0 };
int gro[200004] = { 0 };

int fi(int x)
{
	if (x == gro[x])
		return x;
	else
		return gro[x] = fi(gro[x]);
}

void uni(int x, int y)
{
	gro[fi(y)] = fi(x);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		int F;
		map< string,int> ma;
		scanf("%d", &F);
		memset(gro, 0, sizeof(gro));
		for (int i = 1; i <= F*2; i++)
			gro[i] = i;
		int fc = 1;
		for (int fr = 0; fr < F; fr++)
		{
			char aa[22], bb[22];
			scanf("%s %s",&aa, &bb);
			string a = aa, b = bb;
			if (!ma[a])
				ma[a] = fc++;
			if (!ma[b])
				ma[b] = fc++;
			int mma = ma[a];
			int mmb = ma[b];
			uni(mma, mmb);
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i < fc; i++)
			{
				gro[i] = fi(gro[i]);
				cnt[gro[i]]++;
			}
			printf("%d\n", cnt[gro[mma]]);
		}
	}
	return 0;


}