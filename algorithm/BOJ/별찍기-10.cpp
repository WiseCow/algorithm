#include<cstdio>
int N;
char map[2200][2200];
void makemap(int n, int nowy, int nowx,int ry, int rx)
{
	int k = n / 3;
	if (n == 1)
	{
		if (ry == 1 && rx == 1)
			map[nowy][nowx] = ' ';
		else
			map[nowy][nowx] = '*';
	}
	else
	{
		if (ry == 1 && rx == 1)
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					makemap(k, nowy + i*k, nowx + j*k, 1, 1);
		else		
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					makemap(k, nowy + i*k, nowx + j*k, i, j);		
	}

}
int main()
{
	scanf("%d", &N);
	if (N == 1)
	{
		printf("*");
		return 0;
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			makemap(N / 3, i*N/3, j*N/3,i,j);
	for (int i = 0; i < N;i++)
	printf("%s\n", map[i]);
}
