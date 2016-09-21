//https://www.acmicpc.net/problem/2178
#include<iostream>
using namespace std;
char arr[101][101];
int chk[101][101];
int dx[4] = { 1,0,0,-1};
int dy[4] = {0,1,-1,0};
int mx, my;


struct node
{
	int x,y,cnt;
	node *next;

};
struct Queue
{
	int num;
	node *front;
	node *rear;

};
void enqueue(Queue *qu, int x, int y, int cnt)
{

	node *ne = new node;
	ne->x = x;
	ne->y = y;
	ne->cnt = cnt;
	ne->next = NULL;

	if (qu->num == 0)
	{
		qu->front = ne;
		qu->rear = ne;
	}
	else
	{
		qu->rear->next = ne;
		qu->rear = ne;
	}
	qu->num++;
}


void dequeue(Queue *qu)
{

	while (qu->num != 0)
	{
		node *tmp = qu->front;
		qu->front = qu->front->next;
		int x = tmp->x;
		int y = tmp->y;
		int cnt = tmp->cnt;
		qu->num--;
		if (x == mx - 1 && y == my - 1)
		{
			cout << cnt << endl;
			break;
		}

		if (chk[x][y] == 0 || chk[x][y] > cnt)
		{
			chk[x][y] = cnt;
			for (int i = 0; i < 4; i++)
			{
				if (x + dx[i] >= 0 && x + dx[i] < mx&&y + dy[i] >= 0 && y + dy[i] < my&&arr[x+dx[i]][y+dy[i]]=='1')
				{
					enqueue(qu, x + dx[i], y + dy[i],cnt+1);
				}
			}
		}
		delete tmp;
	}
}

int main()
{
	

	cin >> mx >> my;
	for (int a = 0; a < mx; a++)
	{
		cin >> arr[a];
	}
	Queue *Qu = new Queue;
	Qu->front = NULL;
	Qu->rear = NULL;
	Qu->num = 0;
	enqueue(Qu, 0, 0, 1);
	dequeue(Qu);
}