 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		 

	cin >> nCount;	

	for (int itr = 0; itr<nCount; itr++)
	{
		long long num;

		cin >> num;
		cout << "#testcase" << (itr + 1) << endl;
		long long  i;
		int j = 0;
		for (i = 1;; i *= 2)
		{
		
			if (num < i)
				break;
			j++;

		}
		cout << j << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}