#include <iostream>
using namespace std;


int _maxx;
struct _node
{
	int x;
	int y;
	int cnt;
	_node *next;
};

struct Queue
{
	int num;
	_node *front;
	_node *rear;
};


void enqueue(Queue *Qu, int x, int y, int cnt)
{
	_node *New = new _node;
	New->x = x;
	New->y = y;
	New->cnt = cnt;
	New->next = NULL;

	if (Qu->num == 0)
	{
		Qu->front = New;
		Qu->rear = New;

	}
	else
	{
		Qu->rear->next = New;
		Qu->rear = New;

	}
	Qu->num++;

}


void dequeue(Queue *Qu, int x_size, int y_size, int map[100][100])
{


	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	while (Qu->num != 0)
	{
		_node *tmp = Qu->front;
		int x = tmp->x;
		int y = tmp->y;
		int cnt = tmp->cnt;

		if (map[x][y] > cnt)
		{
			map[x][y] = cnt;
			if (_maxx < cnt)
				_maxx = cnt;
			for (int i = 0; i < 4; i++)
			{
				if (x + dx[i] >= 0 && x + dx[i] < x_size&&y + dy[i] >= 0 && y + dy[i]<y_size&&map[x + dx[i]][y + dy[i]]>cnt + 1)
					enqueue(Qu, x + dx[i], y + dy[i], cnt + 1);

			}
		}
		Qu->front = Qu->front->next;
		Qu->num--;

		delete tmp;

	}



}


int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int x_size, y_size;
		cin >> y_size >> x_size;

		int map[100][100] = { 0 };


		for (int r = 0;r<x_size;r++)
			for (int c = 0; c < y_size; c++)
			{
				cin >> map[r][c];
				if (map[r][c] == 0)
				{
					map[r][c] = -1;
				}
				else if (map[r][c] == 1)
				{
					map[r][c] = 99999;
				}
			}

		int x, y;
		cin >> y >> x;
		

		Queue *Qu = new Queue;
		Qu->num = 0;
		Qu->front = NULL;
		Qu->rear = NULL;
		_maxx = 0;
		enqueue(Qu, x-1, y-1, 1);

		dequeue(Qu, x_size, y_size, map);

		cout << _maxx << endl;


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}