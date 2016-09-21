#include<cstdio>
int N1, N2,T;
char a1[27], a2[27];
int po1[101], po2[101];
int main()
{
	scanf("%d %d", &N1, &N2);
	for (int i = N1; i >= 0; i--)
	{
		scanf("%c", &a1[i]);
		po1[i] = -N1 + i;
	}
	a1[N1] = 0;
	scanf("%s", &a2);
	scanf("%d", &T);

	for (int i = 0; i < N2; i++)
		po2[i] = i-T-1;

	for (int i = -51; i < 51; i++)
	{
		for (int j = 0; j < N1; j++)
			if (po1[j] == i)
				printf("%c", a1[j]);


		for (int j = 0; j < N2; j++)
			if (po2[j] == i)
				printf("%c", a2[j]);
		
	}
	printf("\n");
	return 0;
}