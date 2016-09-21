#include<iostream>
using namespace std;

int main()
{
	int N, r, c;

	while (scanf("%d %d %d",&N,&r,&c)!=EOF)
	{
	
		int num = 0, cnt = 0, term = 1, xr = 0, xc = 0, numterm = 1;

		int tmp = 0;
		while (1)
		{
			while (!(xr <= r&&r < xr + term&&xc <= c&&c < xc + term))
			{
				if (cnt == 0)
				{
					cnt++;
					xc += term;
					num += numterm;
				}
				else if (cnt == 1)
				{
					cnt++;
					xr += term;
					xc -= term;
					num += numterm;
				}
				else if (cnt == 2)
				{
					cnt++;
					xc += term;
					num += numterm;
				}
				else
				{
					cnt = 0;
					xr = 0;
					xc = 0;
					num = 0;
					term *= 2;
					numterm *= 4;
				}
			}
			tmp += num;
			r -= xr;
			c -= xc;
			xr = 0;
			xc = 0;
			term /= 2;
			num = 0;
			cnt = 0;
			numterm /= 4;

			if (xc == c&&xr == r)
			{
				cout << tmp + num << endl;
				break;
			}


		}
	}






}