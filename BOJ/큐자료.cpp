//////#include<iostream>
//////using namespace std;
//////
//////struct _node
//////{
//////	int data;
//////	_node *next;
//////};
//////
//////struct Queue
//////{
//////	int num;
//////	_node *front;
//////	_node *rear;
//////};
//////
//////void inital(Queue *qu)
//////{
//////	qu->front = NULL;
//////	qu->rear = NULL;
//////	qu->num = 0;
//////}
//////
//////void enqueue(Queue *qu, int data)
//////{
//////	_node *newnode = new _node;
//////	newnode->data = data;
//////	newnode->next = NULL;
//////
//////	if (qu->num == 0)
//////	{
//////		qu->front = newnode;
//////		qu->rear = newnode;
//////	}
//////	else
//////	{
//////		qu->rear->next = newnode;
//////		qu->rear = newnode;
//////	}
//////	qu->num++;
//////}
//////
//////
//////int dequeue(Queue *qu)
//////{
//////	_node *tmpnode;
//////
//////	if (qu->num == 0)
//////	{
//////		return -1;
//////	}
//////	else
//////	{
//////		tmpnode = qu->front;
//////		qu->front = qu->front->next;
//////		int data = tmpnode->data;
//////		delete tmpnode;
//////		qu->num--;
//////		return data;
//////	}
//////}
//////
//////
//////int main()
//////{
//////
//////	Queue *qu = new Queue;
//////	inital(qu);
//////	enqueue(qu, 1);
//////	enqueue(qu, 2);
//////	enqueue(qu, 3);
//////	
//////	
//////	int data;
//////	cout << dequeue(qu) << endl;
//////	cout << dequeue(qu) << endl;
//////	cout << dequeue(qu) << endl;
//////	cout << dequeue(qu) << endl;
//////
//////	return 0;
//////}
////
////#include<iostream> //MAZE
////using namespace std;
////
////
////struct _node
////{
////	int xp;
////	int yp;
////	int now;
////	_node *next;
////};
////
////struct Queue
////{
////	int num;
////	_node *front;
////	_node *rear;
////};
////
////void enqueue(Queue *qu, int x, int y, int now)
////{
////	_node *newnode = new _node;
////	newnode->xp = x;
////	newnode->yp = y;
////	newnode->now = now;
////
////	newnode->next = NULL;
////
////	if (qu->num == 0)
////	{
////		qu->front = newnode;
////		qu->rear = newnode;
////	}
////	else
////	{
////		qu->rear->next = newnode;
////		qu->rear = newnode;
////	}
////	qu->num++;
////}
////
////
////
////
////bool chk(int x, int y, int mx, int my)
////{
////	return x >= 0 && x < mx&&y >= 0 && y < my;
////}
////void dequeue(Queue *qu, char map[30][30],int cnt[30][30], int mx, int my)
////{
////	int fx[4] = { 0, 0, 1, -1 };
////	int fy[4] = { -1, 1, 0, 0 };
////	while (qu->num != 0)
////	{
////		_node *tmp = qu->front;
////		qu->front = qu->front->next;
////		qu->num--;
////
////		int px = tmp->xp;
////		int py = tmp->yp;
////		int now = tmp->now;
////		delete tmp;
////
////		if (cnt[px][py] > now)
////		{
////			cnt[px][py] = now;
////			if (px == 0 && py == my - 1)
////				return;
////			for (int i = 0; i < 4; i++)
////			{
////				if (chk(px + fx[i], py + fy[i], mx, my) && map[px + fx[i]][py + fy[i]] == '0')
////				{
////					enqueue(qu, px + fx[i], py + fy[i], now + 1);
////				}
////			}
////		}
////	}
////}
////
////int main()
////{
////
////	int tc;
////	cin >> tc;
////	for (int itr = 0; itr < tc; itr++)
////	{
////		int x,  y;
////		cin >> x >> y;
////
////		char map[30][30];
////
////		for (int i = 0; i < x; i++)
////		{
////			cin >> map[i];
////		}
////		Queue *qu = new Queue;
////		qu->front = NULL;
////		qu->rear = NULL;
////		qu->num = 0;
////
////
////		enqueue(qu, x - 1, 0,1);
////
////		int cntmap[30][30];
////		for (int i = 0; i < x; i++)
////			for (int j = 0; j < y; j++)
////				cntmap[i][j] = 124;
////		dequeue(qu, map, cntmap, x, y);
////
////
////
////		cout << "#testcase" << itr + 1 << endl;
////		cout << cntmap[0][y - 1] << endl;
////	}
////
////
////
////	return 0;
////}
//
//
//
//
//#include<iostream>
//using namespace std;
//
//struct _node
//{
//	int data;
//	_node *next;
//};
//
//struct Queue
//{
//	int num;
//	_node *front;
//	_node *rear;
//};
//
//void inital(Queue *qu)
//{
//	qu->front = NULL;
//	qu->rear = NULL;
//	qu->num = 0;
//}
//
//void enqueue(Queue *qu, int data)
//{
//	_node *newnode = new _node;
//	newnode->data = data;
//	newnode->next = NULL;
//
//	if (qu->num == 0)
//	{
//		qu->front = newnode;
//		qu->rear = newnode;
//	}
//	else
//	{
//		qu->rear->next = newnode;
//		qu->rear = newnode;
//	}
//	qu->num++;
//}
//
//
//bool dequeue(Queue *qu)
//{
//	_node *tmpnode;
//
//	if (qu->num == 0)
//	{
//		return false;
//	}
//	else
//	{
//		tmpnode = qu->front;
//		qu->front = qu->front->next;
//		int data = tmpnode->data;
//		delete tmpnode;
//		qu->num--;
//		return true;
//	}
//}
//void printqueue(Queue *qu)
//{
//	_node *tmpnode;
//
//	while (qu->num!=0)
//	{
//
//		tmpnode = qu->front;
//		qu->front = qu->front->next;
//		int data = tmpnode->data;
//		delete tmpnode;
//		cout << data << endl;
//		qu->num--;
//	}
//
//}
//
//
//int main()
//{
//
//
//	int tc;
//	cin >> tc;
//	for (int itr = 0; itr < tc; itr++)
//	{
//		Queue *qu = new Queue;
//		inital(qu);
//
//		int cnt;
//		cin >> cnt;
//		bool flag = 0;
//		for (int k = 0; k < cnt; k++)
//		{
//			char a[2];
//			cin >> a;
//
//			if (a[0] == '-')
//			{
//				if (!dequeue(qu))
//				flag = 1;
//			}
//			else
//			{
//				enqueue(qu, a[0] - '0');
//			}
//		}
//
//
//
//
//		cout << "#testcase" << itr + 1 << endl;
//		if (flag == 0)
//			printqueue(qu);
//		else
//			cout << "error!" << endl;
//
//
//
//
//	}
//	return 0;
//}


