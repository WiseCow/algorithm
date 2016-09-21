#include<iostream>
using namespace std;

typedef struct node
{
	int x;
	int y;
	int cnt;
	struct node *next;

}Node;
typedef struct queue
{
	int size;
	Node *front;
	Node *rear;
}Queue;


void push(Queue *Q, int x, int y, int cnt)
{
	Node *New = new Node;
	New->x = x;
	New->y = y;
	New->cnt = cnt;
	New->next = NULL;

	if (Q->size == 0)
	{
		Q->size++;
		Q->front = New;
		Q->rear = New;
	}
	else
	{
		Q->size++;
		Q->rear->next = New;
		Q->rear = New;
	}
}
void pop(Queue *Q, int *x, int *y, int *cnt)
{
	if (Q->size > 1)
	{
		Q->size--;
		Node *tmp = Q->front;
		Q->front = Q->front->next;
		*x = tmp->x;
		*y = tmp->y;
		*cnt = tmp->cnt;
		delete(tmp);

	}
	else if (Q->size == 1)
	{
		Q->size--;
		Node *tmp = Q->front;
		Q->front = NULL;
		Q->rear = NULL;
		*x = tmp->x;
		*y = tmp->y;
		*cnt = tmp->cnt;
		delete(tmp);
	}
	else
	{
		return;
	}
}


int main()
{
	int mapx, mapy;

	cin >> mapx >> mapy;
	char arr[100][100];

	for (int i = 0; i < mapx; i++)
	{
		cin >> arr[i];
	}
	Queue *fire = new Queue;
	fire->size = 0;
	fire->front = NULL;
	fire->rear = NULL;
	Queue *Kni = new Queue;
	Kni->size = 0;
	Kni->front = NULL;
	Kni->rear = NULL;
	int desX, desY;

	for (int i = 0; i < mapx; i++)
	for (int j = 0; j < mapy; j++)
	{
		if (arr[i][j] == '*')
		{
			push(fire, i, j, 0);
		}
		if (arr[i][j] = 'S')
			push(Kni, i, j, 0);
		if (arr[i][j] == 'D')
		{
			desX = i, desY = j;

		}
	}



	while (1)
	{
		int sin = 1;
		while (1)
		{
			int x, y, cnt;
			pop(fire, &x, &y, &cnt);
			if (cnt != sin)
				break;

			if (arr[x][y] != 'D' || arr[x][y] != 'W')
			{
				if (x - 1 >= 0)push(fire, x - 1, y, cnt + 1);
				if (x + 1 < mapx)push(fire, x + 1, y, cnt + 1);
				if (y - 1 >= 0)push(fire, x, y - 1, cnt + 1);
				if (y + 1 < mapy)push(fire, x, y + 1, cnt + 1);
			}

		}
		while (1)
		{

		}







	}













}