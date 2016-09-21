#include<iostream>
using namespace std;
int main()
{
	int sum=0;
	for (int i = 0; i < 5; i++)
	{
		int a;
		scanf("%d", &a);
		if (a < 40)
			sum += 40;
		else
			sum += a;
	}
	cout << sum / 5 << endl;
}