#include<iostream>
#include<queue>
using namespace std;
int arr[6] = { 0,1,2,3,4,5 };
int res = 0, bfsres = 0 ;
int dfsresns=0;
struct Node { int sum, arr[10],jari; };
queue<Node> q;

void dfs(int now,int ja, int sum, int map[10])
{
	if (sum == 5)
	{
		for (int i = 1; i < ja; i++)
			printf("%d ", map[i]);

		printf("\n");
		res++;
	}
	else if (sum > 5)
		return;

	int res = 0;
	for (int i = 1; i <= 5; i++)
	{
		map[ja] = i;
		dfs(i, ja + 1, sum + arr[i], map);
	}

}
void dfsnd(int now, int ja, int sum, int map[10],bool visit[10])
{
	if (sum == 5)
	{
		for (int i = 1; i < ja; i++)
			printf("%d ", map[i]);

		printf("\n");
		dfsresns+=1;
	}
	else if (sum > 5)
		return;

	int res = 0;
	for (int i = now+1; i <= 5; i++)
	{
		if (visit[i])
			continue;
		visit[i] = 1;
		map[ja] = i;
		dfsnd(i, ja + 1, sum + arr[i], map,visit);
		map[ja] = 0;
		visit[i] = 0;
	}

}

void bfs()
{


	for (int i = 1; i <= 5; i++)
	{
		Node a;
		a.sum = i;
		a.arr[1] = i;
		a.jari = 1;
		q.push(a);
	}
	while (q.size())
	{
		Node tmp = q.front();
		q.pop();

		if (tmp.sum == 5)
		{
			for (int i = 1; i <= tmp.jari; i++)
			{
				printf("%d ", tmp.arr[i]);
			}
			bfsres++;
			printf("\n");
			continue;
		}
		else if (tmp.sum > 5)
			continue;
		for (int i = 1; i <= 5; i++)
		{
			if ((tmp.sum) + i <= 5)
			{
				Node tt;
				tt.jari = (tmp.jari)+1;

				for (int k = 1; k <= tmp.jari; k++)
				{
					tt.arr[k]=tmp.arr[k];
				}
				tt.arr[tt.jari] = i;
				tt.sum = (tmp.sum)+ i;
				q.push(tt);
			}
		}
	}
}




int main()
{
	for (int i = 1; i <= 5; i++)
	{
		int map[10];
		map[1] = i;
		//dfs(i,2,arr[i],map);
	}
	printf("\ndfs 개수 %d\n\n", res);
	//bfs();
	printf("\n\n bfs개수 %d\n\n", bfsres);
	
	for (int i = 1; i <= 5; i++)
	{
		int map[10];
		bool visit[10] = { 0 };
		map[1] = i;
		visit[i] = 1;
		dfsnd(i, 2, arr[i], map, visit);
		visit[i] = 0;
	}
	printf("\n%d\n", dfsresns);
}