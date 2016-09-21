#include<iostream>
using namespace std;


int main()
{
	int nCount;
	cin >> nCount;

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << itr + 1 << endl;

		int num;
		cin >> num;
		int mod = 2;
		while (1)
		{
			

			if (num%mod == 0)
			{
				cout << mod << " ";
				num /= mod;
			}
			else
			{
				mod++;
			}

			if (num == 1)
				break;
		}
		cout << endl;




	}

	return 0;
}