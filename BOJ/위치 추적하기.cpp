#include <iostream>
using namespace std;
#define max 100000
int _abs(int a)
{
	return a > 0 ? a : -a;
}
int x[max], y[max];
char arr[3 * max];

int main()
{

	int nCount;		

	cin >> nCount;	

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int N, M;
		cin >> N >> M;
		
		for (int i = 0; i < N; i++)
		{
			cin >> x[i] >> y[i];
		}
		
		cin >> arr;
		int now_x = 0, now_y = 0;
		for (int po = 0; po < M; po++)
		{
			if (arr[po] == 'E')
				now_x++;
			else if (arr[po] == 'W')
				now_x--;
			else if (arr[po] == 'S')
				now_y--;
			else
				now_y++;

			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				sum += (_abs(x[i] - now_x) + _abs(y[i] - now_y));
			}
			cout << sum << " ";



		}

		cout << endl;




	}

	return 0;	

}