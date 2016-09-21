#include<iostream>
using namespace std;
int main()
{
	char arr[1000];
	char arr1[1000];


	scanf("%s", &arr);
	scanf("%s", &arr1);

	int a, b;
	int i = 0;
	for (; arr[i] != 'h' && arr1[i] != 'h'; i++);


	if (arr[i] == 'h')
	{
		if (arr1[i] == 'h')
			cout << "go\n";
		else
			cout <<"no\n";

	}
	else
	{
		cout << "go\n";
	}
	


}