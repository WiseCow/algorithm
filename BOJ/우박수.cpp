#include <iostream>
using namespace std;


void find(int num)
{
	if (num == 1){
		cout << 1 << endl;
		return;
	}

	if (num % 2 == 1)
		find(3 * num + 1);
	else
		find(num / 2);
	cout << num << endl;

}
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		cin >> num;
		find(num);

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}