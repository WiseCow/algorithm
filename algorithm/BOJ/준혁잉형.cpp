//#include<iostream>
//using namespace std;
//int sizee;
//int map[21][21] = { 0 };
//int dmap[21][21] = { 0 };
//int dx[4] = { 0,1,-1,0 };
//int dy[4] = { 1,0,0,-1 };
//bool chk(int x, int y)
//{
//	if (x > 0 && x <= sizee&&y > 0 && y <= sizee)
//		return 1;
//	else
//		return 0;
//}
//void findd(int x, int y,int cntt)
//{
//	if (cntt == 999999)
//		cntt = 0;
//
//	if (dmap[x][y]<cntt||dmap[x][y]== 999999)
//	{
//		dmap[x][y] = cntt;
//		int dst = 4, maxx = 999999;
//		for (int i = 0; i < 4; i++)
//		{
//			if (chk(x + dx[i], y + dy[i]) && map[x][y]>map[x + dx[i]][y + dy[i]] && maxx>map[x + dx[i]][y + dy[i]])
//			{
//				maxx = map[x + dx[i]][y + dy[i]];
//				dst = i;
//			}
//		}
//		if (dst != 4)
//		{
//			findd(x+dx[dst], y+dy[dst], cntt + 1);
//		}
//	}
//}
//int main()
//{
//	int tc;
//	scanf("%d", &tc);
//	for (int itr = 0; itr < tc; itr++)
//	{
//		int max = 0, mx = 0, my = 0;
//		scanf("%d", &sizee);
//		for (int i = 1; i <= sizee; i++)
//			for (int j = 1; j <= sizee; j++)
//			{
//				scanf("%d", &map[i][j]);
//				dmap[i][j] = 999999;
//			}
//
//		for (int i = 1; i <= sizee; i++)
//			for (int j = 1; j <= sizee; j++)
//				findd(i, j,dmap[i][j]);
//
//		int maxxx = 0;
//		for (int i = 1; i <= sizee; i++)
//			for (int j = 1; j <= sizee; j++)
//			{
//				if (maxxx < dmap[i][j])
//					maxxx = dmap[i][j];
//			}
//		printf("#%d %d\n",itr+1, maxxx+1);
//	}
//	return 0;
//}

