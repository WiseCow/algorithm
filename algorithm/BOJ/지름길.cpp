//https://www.acmicpc.net/problem/1446
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dir[10001];
struct comp
{
	int a, b, c;
	comp(int q, int w, int e)
	{
		a = q;
		b = w;
		c = e;
	}
};



bool  cmp( const comp &a,  const comp &b)
{
	if (a.a > b.a)
		return 0;
	else if (a.a < b.a)
		return 1;
	else
	{
		if (a.b > b.b)
			return 0;
		else if (a.b < b.b)
			return 1;
		else
		{
			if (a.c > b.c)
				return 0;
			else if (a.c < b.c)
				return 1;
			else 
				return 1;
		}
	}


}



int main()
{
	int N,D;
	scanf("%d %d", &N,&D);

	for (int i = 1; i <= D; i++)
		dir[i] = i;

	vector<comp> v;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a,&b,&c);

		v.push_back(comp(a, b, c));
		
	}



	sort(v.begin(), v.end(), cmp);



	for (int i = 0; i < N; i++)
	{
		int m = dir[v[i].a] + v[i].c;
		if (v[i].b>D)
			continue;
		if (dir[v[i].b]>m)
		{
			for (int l = v[i].b; l <= D; l++)
			{
				if (dir[l] > m)
				{
					dir[l] = m++;
				}
				else
					break;
			}
		}
	}



	printf("%d\n", dir[D]);

	

}