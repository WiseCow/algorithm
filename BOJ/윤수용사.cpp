//#include <iostream>
//#define SIZE 52
//using namespace std;
//
//typedef struct Node
//{
//	int x;
//	int y;
//	int cnt;
//	struct Node *next;
//}Node;
//
//typedef struct Queue
//{
//	int size;
//	Node *head;
//	Node *tail;
//}Queue;
//
//void push(Queue *q, int x, int y, int cnt)
//{
//	Node *newQ = new Node;
//	newQ->x = x;
//	newQ->y = y;
//	newQ->cnt = cnt;
//	newQ->next = NULL;
//	if (q->size == 0)
//	{
//		q->head = newQ;
//		q->tail = newQ;
//	}
//	else
//	{
//		q->tail->next = newQ;
//		q->tail = q->tail->next;
//	}
//	q->size++;
//}
//
//void pop(Queue *q)
//{
//	Node *temp;
//	if (q->size == 0)
//	{
//
//	}
//	else
//	{
//		temp = q->head;
//		q->head = q->head->next;
//		delete(temp);
//		q->size--;
//	}
//}
//
//int main()
//{
//	int nCount;
//	cin >> nCount;
//	for (int itr = 0; itr < nCount; itr++)
//	{
//		//�� ť
//		Queue *fire = new Queue;
//		fire->head = NULL;
//		fire->tail = NULL;
//		fire->size = 0;
//		//��� ť
//		Queue *hero = new Queue;
//		hero->head = NULL;
//		hero->tail = NULL;
//		hero->size = 0;
//
//		cout << "#testcase" << (itr + 1) << endl;
//		int r, c, hero_x, hero_y, hero_cnt = 1, finish_x, finish_y, fire_x, fire_y, loop = 0;
//		char arr[SIZE][SIZE] = { 0 };
//		int temp[SIZE][SIZE] = { 0 };
//		cin >> r >> c;
//		//�Է�
//		for (int i = 1; i <= r; i++)
//		{
//			for (int j = 1; j <= c; j++)
//			{
//
//				cin >> arr[i][j];
//				//��� ������ �ʱ�ȭ
//				if (arr[i][j] == 'S')hero_x = i, hero_y = j;
//				//�� ��ǥ push
//				if (arr[i][j] == '*'){ push(fire, i, j, 0); loop++; }
//				//�������� �ʱ�ȭ
//				if (arr[i][j] == 'D')finish_x = i, finish_y = j;
//			}
//		}
//		bool flag = 0;
//		//��簡 �����Ҷ�����(�Ҹ��� BFS�� ������ ��� BFS��)
//		while (temp[finish_x][finish_y] == 0 && !flag)
//		{
//			int loop_cnt = 0;
//			for (int i = 0; i < loop; i++)
//			{
//				//�� ť�� ������� ������� �� ��ǥ ����(���� cnt�Ⱦ�)
//				if (fire->size != 0)fire_x = fire->head->x;
//				if (fire->size != 0)fire_y = fire->head->y;
//				pop(fire);
//
//				//�� ���� - ���� �� ����
//				if (arr[fire_x - 1][fire_y] == '.' || arr[fire_x - 1][fire_y] == 'f'){ arr[fire_x - 1][fire_y] = '*'; push(fire, fire_x - 1, fire_y, 0); loop_cnt++; }
//				if (arr[fire_x][fire_y - 1] == '.' || arr[fire_x][fire_y - 1] == 'f'){ arr[fire_x][fire_y - 1] = '*'; push(fire, fire_x, fire_y - 1, 0); loop_cnt++; }
//				if (arr[fire_x + 1][fire_y] == '.' || arr[fire_x + 1][fire_y] == 'f'){ arr[fire_x + 1][fire_y] = '*'; push(fire, fire_x + 1, fire_y, 0); loop_cnt++; }
//				if (arr[fire_x][fire_y + 1] == '.' || arr[fire_x][fire_y + 1] == 'f'){ arr[fire_x][fire_y + 1] = '*'; push(fire, fire_x, fire_y + 1, 0); loop_cnt++; }
//			}
//			loop = loop_cnt;
//			//��� ��ǥ ����(ī��Ʈ�� �߰�.�ϴ� Ǯ�� int�迭�� ����)
//			if (hero->size != 0)hero_x = hero->head->x;
//			if (hero->size != 0)hero_y = hero->head->y;
//			if (hero->size != 0)hero_cnt = hero->head->cnt;
//			pop(hero);
//
//			//f�� free.. ���� ��� ���� �ü��ְ�.�� �ٽ� �Ȱ��� - ������ ����..
//			if (arr[hero_x - 1][hero_y] == '.' || arr[hero_x - 1][hero_y] == 'D'&& temp[hero_x - 1][hero_y] == 0){ arr[hero_x][hero_y] = 'f'; temp[hero_x - 1][hero_y] = hero_cnt; push(hero, hero_x - 1, hero_y, hero_cnt + 1); }
//			if (arr[hero_x][hero_y - 1] == '.' || arr[hero_x][hero_y - 1] == 'D' && temp[hero_x][hero_y - 1] == 0){ arr[hero_x][hero_y] = 'f'; temp[hero_x][hero_y - 1] = hero_cnt; push(hero, hero_x, hero_y - 1, hero_cnt + 1); }
//			if (arr[hero_x + 1][hero_y] == '.' || arr[hero_x + 1][hero_y] == 'D' && temp[hero_x + 1][hero_y] == 0){ arr[hero_x][hero_y] = 'f'; temp[hero_x + 1][hero_y] = hero_cnt; push(hero, hero_x + 1, hero_y, hero_cnt + 1); }
//			if (arr[hero_x][hero_y + 1] == '.' || arr[hero_x][hero_y + 1] == 'D' && temp[hero_x][hero_y + 1] == 0){ arr[hero_x][hero_y] = 'f'; temp[hero_x][hero_y + 1] = hero_cnt; push(hero, hero_x, hero_y + 1, hero_cnt + 1); }
//
//			if (hero->size == 0){ flag = 1; cout << "impossible" << endl; break; }
//
//		}
//		//������ ��� �� �� ���, �������� ���� ��� "impossible" ���
//		if (flag == 0)
//		{
//			if (temp[finish_x][finish_y] != 0)cout << temp[finish_x][finish_y] << endl;
//			else cout << "impossible" << endl;
//		}
//	}
//	return 0;
//}
//



