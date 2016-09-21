//축사 보안프로그램

#include <iostream>
using namespace std;
void out(char(*arr)[2], int count, int charcount, int charsize, char *wor, int x, char* first)
{

	if (count == 0)
	{
		for (int i = 0; i <= charcount - charsize; i++)
		{
			*wor = *(arr + i)[0];
			out(arr + 1, count + 1, charcount, charsize, wor + 1, i, first);
		}
	}
	else if (count == charsize)
	{
		int flag = 0;
		for (int i = 0; i < charsize; i++)
		{
			if (*(first + i) == 'a' || *(first + i) == 'e' || *(first + i) == 'i' || *(first + i) == 'o' || *(first + i) == 'u')
				flag++;
		}
		if (flag > 0)
		{
			for (int i = 0; i < charsize; i++)
			{
				cout << *(first + i);
			}
			cout << endl;
		}


	}

	else
	{
		for (int i = x; i <= charcount - charsize; i++)
		{
			*wor = *(arr + i)[0];
			out(arr + 1, count + 1, charcount, charsize, wor + 1, i, first);
		}
	}

}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int charsize;
		int charcount;
		char arr[100][2];
		char word[100] = { 0, };
		char(*ptr)[2] = arr;
		cin >> charsize >> charcount;

		for (int i = 0; i < charcount; i++)
			cin >> arr[i];

		for (int i = 0; i < charcount - 1; i++)
		for (int j = 0; j < charcount - i - 1; j++)
		if (strcmp(arr[j], arr[j + 1]) > 0)
		{
			char tmp[100];
			strcpy_s(tmp, arr[j]);
			strcpy_s(arr[j], arr[j + 1]);
			strcpy_s(arr[j + 1], tmp);

		}





		cout << "#testcase" << (itr + 1) << endl;
		out(ptr, 0, charcount, charsize, word, 0, word);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}