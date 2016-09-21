#include<stdio.h>


int main(){
	int a, b[100], c, d, e, f;
	scanf("%d", &a);
	for (c = 0; c<a; c++)
	{
		scanf("%d", &b[c]);
	}

	for (c = 0; c<a; c++)
	{
		printf("#testcase%d\n", c + 1);
		if (b[c]<3 || b[c]>18)
			printf("none\n");
		else{

			for (d = 1; d <= 6; d++)
			for (e = 1; e <= 6; e++)
			for (f = 1; f <= 6; f++)
			if ((d + e + f) == b[c])
				printf("%d %d %d\n", d, e, f);
		}
	}

	return 0;




}
