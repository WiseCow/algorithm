#include<iostream>
using namespace std;
int idx[16] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768 };
int N, in[20][20],P;
char state[18];
int D[17][17];
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &in[i][j]);
	scanf("%s", &state[1]);
	int mp = 0;

	int init=0;
	for (int i = N; i >=1; i--)
	{
		if (state[i] == 'Y')
		{
			mp++;
			init <<= 1;
			init += 1;
		}
		else
			init <<= 1;
	}

	scanf("%d", &P);

	for (int i = 1; i <= (1 << N); i <<= 1)
	{
		if (init&i == i)
		{
			for (int j = 1; j < (1 << N); j <<= 1)
			{
				if ((init&j) == 0)
				{
					if (D[1][init | j] == 0 || D[1][init | j] < in[1 << (i-1)][1 << (j-1)])
						D[1][init | j] = in[1 << (i-1)][1 << (j-1)];
				}
			}
		}
	}
	return 0;
	
}