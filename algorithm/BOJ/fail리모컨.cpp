#include<cstdio>
bool disa[11];
int abs(int a)
{
	return a > 0 ? a : -a;
}
int main()
{
	char N[7];
	scanf("%s", &N);
	int len = 0;
	int input = 0;
	while (N[len])
	{
		int a = N[len]-'0';
		input *= 10;
		input += a;
		len++;
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a;
		scanf("%d", &a);
		disa[a] = 1;
	}
	int plus = abs(100 - input);





}