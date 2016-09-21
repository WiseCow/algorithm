#include<iostream>


using namespace std;
int flag = 0;

void up(int stair, int now)
{
	if (now > stair)
		return;
	else if (now == stair)
	{
		flag++;
	}
	else
	{
		up(stair, now + 1);
		up(stair, now + 2);

	}
}

int main()
{
	int stair;
	cin >> stair;
	up(stair, 0);
	cout << flag;
}