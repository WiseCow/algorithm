 

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int a, b;
		cin >> a >> b;
		
		if (a % 2 == 0 && b % 2 == 0)
		{
			cout << "even+even=even" << endl << "even*even=even" << endl;
		}
		else if (a % 2 == 0)
		{

			cout << "even+odd=odd" << endl << "even*odd=even" << endl;
		}
		else if (b % 2 == 0)
		{
			cout << "odd+even=odd" << endl << "odd*even=even" << endl;
		}
		else
		{
			cout << "odd+odd=even" << endl << "odd*odd=odd" << endl;

		}
		

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}