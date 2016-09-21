//http://59.23.113.171/30stair/dam/dam.php?pname=dam
//#include<iostream>
//#include<malloc.h>
//int Tsize;
//int solution;
//
//using namespace std;
//
//int map[100][100];
//int fl = 0;
//typedef struct fld{
//	int x;
//	int y;
//	int cnt;
//	struct fld *next;
//	struct fld *prev;
//
//
//}flood;
//
//void insert(int _x, int _y, int cnt, flood **ptr)
//{
//	flood *New = (flood *)malloc(sizeof(flood));
//	New->cnt = cnt;
//	New->x = _x;
//	New->y = _y;
//	if (*ptr == NULL)
//	{
//		New->next = New;
//		New->prev = New;
//		*ptr = New;
//	}
//	else
//	{
//		
//		New->prev = (*ptr)->prev;
//		(*ptr)->prev->next = New;
//		New->next = (*ptr);
//		(*ptr)->prev = New;
//	}
//}
//
//void deque(flood **ptr)
//{
//	if (*ptr == NULL)
//	{
//		fl = 1;
//		return;
//	}
//	flood *tmp = (*ptr)->prev->next;
//	int x = (*ptr)->x;
//	int y = (*ptr)->y;
//	int cnt = (*ptr)->cnt;
//
//	if ((*ptr)->next != *ptr){
//		
//		(*ptr)->next->prev = (*ptr)->prev;
//		(*ptr)->prev->next = (*ptr)->next;
//		*ptr = (*ptr)->next;
//		free(tmp);
//	}
//	else
//	{
//		free(*ptr);
//		*ptr = NULL;
//	}
//	if (cnt > solution)
//	{
//		fl = 1;
//		return;
//		
//	}
//	
//	if (cnt == 0)
//		map[x][y] = -2;
//	else
//	{
//		if (map[x][y] == 0)
//			map[x][y] = cnt;
//	}
//
//	for(int i = -1; i < 2; i += 2)
//	{
//		if (x + i<0 || x + i>Tsize-1)
//			continue;
//		else
//		{
//			if (map[x + i][y] == 0)
//				insert(x + i, y, cnt + 1, ptr);	
//		}
//	}
//
//	for (int i = -1; i < 2; i += 2)
//	{
//		if (y + i<0 || y + i>Tsize-1)
//			continue;
//		else
//		{
//			if (map[x][y+i] == 0)
//				insert(x, y+i, cnt + 1, ptr);
//
//		}
//
//
//	}
//	//체크하고 insert하기
//
//
//
//}
//
//
//
//void floood(int _x, int _y, int cnt, flood **ptr)
//{
//	insert(_x, _y, cnt, ptr);
//	while (1)
//	{
//		deque(ptr);
//		if (fl == 1)
//			break;
//
//	}
//}
//int main()
//	
//{
//	
//	cin >> Tsize;
//
//	int x, y;
//	
//	flood *ptr=NULL;
//
//	for (int i = 0; i < Tsize; i++)
//	for (int j = 0; j < Tsize; j++)
//	{
//		cin >> map[i][j];
//		if (map[i][j] == 1)
//			map[i][j] = -1;
//
//	}
//
//	cin >> x >> y;
//	cin >> solution;
//	map[x - 1][y - 1] = -2;
//
//	int flag = 0;
//	
//		floood(y-1, x-1, 0, &ptr);
//	
//		for (int i = 0; i < Tsize; i++)
//		for (int j = 0; j < Tsize;j++)
//		if (map[i][j]==solution)
//		{
//			flag++;
//		}
//
//
//
//	
//	cout << flag << endl;
//	
//}
//
//



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


	int front = 0, rear = 0;


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

	while (k <= max){
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
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == max + 1)
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