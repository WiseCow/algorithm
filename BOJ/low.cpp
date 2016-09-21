#include <iostream>
using namespace std;

void print(int num)
{
	if (num == 0)
	{
		return;
	}

	if (num % 2 == 0)
	{
		
		print(-(num / 2));
		cout << "0";
	}
	else
	{
		if (num >= 0)
			print(-num / 2);
		else
			print((-num+1) / 2);
		cout << "1";
	}



}


int main()
{
	int a;
	cin >> a;

	if (a != 0)
		print(a);
	else
		cout << 0;
	cout << endl;
	return 0;
	
}