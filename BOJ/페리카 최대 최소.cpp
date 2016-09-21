 #include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		char arr[2][100000] = { 0, };
		char res[4][100000] = { 0, };


		cin >> arr[0] >> arr[1];

		int a, b;

		for (a = 0; arr[0][a] != 0; a++)
		{
			if (arr[0][a] == '5' || arr[0][a] == '6')
			{
				res[0][a] = '5';
				res[1][a] = '6';
			}
			else
			{
				res[0][a] = arr[0][a];
				res[1][a] = arr[0][a];
			}
		}
		for (b = 0; arr[1][b] != 0; b++)
		if (arr[1][b] == '5' || arr[1][b] == '6')
		{
			res[2][b] = '5';
			res[3][b] = '6';
		}
		else
		{
			res[2][b] = arr[1][b];
			res[3][b] = arr[1][b];
		}
		int min = atoi(res[0]) + atoi(res[2]);
		int max = atoi(res[1]) + atoi(res[3]);

		cout << min << " " << max << endl;

	}


	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}