#include <iostream>

using namespace std;
int maxcnt;
void serch(int (*map)[25], int rx, int ry, int bx, int by, int cnt )
{

	if (map[bx][by] == 4)
		return;
	if (map[rx][ry] == 4 && map[bx][by] != 4 && (rx != bx || ry != by))
	{
		if (maxcnt > cnt)
			maxcnt = cnt;
		return;
	}

	if (cnt<11&&(rx!=bx||ry!=by))
	{
		if (map[rx + 1][ry] != 3 || map[bx + 1][by] != 3)
		{
			if (map[rx + 1][ry] != 3 && map[bx + 1][by] != 3)
			{
				serch(map, rx+1, ry, bx+1, by, cnt + 1);
			}
			if (map[rx + 1][ry] != 3 && map[bx + 1][by] == 3)
			{
				serch(map, rx + 1, ry, bx, by, cnt + 1);
			}
			if (map[rx + 1][ry] == 3 && map[bx + 1][by] != 3)
			{
				serch(map, rx, ry, bx+1, by, cnt + 1);
			}
		}
			
		if (map[rx - 1][ry] != 3 || map[bx - 1][by] != 3)
		{
			if (map[rx - 1][ry] != 3 && map[bx - 1][by] != 3)
			{
				serch(map, rx - 1, ry, bx - 1, by, cnt + 1);
			}
			if (map[rx - 1][ry] != 3 && map[bx - 1][by] == 3)
			{
				serch(map, rx - 1, ry, bx, by, cnt + 1);
			}
			if (map[rx - 1][ry] == 3 && map[bx - 1][by] != 3)
			{
				serch(map, rx, ry, bx - 1, by, cnt + 1);
			}
		}
		if (map[rx][ry+1] != 3 || map[bx][by+1] != 3)
		{
			if (map[rx][ry+1] != 3 && map[bx][by+1] != 3)
			{
				serch(map, rx, ry + 1, bx , by +1, cnt + 1);
			}
			if (map[rx][ry+1] != 3 && map[bx][by+1] == 3)
			{
				serch(map, rx, ry+1,  bx, by, cnt + 1);
			}
			if (map[rx][ry + 1] == 3 && map[bx][by + 1] != 3)
			{
				serch(map, rx, ry, bx, by + 1, cnt + 1);
			}
		}
		if (map[rx][ry - 1] != 3 || map[bx][by - 1] != 3)
		{
			if (map[rx][ry - 1] != 3 && map[bx][by - 1] != 3)
			{
				serch(map, rx, ry - 1, bx, by - 1, cnt + 1);
			}
			if (map[rx][ry - 1] != 3 && map[bx][by - 1] == 3)
			{
				serch(map, rx, ry - 1, bx, by, cnt + 1);
			}
			if (map[rx][ry - 1] == 3 && map[bx][by - 1] != 3)
			{
				serch(map, rx, ry, bx, by - 1, cnt + 1);
			}
		}
	}

}



int main()
{

	freopen("input02.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int itr = 0; itr < tc; itr++)
	{
		maxcnt = 11;

		int ans=0;
		int map[25][25]={0};
		int row, col, cnt;

		int rx, ry, bx, by;
		cin >> row >> col;


		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
				{
					rx = i;
					ry = j;
				}
				if (map[i][j] == 2)
				{
					bx = i;
					by = j;
				}
			}
		}


		serch(map, rx, ry, bx, by, 0);
		
		if (maxcnt == 11)
			ans = -1;
		else
			ans = maxcnt;

		cout << "#" << itr + 1 << " " << ans << endl;
	}
}