#include <iostream>
using namespace std;

struct _node
{
	int x;
	int y;

	_node *next;

};

struct Queue
{
	int num;
	_node *front;
	_node *rear;

};

void enqueue(Queue *Qu, int x, int y)
{
	_node *NEW = new _node; 
	NEW->x = x;
	NEW->y = y;
	NEW->next = NULL;

	if (Qu->num == 0)
	{
		Qu->front = NEW;
		Qu->rear = NEW;

	}
	else
	{
		Qu->rear->next = NEW;
		Qu->rear = NEW;
	}
	Qu->num++;

}


int dequeue(Queue *Qu,int map[100][100],int size)
{
	_node *tmp;
	while (Qu->num != 0)
	{
		tmp = Qu->front;
		int x = tmp->x;
		int y = tmp->y;

		if (x == size - 1 && y == size - 1)
			return 1;

		int jump = map[x][y];

		if (x+jump<size)
		{
			enqueue(Qu, x+jump, y);
		}
		if (y+jump<size)
		{
			enqueue(Qu, x, y+jump);
		}
		Qu->front = Qu->front->next;
		Qu->num--;
		delete(tmp);
	}

	return 0;

}



int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		Queue *Que = new Queue;
		Que->num = 0;
		Que->front = NULL;
		Que->rear = NULL;

		int size, x, y, map[100][100] = { 0 };


		cin >> size;

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> map[i][j];

		enqueue(Que, 0, 0);		
		if (dequeue(Que, map, size))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;



	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}