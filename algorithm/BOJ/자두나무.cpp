#include<iostream>
#define max(a,b) ((a)>(b))?a:b
using namespace std;
int T, W,D[1001][31][2];
int main()
{
	scanf("%d %d", &T, &W);

	for (int i = 1; i <= T; i++)
	{
		int a;
		scanf("%d", &a);

		--a;
		for (int j = 0; j <= W; j++)
		{
			D[i][j][0] = D[i - 1][j][0];
			if(j!=0)
			D[i][j][1] = D[i - 1][j][1];
			if (a == 0)
			{
				D[i][j][0]++;
				if (j != 0)
					D[i][j][0] = max(D[i][j][0], D[i - 1][j - 1][1] + 1);

			}
			else
			{
				D[i][j][1]++;
				if (j != 0)
					D[i][j][1] = max(D[i][j][1], D[i - 1][j - 1][0] + 1);
			}
		}
	}




	int maxx = 0;
	for (int i = 0; i <= W; i++)
		for (int j = 0; j < 2; j++)
			maxx = max(maxx, D[T][i][j]);



	cout << maxx << '\n';


}