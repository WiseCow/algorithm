#include<iostream>
using namespace std;


int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin>>nCount;	/* �׽�Ʈ ���̽� �Է� */

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

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}