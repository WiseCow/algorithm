#include<cstdio>
#include<cstring>
int in[100001], D[100001][5][5];
int abs(int a)
{
	return a > 0 ? a : -a;
}
int sol(int now, int l, int r)
{
	if (in[now] == 0)
		return 0;
	int &ret = D[now][l][r];
	if (ret != -1)return ret;
	int t1 = 987654321, t2 = 987654321;
	if (in[now] != r)
		t1 = sol(now + 1, in[now], r);
	if (in[now] != l)
		t2 = sol(now + 1, l, in[now]);


	if (l == 0 && r == 0)
	{
		t1 += 2;
		t2 += 2;
	}
	else if (l == 0)
	{
		t1 += 2;
		if (in[now] == r)
			t2 += 1;
		else
			t2 += abs(r - in[now]) == 2 ? 4 : 3;
	}
	else if (r == 0)
	{
		t2 += 2;
		if (in[now] == l)
			t1 += 1;
		else
			t1 += abs(l - in[now]) == 2 ? 4 : 3;
	}
	else
	{
		if (in[now] == l)
		{
			t1 += 1;
			t2 += abs(r - in[now]) == 2 ? 4 : 3;
		}
		else if (in[now] == r)
		{
			t1 += abs(l - in[now]) == 2 ? 4 : 3;
			t2 += 1;
		}
		else
		{
			t1 += abs(l - in[now]) == 2 ? 4 : 3;
			t2 += abs(r - in[now]) == 2 ? 4 : 3;
		}
	}
	if (t1 < t2)
		ret = t1;
	else
		ret = t2;
	return ret;
}



int main()
{
	int idx = 1;
	while (1)
	{
		scanf("%d", &in[idx]);
		if (in[idx] == 0)
			break;
		idx++;
	}

	memset(D, -1, sizeof(D));

	printf("%d", sol(1, 0, 0));


}