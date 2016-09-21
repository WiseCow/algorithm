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
2���� �� 1������
���� : ���޷�
�з� : 2���� �������� (����ġ -> ���ͽ�Ʈ�� Ȱ��)
*/
//
//#include <iostream>
//#include <cstdio>
//#include <queue>
//#pragma warning (disable:4996)
//using namespace std;
//
//typedef struct data { int y, x, cnt; }Data;      //�ʺ�켱Ž���� ť�� �� ������
//bool operator<(Data d1, Data d2) { return d1.cnt > d2.cnt; }   //�켱���� ť���� �켱���� ������
//
//char map[100][100];                  //�Է°��� ���� 2���� �迭 
//int resultMap[100][100];               //��� ���� ������ 2���� �迭
//int arrX[4] = { 0, 1, 0, -1 };               //�����¿� �̵� �� �ʿ��� X��ǥ
//int arrY[4] = { -1, 0, 1, 0 };               //�����¿� �̵� �� �ʿ��� Y��ǥ
//int N;
//
///* ������ 2���� �迭 ���� ������� �Ǻ����ִ� �Լ� */
//bool RangeMap(int y, int x)
//{
//	if (y > N - 1 || x > N - 1 || y < 0 || x < 0)   //������ 2���� �迭 ������ ����ٸ�?
//		return false;
//	else
//		return true;
//}
//
///* �ʺ�켱 Ž��(�켱���� ťȰ��) -> �������������� �ּ� ����ġ ��� Ž�� */
//int BFS()
//{
//	Data startData = { 0,0,0 };      //���� ���� ����
//
//	priority_queue<Data> q;      //�켱���� ť����
//	q.push(startData);         //�������� ť�� ����
//
//	resultMap[startData.y][startData.x] = startData.cnt;      //�������� ��� �迭�� üũ
//
//	int result = 1987654321;
//	while (!q.empty())
//	{
//		Data outData = q.top();
//		q.pop();
//
//		/* ���� ������ ���� ���� ������ ����ġ ���� �ᱹ �ּҺ�� */
//		if (outData.x == N - 1 && outData.y == N - 1)
//		{
//			return outData.cnt;
//		}
//
//		/* ���� ��ǥ���� ���� �ִ� 4���� Ž�� */
//		for (int i = 0; i < 4; i++)
//		{
//			Data inData = { outData.y + arrY[i], outData.x + arrX[i], outData.cnt };      //���� ��ǥ�� ����� ������
//
//																						  /* �������� ������ ��ǥ�� ������ �迭 ������ �Ѿ�°�? */
//			if (RangeMap(inData.y, inData.x))
//			{
//				/* ������� ������ �ʿ��� ���� ����� ��ǥ������ ����ġ�� �� �ּҶ�� �ٲ��ش�  */
//				if (resultMap[inData.y][inData.x] > inData.cnt + (map[inData.y][inData.x] - 48))
//				{
//					inData.cnt += (map[inData.y][inData.x] - 48);      //�������� ����� ��ǥ�� �ּҰ���ġ
//					resultMap[inData.y][inData.x] = inData.cnt;      //����� ����� �ʿ� ��� ����
//					q.push(inData);               //���� ����� ��ǥ �켱����ť�� ����
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
//		/* ����� ���� 2���� �� ���� ū������ �ʱ�ȭ */
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