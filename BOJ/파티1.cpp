#include<cstdio>
#include<cstring>
int N, M, X;
struct vecnode
{
	int to, from, dist;
	vecnode *next;
};
struct vec
{
	int size;
	vecnode* front;
	vecnode* rear;
	vec() {
		size = 0;
		front = NULL;
		rear = NULL;
	}
	void push(int a,int b,int c)
	{
		vecnode *t = new vecnode;
		t->from = a;
		t->to = b;
		t->dist = c;
		if (size == 0)
		{
			front = t;
			rear = t;
		}
		else
		{
			rear->next = t;
			rear = t;
		}
		size++;
	}
};
vec vc[1000];
struct node
{
	int x;
	node *next;
};
struct qu
{
	int size;
	node* front;
	node* rear;
	qu() {
		size = 0;
		front = NULL;
		rear = NULL;
	}
	bool empty()
	{
		return size;
	}
	void push(int x)
	{
		node *t = new node;
		t->x = x;
		t->next = NULL;
		if (size == 0)
		{
			front = t;
			rear = t;
		}
		else
		{
			rear->next = t;
			rear = t;
		}
		size++;
	}
	int fro()
	{
		node *t = front;
		return t->x;
	}
	void pop()
	{
		node *t = front;
		front = front->next;
		size--;
		delete t;
	}
};



int find(int st, int en)
{
	int map[1000];

	memset(map, 0x3f, sizeof(map));
	map[st] = 0;
	qu q;
	q.push(st);

	while (q.empty())
	{
		int t = q.fro();
		q.pop();
		vecnode *tmp = vc[t].front;
		for (int i = 0; i < vc[t].size; i++)
		{
			int to = tmp->to;
			int from = tmp->from;
			int dist = tmp->dist;
			if (map[to] > map[from] + dist)
			{
				map[to] = map[from] + dist;
				q.push(to);
			}
			tmp = tmp->next;
		}
	}
	return map[en];
}


int main()
{
	scanf("%d%d%d", &N, &M, &X);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vc[a-1].push(a-1, b-1, c);
	}
	

	int mx = 0;

	for (int i = 0; i < N; i++)
	{
		if (i == X - 1)
			continue;
		int t = find(i, X - 1) + find(X - 1, i);
		if (mx < t)
			mx = t;
	}
	printf("%d", mx);

}