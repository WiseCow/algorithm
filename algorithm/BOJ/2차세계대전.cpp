//#include<iostream>
//#include<queue>
//#define INF 987654321
//int tc, N;
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//
//using namespace std;
//struct Edge { int x, y, cost; };
//queue <Edge> q;
//bool chk(int x, int y)
//{
//	return x > 0 && x <= N&& y > 0 && y <= N;
//}
//int main()
//{
//
//	scanf("%d", &tc);
//
//	for (int itr = 0; itr < tc; itr++)
//	{
//		scanf("%d", &N);
//		int res = 0;
//
//		char map[102][102];
//
//		int repair[102][102] = { 0 };
//		for (int i = 1; i <= N; i++)
//		{
//			map[i][0] = 32;
//			scanf("%s", &map[i][1]);
//			for (int j = 1; j <= N; j++)
//				repair[i][j] = INF;
//		}
//		repair[1][1] = 0;
//		for (int i = 0; i < 4; i++)
//		{
//			if (chk(1 + dx[i], 1 + dy[i]))
//			{
//				if (repair[1 + dx[i]][1 + dy[i]]>1 + (map[1 + dx[i]][1 + dy[i]] - 48) * 10000)
//				{
//					q.push({ 1 + dx[i], 1 + dy[i], 1 + (map[1 + dx[i]][1 + dy[i]] - 48) * 10000 });
//				}
//			}
//		}
//
//
//
//		while (q.size())
//		{
//			int x = q.front().x;
//			int y = q.front().y;
//			int cost = q.front().cost;
//			q.pop();
//
//			if (cost < repair[x][y])
//			{
//				repair[x][y] = cost;
//				for (int i = 0; i < 4; i++)
//				{
//					if (chk(x + dx[i], y + dy[i]))
//					{
//						if (repair[x + dx[i]][y + dy[i]]>cost + 1 + (map[x + dx[i]][y + dy[i]] - 48) * 10000)
//						{
//							q.push({ x + dx[i], y + dy[i], cost + 1 + (map[x + dx[i]][y + dy[i]] - 48) * 10000 });
//						}
//					}
//				}
//			}
//		}
//		res = repair[N][N] / 10000;
//
//
//		printf("#%d %d\n", itr + 1, res);
//
//	}
//
//}
//
//#include<iostream>
//#include<queue>
//#define INF 987654321
//int tc, N;
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//int map[102][102];
//
//using namespace std;
//struct Edge { int x, y; };
//queue <Edge> q;
//bool chk(int x, int y)
//{
//	return x > 0 && x <= N&& y > 0 && y <= N;
//}
//int main()
//{
//
//	scanf("%d", &tc);
//
//	for (int itr = 0; itr < tc; itr++)
//	{
//		scanf("%d", &N);
//		int res = 0;
//
//		char map[102][102];
//
//		int repair[102][102] = { 0 };
//		for (int i = 1; i <= N; i++)
//		{
//			for (int j = 1; j <= N; j++)
//			{
//				scanf("%1d", &map[i][j]);
//				repair[i][j] = INF;
//			}
//		}
//		queue<Edge>q;
//		q.push({ 1, 1 });
//		repair[1][1] = 0;
//		while (q.size())
//		{
//			int x = q.front().x;
//			int y = q.front().y;
//			q.pop();
//
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = x + dx[i];
//				int ny = y + dy[i];
//				if (chk(nx, ny))
//				{
//					if (repair[x + dx[i]][y + dy[i]] > map[x + dx[i]][y + dy[i]] + repair[x][y])
//					{
//						repair[nx][ny] = map[nx][ny] + repair[x][y];
//						q.push({nx,ny});
//					}
//				}
//			}
//		}
//
//		res = repair[N][N];
//
//		printf("#%d %d\n", itr+1, res);
//	}
//	return 0;
//}


