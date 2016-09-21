#include<iostream>
using namespace std;
int main()
{

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{

		unsigned long long input;
		cin >> input;

		unsigned long long j = 1000000000;

		while (input / j == 0)
			j /= 10;
		
		
		if (input >= j * 5-1)
		{
			cout << j * 5 * (j * 5 - 1) << endl;
		}
		else
		{
			cout << input*((j * 10 - 1) - input) << endl;
		}

	}
}

//#include<iostream>
//using namespace std;
//int main()
//{
//
//	int tc;
//	cin >> tc;
//	for (int i = 0; i < tc; i++)
//	{
//
//
//		unsigned long long input;
//		cin >> input;
//
//		unsigned long long j = 1000000000;
//		for (; input%j != 0; j /= 10);
//
//
//		unsigned long long max = 0;
//
//		if (input > j * 5)
//		{
//			max = j * 5 * (j * 5 - 1);
//		}
//		else
//		{
//			for (unsigned long long i = j; i <= input; i++)
//			{
//				unsigned long long a = i*((j * 10 - 1) - i);
//				if (max < a)
//					max = a;
//			}
//		}
//
//		cout << max << endl;
//
//
//
//
//
//	}
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	for (int i = 100; i < 500; i++)
//	{
//		int a = i*(i * 10 - 1) - 1;
//		cout << i << " " << a << endl;
//	}
//
//}