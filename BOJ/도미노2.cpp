#include<iostream>

using namespace std;

int main()
{
	int num;

	cin >> num;

	int block[40][2];
	int sum[40];


	for (int i = 0; i < num; i++)
	{
		cin >> block[i][0] >> block[i][1];
		sum[i] = block[i][0] + block[i][1];
	}


	for (int i = 0; i < num; i++)
	{
		int mini = i;
		for (int j = i; j < num; j++)
		{
			if (sum[mini]>sum[j])
				mini = j;
		}

		int tmp = sum[mini];
		sum[mini] = sum[i];
		sum[i] = tmp;
	}


	for (int i = num - 1; i >= 0; i--)
		cout << sum[i] << " ";


	/*
	int ans = 0;
	int ten = 10;

	for (int i = 0; i < num; i++)
	{
	if (i == 0)
	{
	ans = sum[i];
	}
	else
	{
	ans += sum[i] * ten;
	ten *= 10;
	}
	}

	cout << ans;

	*/


	int k;
	int last = 0;
	for (int i = 0; i < num; i++)
	{
		k = sum[i] / 10;
		if (k == 1)
			cout << k + last;
		else
			if (last != 0)
				cout << last;
			else if (last == 0 && i != 0)
				cout << last;
		last = sum[i] % 10;

	}

	cout << last << endl;


	return 0;
}