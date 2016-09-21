#include<cstdio>
#include<algorithm>
using namespace std;
int a, b, c,m[3];
int main()
{
	while (1)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a + b + c == 0)
			break;
		if (a == b&&b == c)
			printf("Equilateral\n");
		else
		{
			m[0] = a;
			m[1] = b;
			m[2] = c;
			sort(m, m + 3);
			if (m[0] + m[1] <= m[2])
				printf("Invalid\n");
			else
			{
				if (m[0] == m[1]||m[1]==m[2])
					printf("Isosceles\n");
				else
					printf("Scalene\n");
			}
		}
	}
}