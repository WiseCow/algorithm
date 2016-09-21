#include<iostream>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		int r = (r2 + r1)*(r2 + r1);
		int _r = (r1 - r2)*(r1 - r2);

		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << endl;
			continue;
		}

		else{
			if (d > r)cout << 0 << endl;
			else if (d == r)cout << 1 << endl;
			else{
				if (d > _r) cout << 2 << endl;
				else if (d == _r)cout << 1 << endl;
				else cout << 0 << endl;
			}
		}
	}

}