#include<iostream>
using namespace std;
int  N, M;
int main()
{
	scanf("%d %d", &N, &M);

	if (N == 1)
	{
		cout << 1;
	}
	else if(N==2)
	{
		if (M > 7)
			cout << 4;
		else
			cout << (M + 1) / 2;
	}
	else
	{
		if (M >= 7)
		{
			cout << M - 2;
		}
		else
		{
			if (M < 4)
				cout << M;
			else
				cout << 4;

		}
	}

	cout << '\n';


	return 0;



}