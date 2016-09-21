//#include<iostream>
//#include<queue>
//using namespace std;
//char arr[33][33];
//int dan[33][33];
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//
//int N;
//struct node
//{
//	int x, y, now;
//	node(int a, int b, int c) {
//		x = a; y = b; now = c;
//	}
//};
//bool chk(int x, int y){return x > 0 && y > 0 && x <= N&&y <= N;}
//int main()
//{
//	scanf("%d", &N);
//	int idx = 1;
//	for (int i = 1; i <= N; i++)
//			scanf("%s", &arr[i][1]);
//
//	queue<node> q;
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			if (arr[i][j] == '1' && dan[i][j] == 0)
//			{
//				q.push(node(j, i, idx++));
//				while (q.size())
//				{
//					node tmp = q.front();
//					q.pop();
//					int x = tmp.x;
//					int y = tmp.y;
//					int idx1 = tmp.now;
//					if (dan[y][x] == 0)
//					{
//						dan[y][x] = idx1;
//						for (int i = 0; i < 4; i++)
//						{
//							if (chk(x + dx[i], y + dy[i]) &&arr[y + dy[i]][x + dx[i]]=='1'&& !dan[y + dy[i]][x + dx[i]])
//								q.push(node(x + dx[i], y + dy[i], idx1));
//						}
//					}
//				}
//			}
//
//	int in[400] = { 0 };
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			if (dan[i][j])
//				in[dan[i][j]]++;
//	printf("%d\n", idx-1); 
//	priority_queue<int>qq;
//	for (int i = 1; i < idx; i++)
//		qq.push(-in[i]);
//	while (qq.size())
//	{
//		printf("%d\n", -qq.top());
//		qq.pop();
//	}
//
//
//	return 0;
//}
#include <stdio.h>
int N;
int arr[26][26]; // 집 위치
int visit[26][26]; // 방문 여부
int queue[2][626];
int head, tail;
int count[626]; // 단지별 세대 수
int numberOfDanji; // 전체 단지 수

void enQueue(int x, int y);
void deQueue();
void bfs(int x, int y);

int main(void)
{
	int x, y;
	int temp;

	scanf("%d", &N);
	for (x = 1; x <= N; x++)
	{
		for (y = 1; y <= N; y++)
		{
			scanf("%d", &arr[x][y]);
		}
	}

	for (x = 1; x <= N; x++)
	{
		for (y = 1; y <= N; y++)
		{
			if (visit[x][y] == 0 && arr[x][y] == 1)
			{
				bfs(x, y);
				numberOfDanji++;
			}
		}
	}
	// 버블소트
	for (x = 1; x < numberOfDanji; x++)
	{
		for (y = 1; y <= numberOfDanji - x; y++)
		{
			if (count[y] > count[y + 1])
			{
				temp = count[y];
				count[y] = count[y + 1];
				count[y + 1] = temp;
			}
		}
	}
	printf("%d\n", numberOfDanji);
	for (x = 1; x <= numberOfDanji; x++)
		printf("%d\n", count[x]);
}

void enQueue(int x, int y)
{
	if (tail > 626)
	{
		return;
	}

	queue[0][tail] = x;
	queue[1][tail] = y;
	tail++;
}

void deQueue()
{
	count[numberOfDanji + 1]++; // 단지 내 세대 수 셈
	if (head == tail)
	{
		return;
	}

	head++;
}

void bfs(int x, int y)
{
	int up = x - 1;
	int down = x + 1;
	int left = y - 1;
	int right = y + 1;

	int tempX, tempY;

	// 큐에 노드 넣기
	visit[x][y] = 1;
	enQueue(x, y);

	while (tail != head)
	{
		tempX = queue[0][head];
		tempY = queue[1][head];

		up = tempX - 1;
		down = tempX + 1;
		left = tempY - 1;
		right = tempY + 1;

		if ((tempX >= 1 && tempX <= N) && (tempY >= 1 && tempY <= N))
		{
			deQueue();

			// 위쪽 노드 검사
			if (visit[up][tempY] == 0 && arr[up][tempY] == 1)
			{
				visit[up][tempY] = 1;
				enQueue(up, tempY);
			}
			// 아래쪽 노드 검사
			if (visit[down][tempY] == 0 && arr[down][tempY] == 1)
			{
				visit[down][tempY] = 1;
				enQueue(down, tempY);
			}
			// 왼쪽 노드 검사
			if (visit[tempX][left] == 0 && arr[tempX][left] == 1)
			{
				visit[tempX][left] = 1;
				enQueue(tempX, left);
			}
			// 오른쪽 노드 검사
			if (visit[tempX][right] == 0 && arr[tempX][right] == 1)
			{
				visit[tempX][right] = 1;
				enQueue(tempX, right);
			}
		}
	}
}