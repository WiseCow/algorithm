#include<iostream>
using namespace std;
int main()
{
	int R, C;

	char arr[52][52];
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++)
	{
		scanf("%s", &arr[i][1]);
	}
	int a = 0, b = 0, c = 0, d = 0,e=0;
	for (int i = 1; i < R; i++)
		for (int j = 1; j < C; j++)
		{
			int com = 0;
			int bi = 0;
			int car = 0;
			for (int l = 0; l < 2; l++)
				for (int o = 0; o < 2; o++)
				{
					if (arr[i + l][j + o] == '.')
						com++;
					if (arr[i + l][j + o] == '#')
						bi++;
					if (arr[i + l][j + o] == 'X')
						car++;
				}

			if (com == 4)
				a++;
			if (com == 3 && car == 1)
				b++;

			if (com == 2 && car == 2)
				c++;

			if (com == 1 && car == 3)
				d++;
			if (car == 4)
				e++;
		}
	printf("%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e);
}