#include<iostream>
#include<vector>
using namespace std;
struct circle
{
	int left;
	int right;
	int mid;
	circle(int a, int b, int c)
	{
		left = a;
		right = b;
		mid = c;
	}
};
int main()
{

	int tc;
	cin >> tc;
	vector<circle> C;

	for (int itr = 0; itr < tc; itr++)
	{
		int a, b;

		cin >> a>> b;
		C.push_back(circle(a - b, a + b, a));
	}

	cout << tc;



}