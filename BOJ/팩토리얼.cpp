 
#include <iostream>
using namespace std;
long long fa(int i)
{
	if (i == 0)return 1;
	else return i*fa(i - 1);
}
int main()
{

		int num;
		cin >> num;
		cout << fa(num) << endl;
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}