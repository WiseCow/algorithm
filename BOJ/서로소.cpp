 
#include <iostream>
using namespace std;

int gcm(int a, int b)
{
	if (b == 0)return a;
	else gcm(b, a%b);
}
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int a, b;
		cin >> a >> b;
		if (gcm(a, b) == 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;


	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}