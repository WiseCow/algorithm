#include<cstdio>
char input[1004];
int fo,tc;
int main()
{
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &fo);
		scanf("%s", &input);
		for (int i = 0; input[i] != 0; i++)
		{
			for (int j = 0; j < fo; j++)
				printf("%c", input[i]);
		}
		printf("\n");
	}
}