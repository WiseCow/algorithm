 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int a, b, c, n;
		cin >> a >> b >> c >> n;

		cout << "#testcase" << (itr + 1) << endl;
		int score = 0;
		for (int i = 0; i < n; i++)
		{
			if (a>b)
			{
				if (a > c)
				{
					if (a!=0)score += a,a--;
				}
				else
				{
					if (c != 0)score += c, c--;
				}
			}
			else
			{
				if (b > c)
				{
					if (b != 0)score += b, b--;
				}
				else
				if (c != 0)score += c, c--;
			}
			
		}
		cout << score << endl;
	}
	
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}