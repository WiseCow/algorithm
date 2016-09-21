#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int num;
		int point = 0;
		int arr[100000] = { 0 }; 
		cin >> num;
		double div[50000] = { 0 };
		for (int i = 1; i <= num; i++)
		{
			for (int j = num; j > i; j--)
			{
				if (i != 1 &&( j%i == 0||gcd(i,j)!=1))
					continue;
				arr[point] = i;
				arr[point + 1] = j;
				div[point / 2] = (double)i / (double)j;
				point += 2;
			}
		}
		int k = point / 2;
		for (int i = 0; i < k-1; i++)
		{
			for (int j = 0; j < k - i - 1; j++)
			{
				if (div[j]>div[j + 1])
				{
					double dtmp = div[j];
					div[j] = div[j + 1];
					div[j + 1] = dtmp;
					int tmp = arr[j * 2];
					arr[j * 2] = arr[(j + 1) * 2];
					arr[(j + 1) * 2] = tmp;
					tmp = arr[j * 2 + 1];
					arr[j * 2 + 1] = arr[(j + 1) * 2 + 1];
					arr[(j + 1) * 2 + 1] = tmp;
				}
			}
		}
		cout << "0/1" << endl;
		for (int i = 0; i < k; i++)
		{
			cout << arr[i * 2] << "/" << arr[i * 2 + 1] << endl;
		}
		cout << "1/1" << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}