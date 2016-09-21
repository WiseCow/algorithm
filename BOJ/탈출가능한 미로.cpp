#include <iostream>
using namespace std;
int x_max, y_max;
struct Node
{
	int x, y;
	int cnt;
	Node *next;
};
struct Queue
{
	int size;
	Node *front;
	Node *rear;
};
Queue *create()
{
	Queue *Q = new Queue;
	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;
	return Q;
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
void dequeue(Queue *Q, char(*arr)[101], int(*chk)[101])
{
	int x, y, cnt;
	if (Q->size == 1)
	{
		Node *tmp = Q->front;
		Q->front = NULL;
		Q->rear = NULL;
		x = tmp->x;
		y = tmp->y;
		cnt = tmp->cnt;
		delete tmp;
	}
	else
	{
		Node *tmp = Q->front;
		Q->front = Q->front->next;
		x = tmp->x;
		y = tmp->y;
		cnt = tmp->cnt;
		delete tmp;
	}
	Q->size--;
	if (arr[x][y] != '1'&&chk[x][y] == 0)
	{
		chk[x][y] = cnt;
		if (x - 1 >= 0 && arr[x - 1][y] == '0'&&chk[x - 1][y] == 0)enqueue(Q, x - 1, y, cnt + 1);
		if (x + 1 <x_max && arr[x + 1][y] == '0'&&chk[x + 1][y] == 0)enqueue(Q, x + 1, y, cnt + 1);
		if (y - 1 >= 0 && arr[x][y-1] == '0'&&chk[x][y-1] == 0)enqueue(Q, x, y-1, cnt + 1);
		if (y + 1 < y_max&& arr[x][y + 1] == '0'&&chk[x][y + 1] == 0)enqueue(Q, x, y + 1, cnt + 1);
		
		
		if (x - 1 >= 0 && y - 1 >= 0 && arr[x - 1][y - 1] == '0'&&chk[x - 1][y - 1] == 0)enqueue(Q, x - 1, y - 1, cnt + 1);
		if (x + 1 < x_max && y + 1 < y_max &&arr[x + 1][y + 1] == '0'&&chk[x + 1][y + 1] == 0)enqueue(Q, x + 1, y + 1, cnt + 1);
		if (y - 1 >= 0 && x + 1 < x_max&&arr[x + 1][y - 1] == '0'&&chk[x + 1][y - 1] == 0)enqueue(Q, x + 1, y - 1, cnt + 1);
		if (y + 1 < y_max && x - 1 >= 0 && arr[x - 1][y + 1] == '0'&&chk[x - 1][y + 1] == 0)enqueue(Q, x - 1, y + 1, cnt + 1);

	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		Queue *Q = create();

		int x, y;
		cin >> x >> y;
		x_max = x;
		y_max = y;
		char arr[101][101] = { 0 };
		for (int i = 0; i < x; i++)
		{
			cin >> arr[i];
		}
		int chk[101][101] = { 0 };
		enqueue(Q, 0, 0, 1);

		while (Q->size != 0)
		{
			dequeue(Q, arr, chk);
		}
		if (chk[x - 1][y - 1] == 0)
			cout << 0 << endl;
		else
			cout << 1 << endl;


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}