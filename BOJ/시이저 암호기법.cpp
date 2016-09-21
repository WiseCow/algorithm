#include<iostream>
using namespace std;


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	cin>>nCount;	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		char word[51];
		int num;
		cin >> num;
		cin >> word;
		for (int i = 0; ; i++)
		{
			if (word[i] == 0)
				break;
			word[i] += num;
			if (word[i]>90)
				word[i] -= 26;

		}
		cout<<"#testcase"<<itr + 1<<endl;
		cout << word<<endl;

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}