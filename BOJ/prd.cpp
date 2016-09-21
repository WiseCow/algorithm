#include<iostream>

using namespace std;

#define Max 100000
long long fn(long long an_1, long long an_2, int input)
{

	long long an = an_1 * 3 - an_2;
	if (input == 0)
		return an;
	if (an > Max * Max)
		an %= Max * Max;
	else
		fn(an, an_1, input - 1);
}
int main()
{
	int input, count;
	cin >> input;
	input -= 2;

	cout << fn(1, 1, input) % Max;

}