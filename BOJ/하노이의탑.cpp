 
#include <iostream>
using namespace std;
int flag = 0;
void hanoi(int n, int a, int b)
{
	int c;
	if (n <= 1)
	{
		flag++;
	}
	else
	{
		c = 15 - a - b;
		hanoi(n - 1, a, c);
		flag++;
		hanoi(n - 1, c, b);
	}
}
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		int num;
		cout << "#testcase" << (itr + 1) << endl;
		cin >> num;
		
		hanoi(num, 1, 2);
		cout << flag << endl;

		flag = 0;
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}