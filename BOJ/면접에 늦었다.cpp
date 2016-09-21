https://www.acmicpc.net/problem/5014
#include<iostream>
using namespace std;
int a, b, c, d, e;
int arr[1000001] = { 0 };
int flag = 0;
struct _node
{
	int sta;
	int cnt;
	_node *next;
};
struct Que
{
	int num;
	_node *front;
	_node *rear;

};


Que * init()
{
	Que *newQ = new Que;
	newQ->num = 0;
	newQ->front = NULL;
	newQ->rear = NULL;

	return newQ;
}


void insert(Que *qu,int data, int cnt)
{
	_node *newnode = new _node;
	newnode->cnt = cnt;
	newnode->next = NULL;
	newnode->sta = data;



	if (qu->num == 0)
	{
		qu->front = newnode;
		qu->rear = newnode;
	}
	else
	{
		qu->rear->next = newnode;
		qu->rear = newnode;
	}
	qu->num++;
}

void dequeue(Que *qu)
{
	while (qu->num!=0&&flag==0)
	{
		_node *tmp = qu->front;
		qu->front = qu->front->next;
		qu->num--;
		
		int sta = tmp->sta;
		int cnt = tmp->cnt;
		delete tmp;

		if (arr[sta]!=0&&arr[sta] >= cnt)
		{
			continue;
		}


		arr[sta] = cnt;

		cnt++;

		if (sta == c)
		{
			flag = 1;
			break;
		}
		if (sta-e>=1&&(arr[sta-e] == 0 || arr[sta-e] > cnt))
		{
			
			insert(qu, sta - e, cnt);
		}
		if (sta +d<= a && (arr[sta +d] == 0 || arr[sta +d] > cnt))
		{
			
			insert(qu, sta +d, cnt);
		}

		
	}
	if (flag == 0)
	{
		flag = 2;
	}
}



int main()
{
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	Que *qu = init();


	insert(qu, b, 1);
	dequeue(qu);

	if (flag == 1)
	{
		printf("%d\n", arr[c] - 1);
	}
	else
	{
		printf("use the stairs\n");
	}
}