 
#include <iostream>
using namespace std;
int main()
{

	int nCount=1;		 
 

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		for (int i = 1; i < 10000; i++)
		{
			int a;
			for (int j = 10000; j>0; j /= 10){
				if (i / j>0){
					a = j * 10;
					break;
				}
			}
			if ((i*i)%a == i)
				cout << i << endl;
		}
	 
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}