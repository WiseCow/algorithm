

#include <iostream>
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


void push(Queue *Q, int x, int y, long long cnt)
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
void pop(Queue *Q, int *x, int *y, long long *cnt)
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

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int s_x, s_y;
		int b_x, b_y;
		char arr[1001][1001] = { 0, };

		cin >> s_x >> s_y;
		cin >> b_x >> b_y;

		Queue *Q = new Queue;
		Q->size = 0;
		Q->front = NULL;
		Q->rear = NULL;

		long long cnt = 0;
		push(Q, s_x, s_y, cnt);
		int x=0, y=0;
		while (Q->size != 0)
		{
			pop(Q, &x , &y, &cnt);
			if (arr[x][y] == 0)
			{
				arr[x][y] = 1;
				if (x == b_x&&y == b_y)
					break;
				else
				{
					if (x - 2 > 0 && y - 1 > 0 && arr[x - 2][y - 1] == 0) push(Q, x - 2, y - 1, cnt + 1);
					if (x - 2 > 0 && y + 1 <= 1000 && arr[x - 2][y + 1] == 0) push(Q, x - 2, y + 1, cnt + 1);
					if (x - 1 > 0 && y - 2 > 0 && arr[x - 1][y - 2] == 0) push(Q, x - 1, y - 2, cnt + 1);
					if (x - 1 > 0 && y + 2 <= 1000 && arr[x - 1][y + 2] == 0) push(Q, x - 1, y + 2, cnt + 1);
					if (x + 1 <= 1000 && y - 2 > 0 && arr[x + 1][y - 2] == 0) push(Q, x + 1, y - 2, cnt + 1);
					if (x + 1 <= 1000 && y + 2 <= 1000 && arr[x + 1][y + 2] == 0) push(Q, x + 1, y + 2, cnt + 1);
					if (x + 2 <= 1000 && y - 1 > 0 && arr[x + 2][y - 1] == 0) push(Q, x + 2, y - 1, cnt + 1);
					if (x + 2 <= 1000 && y + 1 <= 1000 && arr[x + 2][y + 1] == 0) push(Q, x + 2, y + 1, cnt + 1);

				}
			}

		}
		cout <<cnt<< endl;




	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
