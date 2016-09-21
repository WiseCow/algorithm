//https://www.acmicpc.net/problem/10250
#include<iostream>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	for (int itr = 0; itr < tc; itr++)
	{
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);

		int mok = N/H;
		int mod = N%H;
		
		if (mod != 0)
			cout << mod;
		else
			cout << H;
		if (mod != 0)
		{
			mok += 1;
		}
		
		if (mok < 10)
			cout << "0";
	
		cout << mok << endl;
	}
}