#include<cstdio>
int main()
{
	char ans[80];
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%s", &ans);
		int k = 0;
		int res = 0;
		int sec = 0;
		while (ans[k])
		{
			if (ans[k] == 'O')
				sec++;
			else
				sec = 0;
			res += sec;
			k++;
		}
		printf("%d\n", res);
	}
}