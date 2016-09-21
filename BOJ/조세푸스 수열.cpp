 
#include <iostream>
using namespace std;
typedef struct node{
	int data;
	struct node *prev;
	struct node *next;

}Node;


typedef struct queue{
	int size;
	Node *front;
	Node *rear;
}Queue;

void enqueue(Queue *Q, int data)
{
	Node *New = new Node;
	New->data = data;
	New->next = NULL;
	New->prev = NULL;

	if (Q->size == 0)
	{	
		New->prev = New;
		New->next = New;
		Q->front = New;
		Q->rear = New;
	}
	else
	{
		New->next = Q->front;
		New->prev = Q->rear;
		Q->rear->next = New;
		Q->front->prev = New;
		Q->rear = New;
	}
	Q->size++;
}
void next(Queue *Q)
{
	Q->front = Q->front->next;
	Q->rear = Q->front->prev;

}
void dequeue(Queue *Q)
{
	if (Q->size == 1)
	{
		Node *tmp = Q->front;
		cout << tmp->data << endl;
		Q->front = NULL;
		Q->rear = NULL;
		delete(tmp);

	}
	else
	{
		Node *tmp = Q->front;
		Q->front = Q->front->next;
		cout << tmp->data << " ";
		Q->front->prev = Q->rear;
		Q->rear->next = Q->front;
		delete(tmp);

	}
	Q->size--;
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		Queue *Q = new Queue;
		Q->size = 0;
		Q->front = NULL;
		Q->rear = NULL;
		int man, seq;
		cin >> man >> seq;
		for (int i = 1; i <= man; i++)
		{
			enqueue(Q, i);
		}
		while (Q->size != 0)
		{
			for (int i = 0; i < seq; i++)
			{
				if (i == seq - 1)
				{
					dequeue(Q);
				}
				else
				{
					next(Q);
				}
			}


		}
}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}