//#include<iostream>
//char map[10][10];
//int cnt;
//int sd, fd, sx, sy, fx, fy;
//void find()
//{
//
//}
//int main()
//{
//	int tc;
//	scanf("%d", &tc);
//	for (int itr = 0; itr < tc; itr++)
//	{
//		int N, M,x,y;
//		scanf("%d %d %d %d", &N, &M,&x, &y);
//		for (int i = 1; i <= N; i++)
//		{
//			scanf("%s", &map[i][1]);
//		}
//		cnt = 0;
//		if (x <= M)
//		{
//			sd = 1;
//			sx = x;
//			sy = 1;
//		}
//		else if (x <= M + N)
//		{
//			sd = 2;
//			sx = 1;
//			sy = x - M;
//		}
//		else if (x <= M + 2 * N)
//		{
//			sd = 3;
//			sx = M;
//			sy = x - M - M;
//		}
//		else
//		{
//			sd = 4;
//			sx = x - M - N - N;
//			sy = N;
//		}
//		if (y <= M)
//		{
//			fd = 1;
//			fx = y;
//			fy = 1;
//		}
//		else if (y <= M + N)
//		{
//			fd = 2;
//			fx = 1;
//			fy = y - M;
//		}
//		else if (y <= M + 2 * N)
//		{
//			fd = 3;
//			fx = M;
//			fy = y - M - M;
//		}
//		else
//		{
//			fd = 4;
//			fx = y - M - N - N;
//			fy = N;
//		}
//
//
//
//
//		cnt = 0;
//		find(sx,sy);
//
//		printf("%d\n", cnt);
//
//
//
//	}
//}
#include<iostream>
#include<vector>
using namespace std;
int abs(int x)
{
	return x > 0 ? x : -x;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	for (int itr = 0; itr < tc; itr++)
	{
		int r, c;
		char input[55];
		vector<pair<int, int>> alpha[37];
		scanf("%d %d", &r, &c);

		for (int i = 1; i <= r; i++)
		{
			scanf("%s", &input);
			for (int j = 0; j < c; j++)
			{
				if (input[j] == '*')
					alpha[0].push_back({ i, j + 1 });
				else if(input[j]>='A'&&input[j]<='Z')
					alpha[input[j]-'A' + 1].push_back({ i, j + 1 });
				else if(input[j]=='-')
					alpha[27].push_back({ i, j + 1 });
				else
					alpha[27+input[j]-'0'].push_back({ i, j + 1 });
			}
		}

		char inputtxt[10001] = { 0 };
		scanf("%s", &inputtxt);
		vector<pair<int, pair<int, int>>> now1;
		vector<pair<int, pair<int, int>>> now2;
		now1.push_back({ 0, {1, 1} });
		int np = 0;
		for (; inputtxt[np] != 0; np++)
		{
			char nchar = inputtxt[np];
			int nint;
			if (nchar == '*')
				nint = 0;
			else if (nchar >= 'A'&&nchar <= 'Z')
				nint = nchar - 'A' + 1;
			else if (nchar == '-')
				nint = 27;
			else
				nint = 27 + nchar - '0';
			if (np % 2 == 0)
			{
				now2.clear();
				for (int j = 0; j < alpha[nint].size(); j++)
				{
					int kx = alpha[nint][j].first, ky = alpha[nint][j].second;
					int costmin = 99999999999;

					for (int i = 0; i < now1.size(); i++)
					{
						int x = now1[i].second.first, y = now1[i].second.second;
						int cost = now1[i].first+1;
						if (costmin > cost + abs(kx - x) + abs(ky - y))
						{
							costmin = cost + abs(kx - x) + abs(ky - y);
						}
					}
					now2.push_back({ costmin,{kx,ky} });
				}

			}
			else
			{
				now1.clear();
				for (int j = 0; j < alpha[nint].size(); j++)
				{
					int kx = alpha[nint][j].first, ky = alpha[nint][j].second;
					int costmin = 99999999999;

					for (int i = 0; i < now2.size(); i++)
					{
						int x = now2[i].second.first, y = now2[i].second.second;
						int cost = now2[i].first + 1;
						if (costmin > cost + abs(kx - x) + abs(ky - y))
						{
							costmin = cost + abs(kx - x) + abs(ky - y);
						}
					}
					now1.push_back({ costmin,{ kx,ky } });
				}
			}
		}
		if (np % 2 == 0)
		{
			now2.clear();
			int minn = 99999999999;
			for (int j = 0; j < alpha[0].size(); j++)
			{
				int kx = alpha[0][j].first, ky = alpha[0][j].second;
				int costmin = 99999999999;

				for (int i = 0; i < now1.size(); i++)
				{
					int x = now1[i].second.first, y = now1[i].second.second;
					int cost = now1[i].first + 1;
					if (costmin > cost + abs(kx - x) + abs(ky - y))
					{
						costmin = cost + abs(kx - x) + abs(ky - y);
					}
				}
				now2.push_back({ costmin,{ kx,ky } });
				if (costmin < minn)
					minn = costmin;
			}
			printf("%d\n", minn);
		}
		else
		{
			now1.clear();
			int minn = 99999999999;
			for (int j = 0; j < alpha[0].size(); j++)
			{
				int kx = alpha[0][j].first, ky = alpha[0][j].second;
				int costmin = 99999999999;

				for (int i = 0; i < now2.size(); i++)
				{
					int x = now2[i].second.first, y = now2[i].second.second;
					int cost = now2[i].first + 1;
					if (costmin > cost + abs(kx - x) + abs(ky - y))
					{
						costmin = cost + abs(kx - x) + abs(ky - y);
					}
				}
				now1.push_back({ costmin,{ kx,ky } });
				if (costmin < minn)
					minn = costmin;
			}
			printf("%d\n", minn);
		}

	}



}