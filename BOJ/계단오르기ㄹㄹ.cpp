#include<cstdio>
#include<cstring>
int N;
int arr[301];
int D[301][4];

int sol(int now, int sec)
{
	if (now == N)
		return arr[N];
	int &ret = D[now][sec];
	if (ret != -1)return ret;
	
	int t1=0, t2=0;

	if (sec < 2)
	{
		if(now+1<=N)
		t1 = arr[now] + sol(now + 1, sec + 1);
		if (now + 2 <= N)
		t2 = arr[now] + sol(now + 2, 1);
 	}
	else
	{
		if (now + 2 <= N)
		t1 = arr[now] + sol(now + 2, 1);
	}

	return ret = t1>t2 ? t1 : t2;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	memset(D, -1, sizeof(D));
	printf("%d", sol(0,0));

}