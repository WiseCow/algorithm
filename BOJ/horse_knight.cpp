//#include<iostream>
//#include<malloc.h>
//
//using namespace std;
//typedef struct que{
//	int count;
//	int x;
//	int y;
//	struct que *next;
//	struct que *prev;
//
//} queue;
//int m_size;
//int d_num;
//int map[1005][1005];
//int ho_map[1005][1005];
//int x_state;
//int y_state;
//queue *knight;
//queue *horse;
//
//void enqueue(queue *que, int _x, int _y, int _count)
//{
//	queue * New = (queue *)malloc(sizeof(queue));
//	New->x = _x;
//	New->y = _y;
//	New->count = _count;
//
//	if (que == NULL)
//	{
//		New->next = New;
//		New->prev = New;
//		que = New;
//
//	}
//	else
//	{
//		que->next->prev = New;
//		New->next = que->next;
//		New->prev = que;
//		que->next = New;
//
//	}
//
//
//}
//
//void dequeue(queue **que)
//{
//	if ((*que)->next!=*que)
//	{
//		queue *drop = (*que)->prev->next;
//
//		*que = (*que)->prev;
//		(*que)->next->next->prev = *que;
//		(*que)->next = (*que)->next->next;
//		free(drop);
//	}
//	else
//	{
//		*que = NULL;
//	}
//}
//void writemap(queue *knight)
//{
//	if (knight == NULL)
//		return;
//	int _x = knight->x, _y=knight->y ,_count = knight->count;
//	
//
//
//	for (int i = -1; i < 2;i+=2)
//	for (int j = -1; j < 2; j += 2)
//	{
//		if (_x + 2 * i < 0 || _y + j < 0 || _x + 2 * i >= m_size || _y + j >= m_size)
//			continue;
//		else
//		{
//			if (map[_x + 2 * i][_y + j] == 0)
//			{
//				map[_x + 2 * i][_y + j] = _count + 1;
//				enqueue(knight, _x + 2 * i, _y + j, _count+1);
//			}
//			else
//				continue;
//		}
//	}
//	for (int i = -1; i < 2; i += 2)
//	for (int j = -1; j < 2; j += 2)
//	{
//		if (_x + i < 0 || _y + 2*j < 0 || _x + i >= m_size || _y + 2 * j >= m_size)
//			continue;
//		else
//		{
//			if (map[_x + i][_y + 2*j] == 0)
//			{
//				map[_x + i][_y + 2*j] = _count + 1;
//				enqueue(knight, _x + i, _y + 2*j, _count + 1);
//			}
//			else
//				continue;
//		}
//	}
//
//	dequeue(&knight);
//	writemap(knight);
//
//}
//
//void ho_writemap(queue *knight)
//{
//	if (knight == NULL)
//		return;
//	int _x = knight->x, _y = knight->y, _count = knight->count;
//
//
//
//	for (int i = -1; i < 2; i += 2)
//	for (int j = -1; j < 2; j += 2)
//	{
//		if (_x + 2 * i < 0 || _y + j < 0 || _x + 2 * i >= m_size || _y + j >= m_size)
//			continue;
//		else
//		{
//			if (ho_map[_x + 2 * i][_y + j] == 0)
//			{
//				if (ho_map[_x + i][_y] != -1)
//				{
//					ho_map[_x + 2 * i][_y + j] = _count + 1;
//					enqueue(knight, _x + 2 * i, _y + j, _count + 1);
//				}
//				else
//					continue;
//			}
//			else
//				continue;
//		}
//	}
//	for (int i = -1; i < 2; i += 2)
//	for (int j = -1; j < 2; j += 2)
//	{
//		if (_x + i < 0 || _y + 2 * j < 0 || _x + i >= m_size || _y + 2 * j >= m_size)
//			continue;
//		else
//		{
//			if (ho_map[_x + i][_y + 2 * j] == 0)
//			{
//				if (ho_map[_x][_y + j] != -1)
//				{
//					ho_map[_x + i][_y + 2 * j] = _count + 1;
//					enqueue(knight, _x + i, _y + 2 * j, _count + 1);
//				}
//				else
//					continue;
//			}
//			else
//				continue;
//		}
//	}
//
//	dequeue(&knight);
//	ho_writemap(knight);
//
//}
//
//int main()
//{
//
//	int nCount;		/* 문제의 테스트 케이스 */
//
//	cin >> nCount;	/* 테스트 케이스 입력 */
//
//	for (int itr = 0; itr < nCount; itr++)
//	{
//		printf("#testcase%d\n", itr + 1);
//		cin >> m_size >> d_num;
//		for (int i = 0; i < m_size; i++)
//		for (int j = 0; j < m_size; j++){
//			cin >> map[i][j];
//			map[i][j] == 1 ? map[i][j] = -1 : map[i][j];
//			ho_map[i][j] = map[i][j];
//		}
//		cin >> x_state >> y_state;
//		map[x_state - 1][y_state - 1] = -2;
//		ho_map[x_state - 1][y_state - 1] = -2;
//
//		knight = (queue *)malloc(sizeof(queue));
//		knight->x = x_state - 1;
//		knight->y = y_state - 1;
//		knight->count = 0;
//		knight->next = knight;
//		knight->prev = knight;
//
//		horse = (queue *)malloc(sizeof(queue));
//		horse->x = x_state - 1;
//		horse->y = y_state - 1;
//		horse->count = 0;
//		horse->next = horse;
//		horse->prev = horse;
//
//		writemap(knight);
//		ho_writemap(horse);
//
//		int fin_count = 0;
//
//		for (int i = 0; i < m_size; i++)
//		for (int j = 0; j < m_size; j++)
//		if (map[i][j] < ho_map[i][j] || (map[i][j]>0 && ho_map[i][j] == 0))
//			fin_count++;
//		cout << fin_count;
//	}
//	return 0;
//}
//
// 

 
//#include <iostream>
//using namespace std;
//int arr[1001][1001] = { 0, };
//int Kn[1001][1001] = { 0, };
//int Ho[1001][1001] = { 0, };
//typedef struct node
//{
//	int x;
//	int y;
//	int cnt;
//	struct node *next;
//}Node;
//
//typedef struct queue
//{
//	int size;
//	Node *front;
//	Node *rear;
//}Queue;
//void insertqu(Queue *Q, int x, int y, int cnt)
//{
//	Node *New = new Node;
//	New->x = x;
//	New->y = y;
//	New->next = NULL;
//	New->cnt = cnt;
//
//	if (Q->size == 0)
//	{
//		Q->front = New;
//		Q->rear = New;
//		Q->size++;
//	}
//	else
//	{
//		Q->size++;
//		Q->rear->next = New;
//	}
//}
//void dequKn(Queue *Q, int size)
//{
//	if (Q->size == 0)
//		return;
//	else
//	{
//		Node *tmp = Q->front;
//		int x, y, cnt;
//		x = Q->front->x;
//		y = Q->front->y;
//		cnt = Q->front->cnt;
//		
//		if (Kn[x][y] == 0 || Kn[x][y] > cnt)
//		{
//			Kn[x][y] = cnt;
//			if (x - 1 >= 0 && arr[x - 1][y] != -2)insertqu(Q, x - 1, y, cnt + 1);
//			if (x + 1 < size&&arr[x - 1][y] != -2)insertqu(Q, x + 1, y, cnt + 1);
//			if (y - 1 >= 0 && arr[x - 1][y] != -2)insertqu(Q, x, y - 1, cnt + 1);
//			if (y + 1 < size&&arr[x - 1][y] != -2)insertqu(Q, x, y + 1, cnt + 1);
//			
//		}
//		Q->size--;
//		Q->front = Q->front->next;
//		delete(tmp);
//	}
//}
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
//		int size, d_num;
//		
//		cin >> size >> d_num;
//
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//
//				cin >> arr[i][j];
//				if (arr[i][j] == 1)
//					arr[i][j] = -2;
//			}
//		}
//		int x, y;
//		cin >> x >> y;
//
//		Queue *Knight = new Queue;
//		Knight->front = NULL;
//		Knight->rear = NULL;
//		Knight->size = 0;
//
//
//		insertqu(Knight, x-1,y-1,1);
//		while (1)
//		{
//			if (Knight->size == 0)
//				break;
//
//			dequKn(Knight, size);
//		}
//
//
//
//
//
//
//
//		cout << Kn[0][0];
//
//
//
//
//	}
//	
//
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//
//}