#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int arr[50];
int n;
int d[17][16000002];
int Mhalf = 0;

struct node
{
	int cnt;
	int sum;
	node(int a, int b) {
		cnt = a;
		sum = b;
	}
};
int Abs(const int a)
{
	if (a < 0) return -a;
	else return a;
}
int chktt(int now, node B, node S, int remain)
{
	int gap = Abs(B.sum - S.sum);
	if (gap > remain) {
		return 0;
	}
	if (B.sum > Mhalf) return 0;
	if (S.sum > Mhalf) return 0;

	if (now == n)
	{
		if (B.sum == S.sum)
		{
			return B.sum;
		}
		else
		{
			return 0;
		}
	}
	if (B.cnt < S.cnt)
	{
		node tmp = S;
		S.cnt = B.cnt;
		S.sum = B.sum;
		B.cnt = tmp.cnt;
		B.sum = tmp.sum;
	}
	int &ret = d[S.cnt][B.sum];
	if (ret != -1) return ret;
	ret = 0;
	B.cnt++;
	B.sum += arr[now];
	if (ret < chktt(now + 1, B, S, remain - arr[now]))
	{
		ret = chktt(now + 1, B, S, remain - arr[now]);
	}
	B.cnt--;
	B.sum -= arr[now];

	S.cnt++;
	S.sum += arr[now];
	if (ret < chktt(now + 1, B, S, remain - arr[now]))
	{
		ret = chktt(now + 1, B, S, remain - arr[now]);
	}
	S.cnt--;
	S.sum -= arr[now];

	if (ret < chktt(now + 1, B, S, remain - arr[now]))
	{
		ret = chktt(now + 1, B, S, remain - arr[now]);
	}

	return ret;
}

int main()
{
	//freopen("표지판_Testcase_Input.txt", "r", stdin);

	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++)
	{
		printf("#%d ", t);
		scanf("%d", &n);
		memset(d, -1, sizeof(d));

		int Maxi = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			Maxi += arr[i];
		}

		Mhalf = (Maxi + 1) / 2;

		int res = chktt(0, node(0, 0), node(0, 0), Maxi);

		if (res == 0)
		{
			printf("YJH잘생김\n");
		}
		else
		{
			printf("%d\n", res);
		}
	}

	return 0;
}