////#include<iostream>
////using namespace std;
////typedef struct node
////{
////	int data;
////	struct node * Next;
////
////}Node;
////
////typedef struct queue
////{
////	int size;
////	Node *first;
////	Node *rear;
////
////}Queue;
////
////
////Queue * creatrqueue()
////{
////	Queue *Q = new Queue;
////
////	Q  -> size = 0;
////	Q->first = NULL;
////	Q->rear = NULL;
////	return Q;
////}
////void enqueue(Queue *Q, int data)
////{
////
////
////	Node * New = new Node;
////	New->data = data;
////	New->Next = NULL;
////
////	if (Q->size == 0)
////	{
////		Q->first = New;
////		Q->rear = New;
////		Q->size++;
////	}
////	else if (Q->size > 100)
////	{
////		cout << "Queue is Full!!" << endl;
////	}
////	else
////	{
////		Q->rear->Next = New;
////		Q->rear = New;
////		Q->size++;
////	}
////}
////
////int dequeue(Queue *Q)
////{
////	if (Q->size == 0)
////	{
////		cout << "Queue is Empty!!" << endl;
////		return 0;
////	}
////	else
////	{
////		Node *tmp = Q->first;
////		int data = tmp->data;
////		Q->size--;
////		Q->first = Q->first->Next;
////		delete(tmp);
////
////		return data;
////
////	}
////}
////
////
////int main()
////{
////	Queue *Q;
////	Q = creatrqueue();
////
////	for (int i = 1; i < 11;i++)
////		enqueue(Q, i);
////	
////	for (int i = 0; i < 12; i++)
////	{
////		int a = 0;
////		a = dequeue(Q);
////		if (a != 0)
////			cout << "Pop! :  " << a << endl;
////
////	}
////
////
////
////
////	return 0;
////}
//
//
//
//#include<iostream>
//using namespace std;
//typedef struct node
//{
//	int data;
//	struct node * Next;
//
//}Node;
//
//typedef struct queue
//{
//	int size;
//	Node *first;
//	Node *rear;
//
//}Queue;
//
//
//Queue * creatrqueue()
//{
//	Queue *Q = new Queue;
//
//	Q->size = 0;
//	Q->first = NULL;
//	Q->rear = NULL;
//	return Q;
//}
//void enqueue(Queue *Q, int data)
//{
//
//
//	Node * New = new Node;
//	New->data = data;
//	New->Next = NULL;
//
//	if (Q->size == 0)
//	{
//		Q->first = New;
//		Q->rear = New;
//		Q->size++;
//	}
//	else if (Q->size > 100)
//	{
//		cout << "Queue is Full!!" << endl;
//	}
//	else
//	{
//		Q->rear->Next = New;
//		Q->rear = New;
//		Q->size++;
//	}
//}
//
//int dequeue(Queue *Q)
//{
//	if (Q->size == 0)
//	{
//		cout << "Queue is Empty!!" << endl;
//		return 0;
//	}
//	else
//	{
//		Node *tmp = Q->first;
//		int data = tmp->data;
//		Q->size--;
//		Q->first = Q->first->Next;
//		delete(tmp);
//
//		return data;
//
//	}
//}
//
//int main()//dfs
//{
//	Queue *Q;
//	Q = creatrqueue();
//	int man, first;
//	cin >> man >> first;
//	int arr[101][101] = { 0 };
//
//
//	int top = 0;
//	int stack[1000] = { 0 };
//	int visit[100] = { 0 };
//	int queue[1000] = { 0 };
//	int front = 0, rear = 0;
//
//	while (1)
//	{
//		int a, b;
//
//		cin >> a >> b;
//		if (a == -1 && b == -1)
//			break;
//		arr[a][b] = 1;
//		arr[b][a] = 1;
//	}
//	visit[1] = 1;
//	cout << 1 << endl;
//	for (int i = 1; i <= man; i++)
//	{
//		if (arr[1][i] == 1)
//		{
//			queue[rear++] = i;
//		}
//	}
//		for (; front != rear;)
//		{
//			int k = queue[front++];
//			
//			if (visit[k] == 0)
//			{
//				cout << k << endl;
//				visit[k] = 1;
//
//				for (int i = 1; i <= man; i++){
//					if (arr[k][i] == 1)
//					{
//						queue[rear++] = i;
//					}
//				}
//
//
//			}
//
//		
//	}
//
//
//
//
//
//
//
//
//
//
//
//		//visit[1] = 1;
//		//for (int i = man; i >0; i--)
//		//{
//		//	if (arr[1][i] == 1)
//		//	{
//		//		stack[top] = i;
//		//		top++;
//		//	}
//		//}
//		//cout << 1 << endl;
//		//for (int i = top - 1; i >= 0; i--)
//		//{
//		//	top--;
//		//	int k = stack[top];
//		//	if (visit[k] == 0)
//		//	{
//		//		cout << k << endl;
//		//		visit[k] = 1;
//		//		for (int l = man; l>0; l--)
//		//		{
//		//			if (arr[k][l] == 1)
//		//			{
//		//				stack[top] = l;
//		//				top++;
//
//		//			}
//		//		}
//		//	}
//		//	i = top - 1;
//		//}
//
//
//		return 0;
//	}



#include<iostream>
using namespace std;


typedef struct data
{
	int x;
	int y;
	int cnt;

}Data;

int main()
{
	int size;
	cin >> size;
	int arr[100][100];

	
	int front=0, rear=0;


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				arr[i][j] = -1;
			/*if (arr[i][j] == 1)
			{
				queue[rear].x = i;
				queue[rear].y = j;
				queue[rear].cnt = 1;
			}
*/
		}
	}
	int x, y;

	cin >> y >> x;
	arr[x - 1][y - 1] = 1;
	int max;
	cin >> max;



	/*while (front != rear)
	{
		int x_p = queue[front].x;
		int y_p = queue[front].y;
		int cnt = queue[front].cnt;



	}*/


	int k = 1;

	while (k <=max){
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++)
			{
				if (arr[i][j] == k)
				{
					if (arr[i - 1][j] == 0) arr[i - 1][j] = k + 1;
					if (arr[i + 1][j] == 0) arr[i + 1][j] = k + 1;
					if (arr[i][j - 1] == 0) arr[i][j - 1] = k + 1;
					if (arr[i][j + 1] == 0)	arr[i][j + 1] = k + 1;

				}
			}
		}
		k++;
	}
	int sum = 0;
	for (int i = 0; i < size;i++)
	for (int j = 0; j < size; j++)
	{
		if (arr[i][j] == max+1)
			sum++;
	}

	if (sum != 0)
	{
		cout << sum << endl;
	}
	else
	{
		cout << "OH, MY GOD" << endl;
	}

}