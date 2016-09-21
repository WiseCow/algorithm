#include<iostream>
using namespace std;
int fac(int a){
	if (a == 1)return 1;
	else return fac(a - 1)*a;
}
int main()
{	cout << fac(5) << endl;}