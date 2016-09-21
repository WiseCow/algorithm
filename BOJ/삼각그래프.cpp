#include<iostream>
#define min(a,b) ((a)<(b))?a:b
using namespace std;
int N;
int in[100002][4];
long long D[100002][4];
int tc = 0;
int main()
{
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d %d %d", &in[i][1], &in[i][2], &in[i][3]);
		}
		D[1][1] = in[1][1];
		D[1][2] = in[1][2];
		D[1][3] = in[1][3] + in[1][2];
		D[2][1] = in[1][2]+in[2][1];
		D[2][2] = min(D[1][2], min(D[1][3], D[2][1]));
		D[2][2] += in[2][2];
		D[2][3] = min(D[1][3], min(D[1][2], D[2][2]));
		D[2][3] += in[2][3];
		for (int i = 3; i <= N; i++)
		{
			D[i][1] = min(D[i - 1][1], D[i - 1][2]);
			D[i][1] += in[i][1];
			D[i][2] = min(D[i - 1][1], min(D[i - 1][2], min(D[i - 1][3], D[i][1])));
			D[i][2] += in[i][2];
			D[i][3] = min(D[i - 1][3], min(D[i - 1][2], D[i][2]));
			D[i][3] += in[i][3];
		}
		printf("%d. %lld\n", ++tc, D[N][2]);
	}

}