/*
2주차 평가 1번문제
제목 : 보급로
분류 : 2차원 선형구조 (가중치 -> 다익스트라 활용)
*/
//
//#include <iostream>
//#include <cstdio>
//#include <queue>
//#pragma warning (disable:4996)
//using namespace std;
//
//typedef struct data { int y, x, cnt; }Data;      //너비우선탐색시 큐에 들어갈 데이터
//bool operator<(Data d1, Data d2) { return d1.cnt > d2.cnt; }   //우선순위 큐에서 우선순위 재정의
//
//char map[100][100];                  //입력값을 받을 2차원 배열 
//int resultMap[100][100];               //결과 값을 저장할 2차원 배열
//int arrX[4] = { 0, 1, 0, -1 };               //상하좌우 이동 시 필요한 X좌표
//int arrY[4] = { -1, 0, 1, 0 };               //상하좌우 이동 시 필요한 Y좌표
//int N;
//
///* 지정된 2차원 배열 밖을 벗어나는지 판별해주는 함수 */
//bool RangeMap(int y, int x)
//{
//	if (y > N - 1 || x > N - 1 || y < 0 || x < 0)   //지정된 2차원 배열 범위가 벗어난다면?
//		return false;
//	else
//		return true;
//}
//
///* 너비우선 탐색(우선순위 큐활용) -> 도착지점까지의 최소 가중치 비용 탐색 */
//int BFS()
//{
//	Data startData = { 0,0,0 };      //시작 지점 지정
//
//	priority_queue<Data> q;      //우선순위 큐선언
//	q.push(startData);         //시작지점 큐에 삽입
//
//	resultMap[startData.y][startData.x] = startData.cnt;      //시작지점 결과 배열에 체크
//
//	int result = 1987654321;
//	while (!q.empty())
//	{
//		Data outData = q.top();
//		q.pop();
//
//		/* 골인 지점에 제일 먼저 도착한 가중치 값이 결국 최소비용 */
//		if (outData.x == N - 1 && outData.y == N - 1)
//		{
//			return outData.cnt;
//		}
//
//		/* 현재 좌표에서 갈수 있는 4방향 탐색 */
//		for (int i = 0; i < 4; i++)
//		{
//			Data inData = { outData.y + arrY[i], outData.x + arrX[i], outData.cnt };      //다음 좌표로 진행될 데이터
//
//																						  /* 다음으로 진행할 좌표가 지정된 배열 범위를 넘어가는가? */
//			if (RangeMap(inData.y, inData.x))
//			{
//				/* 결과값을 저장한 맵에서 다음 진행될 좌표까지의 가중치가 더 최소라면 바꿔준다  */
//				if (resultMap[inData.y][inData.x] > inData.cnt + (map[inData.y][inData.x] - 48))
//				{
//					inData.cnt += (map[inData.y][inData.x] - 48);      //다음으로 진행될 좌표의 최소가중치
//					resultMap[inData.y][inData.x] = inData.cnt;      //결과값 저장된 맵에 결과 대입
//					q.push(inData);               //다음 진행될 좌표 우선순위큐에 삽입
//				}
//
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	freopen("sample_input.txt", "r", stdin);
//
//	int testCase;
//	cin >> testCase;
//	for (int i = 0; i < testCase; i++)
//	{
//		cin >> N;
//
//		/* 결과를 담을 2차원 맵 가장 큰값으로 초기화 */
//		for (int j = 0; j < N; j++)
//			for (int k = 0; k < N; k++)
//				resultMap[j][k] = 1987654321;
//
//		for (int j = 0; j < N; j++)
//			for (int k = 0; k < N; k++)
//				cin >> map[j][k];
//
//		cout << "#" << i + 1 << " ";
//		cout << BFS() << endl;
//
//	}
//
//	return 0;
//}


#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int map[102][102],repair[102][102];
int tc,N;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct Node {
	int x, y, cost;
};
bool operator <(Node a, Node b) {
	return a.cost > b.cost;
}


bool check(int x, int y)
{
	return x > 0 && x <= N && y > 0 && y <= N;
}
int bfs()
{
	priority_queue <Node> q;
	q.push({ 1,1,0 });
	repair[1][1] = 0;
	while (q.size())
	{
		Node tmp = q.top();
		q.pop();

		if (tmp.x == N&& tmp.y == N)
			return tmp.cost;

		int x = tmp.x;
		int y = tmp.y;
		int cost = tmp.cost;
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (check(nx, ny))
			{
				if (repair[nx][ny]>cost+map[nx][ny])
				{
					repair[nx][ny] = cost + map[nx][ny];
					q.push({ nx,ny,cost + map[nx][ny]});
				}
			}
		}
	}
}


int main()
{
	scanf("%d", &tc);

	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%1d", &map[i][j]);
		memset(repair, 0x7f, sizeof(repair));
		int res = bfs();

		printf("#%d %d\n", itr+1, res);
	}
}