/*

VCPP, GPP���� ���

*/

//#include <iostream>
//using namespace std;
//int main()
//{
//
//	int nCount;		/* ������ �׽�Ʈ ���̽� */
//
//	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */
//
//	for (int itr = 0; itr<nCount; itr++)
//	{
//
//		cout << "#testcase" << (itr + 1) << endl;
//
//		/*
//
//		�˰����� ���� �κ�
//
//		*/
//
//		int k, n;
//		cin >> k >> n;
//
//		long long fish = 0;
//		int farr[10000] = { 0, };
//
//		for (int i = 0; i < k; i++)
//		{
//			cin >> farr[i];
//
//			fish += farr[i];
//		}
//
//		int now = fish / n;
//		int high = now;
//		int low = 0;
//
//		int flag = 0;
//
//		while(now != low)
//		{
//			flag = 0;
//
//			for (int j = 0; j < k; j++)
//			{
//				flag += (farr[j] / now);
//			}
//
//			if (flag >= n)
//			{
//				low = now;
//				now = (high + now) / 2;
//			}
//			else
//			{
//				high = now;
//				now = (now + low) / 2;
//			}
//		}
//
//		cout << now << endl;
//	}
//
//	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
//}


/*

VCPP, GPP���� ���

*/

//#include <iostream>
//using namespace std;
//
//typedef unsigned long long Big;
//
//int main(void)
//{
//	int testcase;
//	cin >> testcase;
//	for (int itr = 0; itr < testcase; itr++)
//	{
//		Big num, man;
//		cin >> num >> man;
//		Big fish[100010] = { 0, };
//		Big mini = 999999;
//		Big total = 0;
//		int _idx = 0;
//		for (int i = 0; i < num; i++)
//		{
//			cin >> fish[i];
//			total += fish[i];
//			if (mini > fish[i])
//			{
//				mini = fish[i];
//				_idx = i;
//			}
//		}
//
//		Big temp = (Big)(total / man);
//		if (temp > mini) temp = mini;
//
//		Big ncnt = 0;
//		Big fish_temp = 0;
//		while (ncnt < man)
//		{
//			ncnt = 0;
//			for (int i = 0; i < num; i++)
//			{
//				fish_temp = fish[i];
//				ncnt += (Big)(fish_temp / temp);
//			}
//			temp--;
//		}
//
//		cout << "#testcase" << itr + 1 << endl;
//		cout << temp + 1 << endl;
//
//
//
//	}
//
//	return 0;
//}

/*

VC, GCC���� ���

*/
#include <iostream>
using namespace std;

int moving[10][16] = { { 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 3 },
{ 3, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 0, 3, 0, 0, 0 },
{ 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3 },
{ 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3 },
{ 0, 0, 0, 0, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3 },
{ 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0 } };
int result;
int flag[20];

bool Check(int *arr)
{
	for (int i = 0; i < 16; i++)
		if (arr[i] != 12) return false;
	return true;
}

void Sum_time(int *arr1, int *arr2)
{
	int temp;
	for (int i = 0; i < 16; i++)
	{
		if (arr1[i] + arr2[i] > 12) temp = 3;
		else temp = arr1[i] + arr2[i];
		arr1[i] = temp;
	}
}

void Sub_time(int*arr1, int*arr2)
{
	int temp;
	for (int i = 0; i < 16; i++)
	{
		if (arr1[i] - arr2[i] <= 0) temp = 12;
		else temp = arr1[i] - arr2[i];
		arr1[i] = temp;
	}
}

void Recursion(int *arr, int cnt, int now, int flag_cnt)
{
 	if (flag_cnt > 3) return;
	if (Check(arr))
	{
		for (int i = 0; i < 16; i++)
			result += flag[i];
		//result = cnt;
		return;
	}
	else
	{
		for (int i = now; i < 10; i++)
		{
			Sum_time(arr, moving[i]);
			flag[i] += 1;
			Recursion(arr, cnt + 1, i, flag[i]);
			Sub_time(arr, moving[i]);
			flag[i] -= 1;

		}
	}
}

int main(void)
{
	int testcase;
	cin >> testcase;
	for (int itr = 0; itr < testcase; itr++)
	{
		int arr[20] = { 0, };

		for (int i = 0; i < 16; i++)
			cin >> arr[i];

		result = 0;
		Recursion(arr, 0, 0, 0);

		cout << "#testcase" << itr + 1 << endl;
		if (result == 0) cout << -1 << endl;
		else cout << result << endl;

	}

	return 0;
}