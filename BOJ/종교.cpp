//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct jin{
//	int vertex;
//	struct jin * link;
//}jin;
//
//jin*arr[50001];
//int count = 0;
//int visit[50001] = { 0, };
//
//void insert_node(int n1, int n2)
//{
//	jin*w = NULL;
//
//	jin*node_n1 = (jin*)malloc(sizeof(jin));//메모리 동적 할당
//	jin*node_n2 = (jin*)malloc(sizeof(jin));
//
//	node_n1->vertex = n2;//노드 1에 j학생 입력
//	node_n1->link = NULL;
//
//	node_n2->vertex = n1;//노드 2에 i 학생 입력
//	node_n2->link = NULL;
//
//	if (arr[n1] == NULL)	//전역 n1이 null이면
//		arr[n1] = node_n1; //n1에는 j 학생에대한 간선 연결
//	else
//	{
//		for (w = arr[n1]; w->link != NULL; w = w->link);// 링크따라 끝까지 이동
//		w->link = node_n1;//그자리에 입력
//	}
//	if (arr[n2] == NULL) arr[n2] = node_n2;//n2도 같은 방법
//	else
//	{
//		for (w = arr[n2]; w->link; w = w->link);
//		w->link = node_n2;
//	}
//}
//
//void dfs_node(jin*vertex, int num)
//{
//	jin*w = vertex;
//	visit[num] = 1;
//	for (; w != NULL; w = w->link)
//	{
//		if (visit[w->vertex] != 1)
//			dfs_node(arr[w->vertex], w->vertex);
//	}
//}
//
//int main(void)
//{
//	int n, m;
//	int n1, n2;
//	int i;
//	scanf("%d %d", &n, &m);//학생수와 쌍의수
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d %d", &n1, &n2);//i,j가 같은 종교다.
//		insert_node(n1, n2);//삽입
//	}
//
//
//
//	for (i = 1; i <= n; i++)//탐색 할것임
//	{
//		if (visit[i] == 0)
//		{
//			dfs_node(arr[i], i);
//			count++;
//		}
//	}
//	printf("%d", count);
//
//}
/*
#include <iostream>
#include <math.h>

using namespace std;


struct Jong
{
	int 정점;
	Jong * 다음;

};

Jong * arr[50001];

void insert(int a, int b)
{
	Jong *Ja = new Jong;
	Jong *Jb = new Jong;

	Ja->정점 = b;
	Ja->다음 = NULL;

	Jb->정점 = a;
	Jb->다음 = NULL;


	if (arr[a] == NULL)
	{
		arr[a] = Ja;
	}
	else
	{
		Jong *tmp = arr[a];
		for (; tmp->다음 != NULL; tmp = tmp->다음);
		tmp->다음 = Ja;
	}

	if (arr[b] == NULL)
	{
		arr[b] = Jb;
	}
	else
	{
		Jong *tmp = arr[b];
		for (; tmp->다음 != NULL; tmp = arr[tmp->정점]);
		tmp->다음 = Jb;
	}
}



void find(Jong *findarr, int i, bool *visit)
{
	visit[i] = 1;

	if (findarr->다음 == NULL)
	{
		visit[findarr->정점] = 1;
		return;
	}
	else
	{
		Jong *tmp = findarr;
		for (; findarr!= NULL; findarr = findarr->다음)
		{
				visit[findarr->정점] = 1;
		}
	}
	
}
int main()
{

	int nCount;		
	cin >> nCount;	

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int 사람, 쌍;
		cin >> 사람 >> 쌍;
		for (int i = 0; i < 쌍; i++)
		{
			int a, b;
			cin >> a >> b;
			insert(a, b);
		}
		bool visit[50001] = { 0 };
		int 카운트 = 0;
		for (int i = 1; i <= 사람; i++)
		{
			if (visit[i] == 0)
			{
				if (arr[i] != NULL)
					find(arr[i], i, visit);
				카운트++;
			}
		}
		cout << 카운트 << endl;

		for (int i = 1; i < 사람; i++)
		{
			delete arr[i];
			arr[i] = NULL;
		}
	}

	return 0;	

}
*/

#include <iostream>
using namespace std;


struct Graphenode
{
	int voltex;
	Graphenode *list;
};


Graphenode *student[50001];



void insert(int a, int b)
{
	Graphenode *n = NULL;

	Graphenode *n1 = new Graphenode;
	n1->voltex = b;
	n1->list = NULL;

	Graphenode *n2 = new Graphenode;
	n2->voltex = a;
	n2->list = NULL;


	if (student[a] == NULL)
		student[a] = n1;

	else
	{
		n = student[a];
		n1->list = n;
		student[a] = n1;
	}


	if (student[b] == NULL)
		student[b] = n2;

	else
	{
		n = student[b];
		n2->list = n;
		student[b] = n2;
		
	}

}


void dfs(int i, bool visit[50001])
{
	Graphenode *tmp = student[i];
	visit[i] = 1;
	for (; tmp; tmp = tmp->list)
	{
		if (visit[tmp->voltex] == 0)
		{
			dfs(tmp->voltex, visit);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			insert(a, b);
		}

		bool visit[50001] = { 0 };
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0)
			{
				dfs(i, visit);
				cnt++;

			}
		}


		cout << cnt << endl;


		for (int i = 1; i <= n; i++)
		{
			delete student[i];
			student[i] = NULL;
		}
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}