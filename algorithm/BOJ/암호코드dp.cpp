#include<iostream>
using namespace std;
char in[5002];
long long D[5002];
const int mod = 1000000;
int main()
{

	scanf("%s", &in[1]);
	int i;
	D[0] = 1;
	for (i = 1; in[i] != 0; i++)
	{
		if (i == 1)
		{
			if (in[i] != '0')
				D[i] = 1;
		}
		else
		{
			if (in[i] != '0') {
				D[i] += D[i - 1];
				D[i] %= mod;
			}
			int a = (in[i - 1] - '0')*10+ in[i] - '0';

			if (a >= 10 && a <= 26) {
				D[i] += D[i - 2];
				D[i] %= mod;
			}

		}
	}

	cout << D[i-1]<<'\n';


}


