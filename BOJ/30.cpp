#include<iostream>
using namespace std;
long long chk[10];

int main()
{
	char a[100001];
	scanf("%s", &a);

	long long sum=0;
	for (int i = 0; a[i] != 0; i++)
	{
		chk[a[i] - '0']++;
		sum += a[i] - '0';
	}

	if (chk[0] == 0 || sum % 3 != 0)
		cout << "-1";
	else
	{
		for (int i = 9; i >= 0; i--)
		{
			while (chk[i] != 0)
			{
				cout << i;
					chk[i]--;
			}
		}
	}
	cout << '\n';

}