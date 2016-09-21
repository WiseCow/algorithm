#include<iostream>
#include<queue>
using namespace std;


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


struct node
{
	int x, y, cnt,dist;
	node() {}
	node(int a, int b, int c,int d) {
		x = a; y = b; cnt = c; dist = d;
	}
};

bool chk(int x, int y, int N, int M)
{
	return x > 0 && y > 0 && x <= M&&y <= N;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		char map[12][12];
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
			scanf("%s", &map[i][1]);

		int sx=0, sy=0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (sx == 0 && sy == 0 && map[i][j] == 'O')
				{
					sx = j;
					sy = i;
				}
		queue<node> q;
		q.push(node(sx, sy, 0,4));
		char bmap[12][12] = { 0 };
		int sizemap[12][12];
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
			{
				sizemap[i][j] = 987654321;
				bmap[i][j] = 100;
			}
		int mx = 0;
		while (q.size())
		{
			node tmp = q.front();
			q.pop();
			int x = tmp.x;
			int y = tmp.y;
			int cnt = tmp.cnt;
			int dist = tmp.dist;
			if (sizemap[y][x] > cnt)
			{
				if (mx < cnt)
					mx = cnt;
				sizemap[y][x] = cnt;
				bmap[y][x] = dist;
				for (int i = 0; i < 4; i++)
					if (chk(x + dx[i], y + dy[i], N, M) && map[y + dy[i]][x + dx[i]] == '.'&&sizemap[y+dy[i]][x + dx[i]]>cnt+1)
						q.push(node(x + dx[i], y + dy[i], cnt + 1, i));
			}
		}
		if (mx > 10)
			printf("XHAE\n");
		else
		{
			bool chk = 0;
			int arr[10] = { 0 };
			for (int i = 1; i <= 10; i++)
				for (int j = 1; j <= 10; j++)
					if (map[i][j] == '.')
					{
						if (sizemap[i][j] == 987654321)
							chk = 1;
						if (bmap[i][j] != 100)
							arr[bmap[i][j]]++;
					}

			if (!chk)
			{
				if (arr[1])printf("L");
				if (arr[0])printf("U");
				if (arr[3])printf("R");
				if (arr[2])printf("D");

				printf("\n");
			}
			else
			{
				printf("XHAE\n");
			}




		}


	}



}