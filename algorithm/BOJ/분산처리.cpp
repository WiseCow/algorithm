//#include<iostream>
//using namespace std;
//int main()
//{
//	int tc;
//	cin >> tc;
//	for (int itr = 0; itr < tc; itr++)
//	{
//		int a, b;
//		cin >> a >> b;
//
//
//		if (a == 1)
//		{
//			cout << 1 << endl;
//			continue;
//		}
//		int tmp = (a*a) % 10;
//		int rec;
//		for (rec = 1; tmp != a; rec++)
//		{
//			tmp *= a;
//			tmp = tmp % 10;
//		}
//		b %= rec;
//		tmp = 1;
//
//		for (int i = 0; i < b; i++)
//		{
//			tmp *= a;
//			tmp = tmp % 10;
//		}
//		if (tmp != 0)
//			cout << tmp << endl;
//		else
//			cout << 10 << endl;
//	}
//
//}
//https://www.acmicpc.net/problem/1009
#include<iostream>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	for (int itr = 0; itr < tc; itr++)
	{
		int a, b;
		cin >> a >> b;


		if (a == 1)
		{
			cout << 1 << endl;
			continue;
		}
		int result = 1;

		for (int i = 0; i < b; i++)
		{
			result *= a;
			result %= 10;

		}
		if (result != 0)
			cout << result << endl;
		else
			cout << 10 << endl;
	}

}