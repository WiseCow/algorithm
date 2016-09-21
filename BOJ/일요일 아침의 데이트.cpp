
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int N, M,sx,sy,fx,fy;
char map[60][60];
int trash[60][60];
int neartrash[60][60];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct Data {
	int x, y, tr, netr;
};
bool chk(int x, int y)
{
	return x > 0 && x <= M&&y > 0 && y <= N;
}
bool findnear(int x, int y)
{
	bool is = 0;
	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];
		if (chk(mx,my))
		{
			if (map[my][mx] == 'g')
				is = 1;
		}

	}
	return is;
}
int main()
{
	scanf("%d %d ", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%s", &map[i][1]);

	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)
	{
		if (map[i][j] == 'F')
		{
			fx = j;
			fy = i;
		}
		if (map[i][j] == 'S')
		{
			sx = j;
			sy = i;
		}
	}
	queue<Data>q;
	memset(trash, 0x7f, sizeof(trash));
	memset(neartrash, 0x7f, sizeof(neartrash));
	q.push({ sx,sy,0,0 });
	while (q.size())
	{
		int x = q.front().x;
		int y = q.front().y;
		int tr = q.front().tr;
		int netr = q.front().netr;
		q.pop();

		if (trash[y][x] < tr)
			continue;
		if (trash[y][x] == tr)
		{
			if (neartrash[y][x] <= netr)
				continue;
		}

		trash[y][x] = tr;
		neartrash[y][x] = netr;


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (chk(nx, ny))
			{
				if (map[ny][nx] == '.')
				{
					int nextnear = findnear(nx, ny);
					if (trash[ny][nx] > tr)
					{
						q.push({ nx, ny, tr, netr + nextnear });
					}
					else if (trash[ny][nx] == tr&&neartrash[ny][nx] > netr + nextnear)
					{
						q.push({ nx, ny, tr, netr + nextnear });
					}

				}
				else if (map[ny][nx] == 'g') 
				{
					if (trash[ny][nx] > tr+1)
					{
						q.push({ nx, ny, tr+1, netr});
					}
					else if (trash[ny][nx] == tr + 1&&neartrash[ny][nx] > netr)
					{
						q.push({ nx, ny, tr + 1, netr });
					}
				}
				else
				{
					if (trash[ny][nx] > tr)
					{
						q.push({ nx, ny, tr, netr });
					}
					else if (trash[ny][nx] == tr && neartrash[ny][nx] > netr)
					{
						q.push({ nx, ny, tr, netr });
					}
				}
			}
		}
	}
	printf("%d %d", trash[fy][fx], neartrash[fy][fx]);
}


//#include<cstdio>
//#include<queue>
//#include<cstring>
//using namespace std;
//int dx[4] = { 0,1,0,-1 },dy[4] = { -1,0,1,0 },N, M, sx, sy, fx, fy, grag[51][51];
//struct Near {int x, y, tr, bytr;};
//bool chk(int x, int y){	return x > 0 && x <= M&&y > 0 && y <= N;}
//int main(){
//	scanf("%d %d", &N, &M);
//	char map[52][52];
//	for (int i = 1; i <= N; i++)	scanf("%s", &map[i][1]);
//	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)if (map[i][j] == 'S') { sx = j; sy = i; }	else if (map[i][j] == 'F') { fx = j; fy = i; }
//	memset(grag, 0x7f, sizeof(grag));
//	queue<pair<int, int>> q;
//	q.push({ sx,sy });
//	grag[sy][sx] = 0;
//	while (q.size()){
//		int x = q.front().first, y = q.front().second;
//		q.pop();
//		for (int i = 0; i < 4; i++){
//			int nx = x + dx[i], ny = y + dy[i];
//			if (chk(nx, ny)){
//				if (map[ny][nx] == 'g'){
//					if (grag[ny][nx]>grag[y][x] + 1){
//						grag[ny][nx] = grag[y][x] + 1;
//						q.push({ nx,ny });
//					}}
//				else{
//					if (grag[ny][nx] > grag[y][x]){
//						grag[ny][nx] = grag[y][x];
//						q.push({ nx,ny });
//					}}}}}
//	int near[51][51];
//	memset(near, 0x7f, sizeof(near));
//	near[sy][sx] = 0;
//	queue<Near> Q;
//	Q.push({ sx,sy,0,0 });
//	while (Q.size()){
//		int x = Q.front().x,y = Q.front().y, tr = Q.front().tr, bytr = Q.front().bytr;
//		Q.pop();
//		for (int i = 0; i < 4; i++){
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (chk(nx, ny)){
//				int nt = (tr + (map[ny][nx] == 'g' ? 1 : 0)), plus = 0;
//				if (nt != grag[ny][nx])continue;
//				for (int j = 0; j < 4; j++)
//					if (chk(nx + dx[j], ny + dy[j]))
//						plus += map[ny + dy[j]][nx + dx[j]] == 'g' ? 1 : 0;
//				if (plus > 1)
//					plus = 1;
//				if (map[ny][nx] == 'F' || map[ny][nx] == 'g')
//					plus = 0;
//				if (near[ny][nx]>near[y][x] + plus){
//					near[ny][nx] = near[y][x] + plus;
//					Q.push({ nx,ny,nt,near[y][x] + plus });
//				}}}}
//	printf("%d %d", grag[fy][fx], near[fy][fx]);
//}