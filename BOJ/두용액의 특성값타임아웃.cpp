#include <iostream>
using namespace std;
#define SWAP(a, b) {int t=a; a=b;b=t;}
int main()
{

	int nCount;		

	cin >> nCount;	

	for (int itr = 0; itr<nCount; itr++)
	{
		int _case;
		cin >> _case;
		long long num[100000];
		for (int i = 0;i < _case; i++)
			cin >> num[i];

		for (int i = 0; i < _case-1;i++)
		for (int j = 0; j < _case - i - 1;j++)
		if (num[j]>num[j + 1])
			SWAP(num[j], num[j + 1]);
		
		cout << "#testcase" << (itr + 1) << endl;
		long long mini = 100;
		int x, y;
		for (int i = 0; i < _case / 2; i++){
			for (int j = _case - 1; j >= _case / 2; j--){
				int n = num[i] + num[j];
				if (i == j)
					continue;
				if (n < 0)
				{
					n=-n;
				}
				if (n < mini)
				{
					mini = num[i] + num[j];
					x = i, y = j;
				}

			}
		}

		cout << num[x] << " " << num[y]<<endl;

	}

	return 0;	

}