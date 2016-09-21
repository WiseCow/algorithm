#include<iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a%b);

}

int main(void)
{
	int tc;
	cin >> tc;
	for (int cs = 0; cs < tc; cs++)
	{
		int result = 0;

		int jari;
		char qus[7];
		bool fin[100000] = { 0 };
		cin >> jari >> qus;
		int togcd = 1;
		for (int a = 0; a < 6; a++)
		{

			if (qus[a] == '0')
			{
				for (int k = 1; k*(a + 1) < 100000; k++)
					fin[k*(a + 1)] = 1;
			}

			else if (qus[a] == '1')
			{

				if (togcd == 1)
					togcd = a + 1;
				else
				{
					togcd = togcd * (a + 1) / gcd(togcd, a + 1);
				}
			}
		}
		int cnt=0;
		int max = 1;
		for (int i = 0; i < jari; i++)
			max *= 10;


		for (int i = 1; i*togcd <= max; i++)
		{
			if (fin[i*togcd] == 0)
				cnt++;
		}

		cout << cnt << endl;

	}
	return 0;
}