// 
//#include <iostream>
//using namespace std;
//int main()
//{
//
//	int nCount;		/* 문제의 테스트 케이스 */
//
//	cin >> nCount;	/* 테스트 케이스 입력 */
//
//	for (int itr = 0; itr < nCount; itr++)
//	{
//
//		cout << "#testcase" << (itr + 1) << endl;
//
//		char arr[10005];
//		int chk[10000] = { 0 };
//		bool use[26] = { 0 };
//		chk[0] = 1;
//		chk[1] = 1;
//		for (int i = 2; i < 10000; i++)
//		{
//			for (int j = 2; j*i < 10000; j++)
//			{
//				chk[i*j] = 1;
//			}
//		}
//		int res[26] = { 0 };
//		cin >> arr;
//
//		for (int i = 0; arr[i] != 0; i++)
//		{
//			res[arr[i] - 65]++;
//			use[arr[i] - 65] = 1;
//		}
//		int flag = 0;
//		for (int i = 0; i < 26; i++)
//		{
//			if (chk[res[i]] == 0){
//				printf("%c", i + 65);
//				flag++;
//			}
//
//		}
//		if (flag == 0)
//		{
//			cout << "NONE" ;
//		}
//		cout << endl;
//
//	}
//
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//
//}

/*

VCPP, GPP에서 사용

*/

