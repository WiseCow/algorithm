#include<cstdio>
int D[5001];
char in[5055];
int main()
{
	scanf("%s", &in[1]);
	int len = 1;
	while (in[len])len++;

	D[0]=D[1] = 1;

	for (int i = 2; i < len; i++)
	{
		int a = in[i]-'0';
		int b = in[i] - '0'+(in[i-1]-'0')*10;

		if (a > 0)
			D[i] += D[i - 1];
		if (b >= 10 && b <= 26)
			D[i] += D[i - 2];
		D[i] %= 1000000;
	}

	printf("%d", D[len - 1]);



}