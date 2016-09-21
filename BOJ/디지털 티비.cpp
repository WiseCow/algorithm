//https://www.acmicpc.net/problem/2816

#include<iostream>
#include<cstring>
using namespace std;
int arr[501];
void findkbs(int &p, int kbs, bool num)
{
	while (p != kbs)
	{
		cout << "1";
		p++;
	}
	while (p != num)
	{
		int tmp = arr[p];
		arr[p] = arr[p - 1];
		arr[p - 1] = tmp;
		cout << "4";
		p--;
	}
}
int main()
{
	int tc;
	cin >> tc;
	int kbs1, kbs2;
	for (int i = 0; i < tc; i++)
	{
		char arr1[11];
		cin >> arr1;
		if (strcmp(arr1, "KBS1") == 0)
		{
			kbs1 = i;
			arr[i] = 1;
		}
		if (strcmp(arr1, "KBS2") == 0)
		{
			kbs2 = i;
			arr[i] = 2;
		}
	}

	int ptr = 0;
	findkbs(ptr, kbs1, 0);
	for (int i = 0; i < tc; i++)
	{
		if (arr[i] == 2)
			kbs2 = i;
	}
	findkbs(ptr, kbs2, 1);

	cout << endl;
}