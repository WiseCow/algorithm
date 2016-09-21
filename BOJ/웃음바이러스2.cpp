/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;

int max;
struct node
{
	int x;
	int y;
	int cnt;
	struct node *next;
};

struct Queue
{
	int num;
	struct node *front;
	struct node *rear;


};



void initialize(Queue *Qu)
{
	Qu->num = 0;
	Qu->front = NULL;
	Qu->rear = NULL;
}


void enqueue(Queue *Qu,int x, int y,int cnt)
{
	node *NEW = new node;
	NEW->x = x;
	NEW->y = y;
	NEW->cnt = cnt;
	NEW->next = NULL;
	if (Qu->num == 0)
	{
		Qu->front = NEW;
		Qu->rear = NEW;
		Qu->num++;
	}
	else
	{
		Qu->rear->next = NEW;
		Qu->rear = NEW;
		Qu->num++;
	}

}
void dequeue(Queue *Qu, int(*map)[100], int row, int col)
{
	while (Qu->num != 0)
	{
		int x, y,cnt;
		x = Qu->front->x;
		y = Qu->front->y;
		cnt = Qu->front->cnt;
		Qu->num--;
		node *tmp = Qu->front;
		Qu->front = Qu->front->next;

		if (map[x][y] == 1)
		{
			map[x][y] = cnt;
			max = cnt;
			if (x - 1 >= 0  && map[x - 1][y] == 1)
				enqueue(Qu, x - 1, y, cnt + 1);
			if (y + 1 < col && map[x][y + 1] == 1)
				enqueue(Qu, x, y + 1, cnt + 1);
			if (x + 1 < row && map[x + 1][y] == 1)
				enqueue(Qu, x + 1, y, cnt + 1);
			if (y - 1 >= 0 && map[x][y - 1] == 1)
				enqueue(Qu, x, y - 1, cnt + 1);
		}
		else
			continue;
	}
}


int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int map[100][100] = { 0 };
		int col, row;

		cin >> col >> row;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> map[i][j];
			}
		}

		int startx, starty;
		cin >> starty>>startx;
		Queue *Que = new Queue;

		initialize(Que);

		enqueue(Que, startx-1, starty-1, 2);
		max = 0;
		dequeue(Que, map, row, col);

		cout << max-1<<endl;
		

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}