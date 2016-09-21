#include<cstdio>
#include<cstring>
int in[500][500];

int main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	memset(in, 0x3f, sizeof(in));
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		in[a][b] = 1;
	}

}