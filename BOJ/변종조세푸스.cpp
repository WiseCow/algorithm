#include <iostream>
using namespace std;
int flag = 0;
struct Node
{
	int data;
	Node *next;
	Node *prev;
};
struct Queue
{
	int size;
	Node *front;
	Node *rear;

};
void insert(Queue *Q, int data)
{
	Node *New = new Node;
	New->data = data;
	New->next = NULL;
	New->prev = NULL;

	if (Q->size == 0)
	{
		Q->front = New;
		Q->rear = New;
		New->next = New;
		New->prev = New;
	}
	else
	{
		New->next = Q->front;
		New->prev = Q->rear;
		Q->front->prev = New;
		Q->rear->next = New;
		Q->rear = New;
	}
	Q->size++;
}
void next(Queue *Q)
{
	if (Q->size != 0)
	{
		Q->front = Q->front->next;
		Q->rear = Q->rear->next;
	}
}
void prev(Queue *Q)
{
	if (Q->size != 0)
	{
		Q->front = Q->front->prev;
		Q->rear = Q->rear->prev;
	}
	
}
void del(Queue *Q)
{
	Node *tmp = NULL;
	if (Q->size == 0)
	{
		flag = 1;
		return;
	}
	else if (Q->size==1)
	{
		tmp = Q->front;
		Q->front = NULL;
		Q->rear = NULL;
		Q->size--;
		cout << tmp->data<<endl;
		delete tmp;
		flag = 1;
	}
	else
	{
		tmp = Q->front;
		cout << tmp->data << " ";
		Q->front->next->prev = Q->rear;
		Q->rear->next = Q->front->next;
		Q->front = Q->front->next;
		Q->size--;
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
		Queue *Q = new Queue;
		Q->size = 0;
		Q->front = NULL;
		Q->rear = NULL;


		int num;
		cin >> num;
		for (int i = 1; i <= num; i++)
		{
			insert(Q, i);
		}
		int m, k;
		cin>> k >> m;
		for (int i = 1; i < m; i++)
		{
			next(Q);
		}
		del(Q);
		int rot = 0;
		while (1)
		{
			if (rot == 0)
			{
				rot = 1;
				for (int i = 1; i < k; i++)
					next(Q);
			}
			else
			{
				rot = 0;
				for (int i = 0; i < k; i++)
					prev(Q);
			}
				del(Q);
				if (flag == 1)
					break;

		}
		flag = 0;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}