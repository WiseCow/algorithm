#include <string>
#include <vector>
#include <iostream>
using namespace std;
int h, w;


struct node {
	int x, y;
	node *next;
};

struct q {
	int size;
	node *head;
	node *tail;
};
q *cre()
{
	q *newq = new q;
	newq->size = 0;
	newq->head = NULL;
	newq->tail = NULL;
	return newq;
}

void push(q *newq, int x, int y)
{
	node *newn = new node;
	newn->x = x;
	newn->y = y;
	newn->next = NULL;
	if (newq->size == 0)
	{
		newq->head = newn;
		newq->tail = newn;
	}
	else
	{
		newq->tail->next = newn;
		newq->tail = newn;
	}
	newq->size++;
}

void pop(q *newq)
{
	if (newq->size == 0)
		return;
	else
	{
		node *tem = newq->head;
		newq->head = tem->next;
		delete tem;
		newq->size--;
	}
}

struct arr {
	int x, y;
};


int fx[4] = { 0,1,0,-1 }, fy[4] = { 1,0,-1,0 };
bool chk(int a, int b)
{
	return a > 0 && b > 0 && a <= h && b <= w;
}

bool bre(bool ch[][102], char str[][102])
{
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (ch[i][j] != 1 && str[i][j] != '*')
				return false;
	return true;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char str[102][102] = { 0 };
		bool ch[102][102] = { 0 };
		arr start[10000] = { 0 };
		char key[30] = { 0 };
		int door[30] = { 0 };
		scanf("%d %d", &h, &w);
		q *myq = cre();
		int k = 0;
		for (int i = 1; i <= h; i++)
		{
			scanf("%s", &str[i][1]);
			for (int j = 1; j <= w; j++)
			{
				if (str[i][j] != '*' && (i == 1 || i == h || j == 1 || j == w))
				{
					if(str[i][j)
					start[k].x = i, start[k].y = j;
					k++;
					push(myq, i, j);
					ch[i][j] = 1;
				}
			}
		}
		scanf("%s", key);
		int len = 0;
		while (key[++len]);
		if (len != 0)
		{
			for (int i = 0; i < len; i++)
				door[key[i] - 97]++;
		}
		int cnt = 0;

		while (1)
		{
			int max = 0;
			while (myq->size != 0)
			{
				int x = myq->head->x;
				int y = myq->head->y;

				pop(myq);

				for (int i = 0; i < 4; i++)
				{
					if (chk(x + fx[i], y + fy[i]) && str[x + fx[i]][y + fy[i]] != 42 && ch[x + fx[i]][y + fy[i]] == 0)
					{
						ch[x + fx[i]][y + fy[i]] = 1;
						if (str[x + fx[i]][y + fy[i]] >95)
						{
							door[str[x + fx[i]][y + fy[i]] - 97]++;
							str[x + fx[i]][y + fy[i]] = 46;
							max++;
							push(myq, x + fx[i], y + fy[i]);
						}
						else if (str[x + fx[i]][y + fy[i]] > 60)
						{
							if (door[str[x + fx[i]][y + fy[i]] - 65] != 0)
							{
								str[x + fx[i]][y + fy[i]] = 46;
								max++;
								push(myq, x + fx[i], y + fy[i]);
							}
						}
						else
						{
							if (str[x + fx[i]][y + fy[i]] == 36)
							{
								cnt++;
								str[x + fx[i]][y + fy[i]] = 46;
								max++;
								push(myq, x + fx[i], y + fy[i]);
							}
							push(myq, x + fx[i], y + fy[i]);
						}
					}
				}
			}
			if (max)
			{
				for (int i = 1; i <= h; i++)
					for (int j = 1; j <= w; j++)
						ch[i][j] = 0;
				for (int i = 0; i < k; i++)
				{
					push(myq, start[i].x, start[i].y);
					ch[start[i].x][start[i].y] = 1;
				}
			}
			else
				break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}