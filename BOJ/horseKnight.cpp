#include <iostream>
using namespace std;
int map[1024][1024];
int horse[1024][1024];
int knight[1024][1024];
int mapsize;
struct Node
{
	int x;
	int y;
	int cnt;
	Node *next;

};
struct Queue
{
	int size;
	Node *front;
	Node *rear;
};

Queue *createQ(void)
{
	Queue *New = new Queue;
	New->size = 0;
	New->front = NULL;
	New->rear = NULL;
	return New;
}
void enqueue(Queue *Q, int x, int y, int cnt)
{
	Node *New = new Node;
	New->x = x;
	New->y = y;
	New->cnt = cnt;
	New->next = NULL;
	if (Q->size == 0)
	{
		Q->front = New;
		Q->rear = New;
	}
	else
	{
		Q->rear->next = New;
		Q->rear = New;
	}
	Q->size++;
}

void H_dequeue(Queue *Q, int(*map)[1024], int(*holse)[1024])
{
	int x, y, cnt;

	if (Q->size == 1)
	{
		Node *tmp = Q->front;
		x = tmp->x;
		y = tmp->y;
		cnt = tmp->cnt;
		Q->front = NULL;
		Q->rear = NULL;
		delete tmp;
	}
	else
	{
		Node *tmp = Q->front;
		x = tmp->x;
		y = tmp->y;
		cnt = tmp->cnt;
		Q->front = Q->front->next;
		delete tmp;
	}
	Q->size--;

	if (map[x][y] != 1 && holse[x][y] == 0)
	{
		holse[x][y] = cnt;

		if (x - 1 >= 0 && map[x - 1][y] == 0)
		{
			if (x - 2 >= 0 && y - 1 >= 0 && map[x - 2][y - 1] == 0 && holse[x - 2][y - 1] == 0)enqueue(Q, x - 2, y - 1, cnt + 1);
			if (x - 2 >= 0 && y + 1 < mapsize && map[x - 2][y + 1] == 0 && holse[x - 2][y + 1] == 0)enqueue(Q, x - 2, y + 1, cnt + 1);
		}
		if (x + 1 < mapsize && map[x + 1][y] == 0)
		{

			if (x + 2 < mapsize && y - 1 >= 0 && map[x + 2][y - 1] == 0 && holse[x + 2][y - 1] == 0)enqueue(Q, x + 2, y - 1, cnt + 1);
			if (x + 2 < mapsize && y + 1 < mapsize && map[x + 2][y + 1] == 0 && holse[x + 2][y + 1] == 0)enqueue(Q, x + 2, y + 1, cnt + 1);
		}
		if (y - 1 >= 0 && map[x][y - 1] == 0)
		{

			if (y - 2 >= 0 && x - 1 >= 0 && map[x - 1][y - 2] == 0 && holse[x - 1][y - 2] == 0)enqueue(Q, x - 1, y - 2, cnt + 1);
			if (y - 2 >= 0 && x + 1 < mapsize && map[x + 1][y - 2] == 0 && holse[x + 1][y - 2] == 0)enqueue(Q, x + 1, y - 2, cnt + 1);
		}
		if (y + 1 < mapsize && map[x][y + 1] == 0)
		{

			if (y + 2 < mapsize && x - 1 >= 0 && map[x - 1][y + 2] == 0 && holse[x - 1][y + 2] == 0)enqueue(Q, x - 1, y + 2, cnt + 1);
			if (y + 2 < mapsize && x + 1 < mapsize && map[x + 1][y + 2] == 0 && holse[x + 1][y + 2] == 0)enqueue(Q, x + 1, y + 2, cnt + 1);
		}
	}
}
void K_dequeue(Queue *Q, int(*map)[1024], int(*Knight)[1024])
{
	int x, y, cnt;

	if (Q->size == 1)
	{
		Node *tmp = Q->front;
		x = tmp->x;
		y = tmp->y;
		cnt = tmp->cnt;
		Q->front = NULL;
		Q->rear = NULL;
		delete tmp;
	}
	else
	{
		Node *tmp = Q->front;
		x = tmp->x;
		y = tmp->y;
		cnt = tmp->cnt;
		Q->front = Q->front->next;
		delete tmp;
	}
	Q->size--;

	if (map[x][y] != 1 && Knight[x][y] == 0)
	{
		Knight[x][y] = cnt;
		if (x - 2 >= 0 && y - 1 >= 0 && map[x - 2][y - 1] == 0 && Knight[x - 2][y - 1] == 0)enqueue(Q, x - 2, y - 1, cnt + 1);
		if (x - 2 >= 0 && y + 1 < mapsize && map[x - 2][y + 1] == 0 && Knight[x - 2][y + 1] == 0)enqueue(Q, x - 2, y + 1, cnt + 1);
		if (x + 2 < mapsize && y - 1 >= 0 && map[x + 2][y - 1] == 0 && Knight[x + 2][y - 1] == 0)enqueue(Q, x + 2, y - 1, cnt + 1);
		if (x + 2 < mapsize && y + 1 < mapsize && map[x + 2][y + 1] == 0 && Knight[x + 2][y + 1] == 0)enqueue(Q, x + 2, y + 1, cnt + 1);
		if (y - 2 >= 0 && x - 1 >= 0 && map[x - 1][y - 2] == 0 && Knight[x - 1][y - 2] == 0)enqueue(Q, x - 1, y - 2, cnt + 1);
		if (y - 2 >= 0 && x + 1 < mapsize && map[x + 1][y - 2] == 0 && Knight[x + 1][y - 2] == 0)enqueue(Q, x + 1, y - 2, cnt + 1);
		if (y + 2 < mapsize && x - 1 >= 0 && map[x - 1][y + 2] == 0 && Knight[x - 1][y + 2] == 0)enqueue(Q, x - 1, y + 2, cnt + 1);
		if (y + 2 < mapsize && x + 1 < mapsize && map[x + 1][y + 2] == 0 && Knight[x + 1][y + 2] == 0)enqueue(Q, x + 1, y + 2, cnt + 1);
	}
}


int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int m, dis;
		cin >> m >> dis;
		mapsize = m;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				horse[i][j] = 0;
				knight[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
		int x_s, y_s;
		cin >> x_s >> y_s;
		Queue *Q = createQ();
		enqueue(Q, x_s - 1, y_s - 1, 1);
		while (Q->size != 0)
		{
			H_dequeue(Q, map, horse);
		}
		enqueue(Q, x_s - 1, y_s - 1, 1);
		while (Q->size != 0)
		{
			K_dequeue(Q, map, knight);
		}
		int chk = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (knight[i][j] < horse[i][j] || (knight[i][j] != 0 && horse[i][j] == 0))
					chk++;
			}
		}
		cout << chk << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}