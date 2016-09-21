#include<iostream>
using namespace std;
char input[101];
int main()
{
	scanf("%s", &input[1]);
	int w = 1;
	while (input[w] != 0)w++;
	int a, b;
	w--;
	int R = 0, C = 0;
	for (int a = 1; a <= 10; a++)
	{
		for (int b = 1; a * b <= w; b++) {
			if (a*b == w&&a <= b&&a > R)
			{
				R = a;
			}
		}
	}

	C = w / R;



	for (int i = 1; i <= R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << input[R*j + i];
		}
	}


	cout << '\n';

	//cout << C << " " << R;

	return 0;




}