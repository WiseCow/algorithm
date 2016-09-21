#include<iostream>
using namespace std;
char in[2501];
bool chk[2501][2501];
int d[2501];
int main()
{
	scanf("%s", &in[1]);

	int len = 1;
	while (in[len] != 0)len++;

	for (int i = 1; i < len;i++)
	{ 
		chk[i][i] = 1;
		for (int l = 1; l < i; l++)
		{
			if (l == 1)
			{
				if (in[i] == in[i - l])
					chk[i][i - l] = 1;

			}
			else
			{
				if (chk[i - 1][i - l+1] && in[i] == in[i - l])
					chk[i][i - l] = 1;
			}
		}
	}

	d[0] = 0;
	for (int i = 1; i < len; i++) {
		d[i] = -1;
		for (int j = 1; j <= i; j++) {
			if (chk[i][j]) {
				if (d[i] == -1 || d[i] > d[j - 1] + 1) {
					d[i] = d[j - 1] + 1;
				}
			}
		}
	}
	cout << d[len-1]<<'\n';



	return 0;




}