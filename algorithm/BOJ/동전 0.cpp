#include<iostream>
using namespace std;
int coin[20];
int tc,money;
int cnt;
int main()
{
	scanf("%d %d", &tc,&money);

	int maxx = 0;
	for (int i = 0; i < tc; i++)
	{
		scanf("%d", &coin[i]);
		if (maxx == i - 1&&money>coin[i])
		{
			maxx = i;
		}
	}


	while (money != 0)
	{
		cnt += money / coin[maxx];
		money %= coin[maxx];

		for (; coin[maxx] > money; maxx--);
	}

	cout << cnt << '\n';

	return 0;
}