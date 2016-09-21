//https://www.acmicpc.net/problem/1193
#include<iostream>
using namespace std;
int main()
{
	int input;
	cin >> input;

	int a = 1;
	int i;
	for (i= 0;a<input;i++)
	{
		input -= a;
		a++;
	}

	if (i % 2 == 0)
	{
		cout << a-input+1  << "/" << input << endl;
	}
	else
	{
		cout << input << "/" << a - input+1<< endl;
	}
}