//#include <iostream>
//using namespace std;
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
//		
//
//		int chk[10000][2] = { 0 };
//		int N, P;
//		cin >> N >> P;
//		int cnt = 1;
//		int floor = 0;
//		chk[floor][0] = N;
//		chk[floor++][1] = cnt++;
//
//		int K = N;
//		int flag = 0;
//		while (1)
//		{
//			int sum = 0;
//			int a[10];
//			a[0] = (K / 1000000000) % 10;
//			a[1] = (K / 100000000) % 10;
//			a[2] = (K / 10000000) % 10;
//			a[3] = (K / 1000000) % 10;
//			a[4] = (K / 100000) % 10;
//			a[5] = (K / 10000) % 10;
//			a[6] = (K / 1000) % 10;
//			a[7] = (K / 100) % 10;
//			a[8] = (K / 10) % 10;
//			a[9] = K % 10;
//			for (int j = 0; j < 10; j++)
//			{
//				int p = a[j];
//				for (int i = 0; i < P-1; i++)
//				{
//					a[j] *= p;
//				}
//			}
//			sum += a[0] + a[1] + a[2] + a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9];
//			int i;
//			for (i = 0; i < floor; i++)
//			{
//				if (chk[i][0] == sum)
//				{
//					flag = chk[i][1];
//					break;
//				}
//			}
//			if (flag == 0)
//			{
//				chk[floor][0] = sum;
//				chk[floor++][1] = cnt++;
//			}
//			else
//			{
//				break;
//			}
//			K = sum;
//		}
//			
//			cout << flag-1<< endl;
//	}
//
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//
//}

/*

VCPP, GPP에서 사용

*/

//#include <iostream>
//using namespace std;
//void find(char *arr, int *chk, int max, int cnt)
//{
//	if (cnt == max+1)
//	{
//		for (int i = 1; i <= max; i++)
//		{
//			for (int j = 0; j < max; j++)
//			{
//				if (chk[j] == i)
//					cout << arr[j];
//			}
//		}
//		cout << endl;
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < max; i++)
//		{
//			if (chk[i] != 0)
//				continue;
//			chk[i] = cnt;
//			find(arr, chk, max, cnt + 1);
//			chk[i] = 0;
//		}
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
//		char arr[11];
//		cin >> arr;
//		int cnt;
//		for (cnt = 0; arr[cnt] != 0; cnt++);
//
//
//		for (int i = 0; i < cnt - 1; i++)
//		{
//			for (int j = 0; j < cnt - i - 1; j++)
//			{
//				if (arr[j]>arr[j + 1])
//				{
//					char tmp = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = tmp;
//
//				}
//			}
//		}
//
//		int chk[11] = { 0 };
//		find(arr, chk, cnt, 1);
//
//
//	}
//
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//
//}


#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	FILE *fp = NULL;
	fp = fopen("output.txt", "a");

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		fprintf(fp,"#testcase%d\n",itr + 1);

		int cnt;
		cin >> cnt;
		int arr[30000];
		int sort[30000];

		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
			sort[i] = arr[i];

		}

		for (int i = 0; i < cnt; i++)
		{
			int max = i;
			for (int j = i + 1; j < cnt; j++)
			{
				if (sort[j]>sort[max])
					max = j;
			}
			int tmp = sort[max];
			sort[max] = sort[i];
			sort[i] = tmp;
		}

		int d = 1;
		int chk[30000];
		chk[0] = 1;
		int sum = 0;
		for (int i = 1; i < cnt; i++)
		{
			if (sort[i - 1] == sort[i])
			{
				chk[i] = d;
				sum++;
			}
			else
			{
				d += sum;
				sum = 0;
				chk[i] = ++d;
			}
		}
		for (int i = 0; i < cnt; i++)
		{
			for (int j = 0; j < cnt; j++)
			{
				if (arr[i] == sort[j])
				{
					fprintf(fp, "%s\n", chk[j]);
					break;
				}
			}
		}
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}