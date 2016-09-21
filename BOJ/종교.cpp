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
//	jin*node_n1 = (jin*)malloc(sizeof(jin));//�޸� ���� �Ҵ�
//	jin*node_n2 = (jin*)malloc(sizeof(jin));
//
//	node_n1->vertex = n2;//��� 1�� j�л� �Է�
//	node_n1->link = NULL;
//
//	node_n2->vertex = n1;//��� 2�� i �л� �Է�
//	node_n2->link = NULL;
//
//	if (arr[n1] == NULL)	//���� n1�� null�̸�
//		arr[n1] = node_n1; //n1���� j �л������� ���� ����
//	else
//	{
//		for (w = arr[n1]; w->link != NULL; w = w->link);// ��ũ���� ������ �̵�
//		w->link = node_n1;//���ڸ��� �Է�
//	}
//	if (arr[n2] == NULL) arr[n2] = node_n2;//n2�� ���� ���
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
//	scanf("%d %d", &n, &m);//�л����� ���Ǽ�
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d %d", &n1, &n2);//i,j�� ���� ������.
//		insert_node(n1, n2);//����
//	}
//
//
//
//	for (i = 1; i <= n; i++)//Ž�� �Ұ���
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
	int ����;
	Jong * ����;

};

Jong * arr[50001];

void insert(int a, int b)
{
	Jong *Ja = new Jong;
	Jong *Jb = new Jong;

	Ja->���� = b;
	Ja->���� = NULL;

	Jb->���� = a;
	Jb->���� = NULL;


	if (arr[a] == NULL)
	{
		arr[a] = Ja;
	}
	else
	{
		Jong *tmp = arr[a];
		for (; tmp->���� != NULL; tmp = tmp->����);
		tmp->���� = Ja;
	}

	if (arr[b] == NULL)
	{
		arr[b] = Jb;
	}
	else
	{
		Jong *tmp = arr[b];
		for (; tmp->���� != NULL; tmp = arr[tmp->����]);
		tmp->���� = Jb;
	}
}



void find(Jong *findarr, int i, bool *visit)
{
	visit[i] = 1;

	if (findarr->���� == NULL)
	{
		visit[findarr->����] = 1;
		return;
	}
	else
	{
		Jong *tmp = findarr;
		for (; findarr!= NULL; findarr = findarr->����)
		{
				visit[findarr->����] = 1;
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

		int ���, ��;
		cin >> ��� >> ��;
		for (int i = 0; i < ��; i++)
		{
			int a, b;
			cin >> a >> b;
			insert(a, b);
		}
		bool visit[50001] = { 0 };
		int ī��Ʈ = 0;
		for (int i = 1; i <= ���; i++)
		{
			if (visit[i] == 0)
			{
				if (arr[i] != NULL)
					find(arr[i], i, visit);
				ī��Ʈ++;
			}
		}
		cout << ī��Ʈ << endl;

		for (int i = 1; i < ���; i++)
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
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

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

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}