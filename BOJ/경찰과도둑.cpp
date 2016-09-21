//#include <iostream>//빼기큐
//using namespace std;
//
//typedef struct node
//{
//	int num;
//	struct node *next;
//
//}_node;
//
//
//typedef struct queue
//{
//	int size;
//	_node *front;
//	_node *rear; 
//}Queue;
//
//void enqueue(Queue *Q, int data)
//{
//	_node *New = new _node;
//
//	New->num = data;
//
//	New->next = NULL;
//
//
//	if (Q->size == 0)
//	{
//		Q->front = New;
//		Q->rear = New;
//		Q->size++;
//	}
//	else
//	{
//		Q->rear->next = New;
//		Q->rear = New;
//		Q->size++;
//	}
//
//}
//
//
//void dequeue(Queue *Q)
//{
//	_node * tmp;
//
//
//	if (Q->size==1)
//	{
//		tmp = Q->front;
//		Q->front = NULL;
//		Q->rear = NULL;
//		delete(tmp);
//		Q->size--;
//	}
//	else if (Q->size == 0)
//	{
//	}
//	else
//	{
//		tmp = Q->front;
//		Q->front = Q->front->next;
//		delete(tmp);
//		Q->size--;
//	}
//}
//
//
//void print(Queue *Q)
//{
//	if (Q->size == 0)
//		cout << "error!"<<endl;
//	else
//	{
//		_node *tmp = Q->front;
//			while (tmp != NULL)
//			{
//				cout << tmp->num << endl;
//				tmp = tmp->next;
//			}
//	}
//}
//
//int main()
//{
//
//	int nCount;		/* 문제의 테스트 케이스 */
//
//	cin >> nCount;	/* 테스트 케이스 입력 */
//
//	for (int itr = 0; itr<nCount; itr++)
//	{
//
//		cout << "#testcase" << (itr + 1) << endl;
//
//		int a;
//		cin >> a;
//		Queue *Q = new Queue;
//		Q->size = 0;
//		Q->front = NULL;
//		Q->rear = NULL;
//
//
//		for (int i = 0; i < a; i++)
//		{
//			char data[2];
//
//			cin >> data;
//			if (data[0] == '-')
//				dequeue(Q);
//			else
//				enqueue(Q, data[0]-48 );
//
//		}
//
//		print(Q);
//
//	}
//
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//
//}

/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
typedef struct node
{
	int num;
	int cnt;
	struct node *next;

}_node;
typedef struct queue
{
	int size;
	_node *front;
	_node *rear;
}Queue;
void enqueue(Queue *Q, int data, int cnt)
{
	_node *New = new _node;

	New->num = data;
	New->cnt = cnt;
	New->next = NULL;

	if (Q->size == 0)
	{
		Q->front = New;
		Q->rear = New;
		Q->size++;
	}
	else
	{
		Q->rear->next = New;
		Q->rear = New;
		Q->size++;
	}
}
int dequeue(Queue *Q, int * cnt)
{
	_node * tmp;
	int data;

	if (Q->size == 1)
	{
		tmp = Q->front;
		data = tmp->num;
		*cnt = tmp->cnt;
		Q->front = NULL;
		Q->rear = NULL;
		delete(tmp);
		Q->size--;
	}
	else if (Q->size == 0)return 0;
	else
	{
		tmp = Q->front;
		data = tmp->num;
		*cnt = tmp->cnt;
		Q->front = Q->front->next;
		delete(tmp);
		Q->size--;
	}
	return data;
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */
	cin >> nCount;	/* 테스트 케이스 입력 */
	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int a, b;
		cin >> a >> b;
		int arr[200001] = { 0, };
		Queue *Q = new Queue;
		Q->size = 0;
		Q->front = NULL;
		Q->rear = NULL;

		enqueue(Q, a, 0);
		int cou = 0;
		while (Q->front != NULL || Q->size != 0)
		{
			int num = (dequeue(Q, &cou));
			if (num < 0)continue;
			if (num > 199999)continue;
			if (arr[num] == 1)continue;
			arr[num] = 1;
			if (num == b)
				break;

			enqueue(Q, num * 2, cou + 1);
			enqueue(Q, num + 1, cou + 1);
			enqueue(Q, num - 1, cou + 1);
		}

		cout << cou << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}