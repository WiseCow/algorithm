#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int ggroup[101];
int cost[101];
int posi[101];
int gp;



int main()
{
	
	int man,group;

	scanf("%d %d", &man, &group);


	vector<int> in[101];
	for (int i = 0; i < group; i++)
	{
		int a, b;
		scanf("%d %d",&a,&b);

		in[a].push_back(b);
		in[b].push_back(a);
	}
	memset(cost, 0x3f, sizeof(cost));


	for (int i = 1; i <= man; i++)
	{
		int visit[101] = { 0 };
		visit[i] = 1;
		queue<pair<int, int>> qu;
		
		for (int l = 0; l < in[i].size(); l++)
		{
			qu.push(make_pair(in[i][l], 1));
		}

		int dmax = 0;
		if (ggroup[i] == 0)
		{
			gp++;
			ggroup[i] = gp;
		}
		while (!qu.empty())
		{
			pair<int, int> a = qu.front();
			qu.pop();

			if (ggroup[a.first] == 0)
				ggroup[a.first] = gp;
			if (visit[a.first] == 0)
			{
				visit[a.first] = 1;
				if (dmax < a.second)
					dmax = a.second;
				for (int l = 0; l < in[a.first].size(); l++)
				{
					qu.push(make_pair(in[a.first][l], a.second + 1));
				}
			}
		}
		if (dmax < cost[ggroup[i]])
		{
			cost[ggroup[i]] = dmax;
			posi[ggroup[i]] = i;
		}
	}


	priority_queue<int> a;

	for (int i = 1; i <= gp; i++)
	{
		a.push(-posi[i]);
	}
	printf("%d\n", gp);
	while (!a.empty())
	{
		printf("%d\n",-a.top());
		a.pop();
	}

	return 0;



}



//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//int dist[101][101];
//int cnt[101];
//int posi[101];
//int district[101];
//int qpqp[101][101];
//int kkk[101];
//
//int num = 1;
//int main()
//{
//	int man;
//	scanf("%d", &man);
//
//	vector<int> arr[101];
//	int tc;
//	scanf("%d", &tc);
//	for (int i = 1; i <= man; i++)
//		arr[i].push_back(i);
//	for (int i = 0; i < tc; i++)
//	{
//		int a, b;
//		scanf("%d %d", &a, &b);
//
//		arr[a].push_back(b);
//		arr[b].push_back(a);
//	}
//
//	memset(dist, 10000, sizeof(dist));
//
//	for (int i = 1; i <= man; i++)
//	{
//		
//		priority_queue<pair<int, int>> q;
//		dist[i][i] = 0;
//		for (int k = 0; k < arr[i].size(); k++)
//		{
//			q.push(make_pair(arr[i][k], 1));
//		}
//		while (!q.empty())
//		{
//			pair<int, int> a = q.top();
//			q.pop();
//			if (dist[i][a.first]>a.second)
//			{
//				dist[i][a.first] = a.second;
//				for (int p = 0; p < arr[a.first].size(); p++)
//				{
//					if (dist[i][arr[a.first][p]]>a.second)
//					{
//						q.push(make_pair(arr[a.first][p], a.second + 1));
//					}
//				}
//			}
//		}
//
//		for (int k = 1; k <= man; k++)
//		{
//			if (dist[i][k] != 269488144 && kkk[i] < dist[i][k])
//				kkk[i] = dist[i][k];
//		}
//
//	}
//
//	int arl[101] = { 0 };
//	int mini[101] = { 0 };
//
//	int visit[101] = { 0 };
//
//
//	for (int i = 1; i <= man; i++)
//	{
//		if (visit[i] == 0)
//		{
//			for (int k = 1; k <= man; k++)
//			{
//				if (dist[i][k] != 269488144)
//				{
//					visit[k] = 1;
//					district[k] = num;
//				}
//			}
//			num++;
//		}
//	}
//
//	priority_queue<int> wow;
//	for (int i = 1; i < num; i++)
//	{
//		mini[i] = 999999;
//		for (int l = 1; l <= man; l++)
//		{
//			if (district[l] == i)
//			{
//				if (kkk[l] <= arl[i] || arl[i] == 0)
//				{
//					if (arl[i] == kkk[l])
//					{
//						if(mini[i]>l)
//							mini[i] = l;
//					}
//					else
//					{
//						mini[i] = l;
//						arl[i] = kkk[l];
//
//					}
//					
//				}
//
//			}
//		}
//		wow.push(-mini[i]);
//	}
//
//	
//	cout << num << '\n';
//	while (!wow.empty())
//	{
//		printf("%d\n", -wow.top());
//		wow.pop();
//	}
//
//
//	return 0;
//
//
//}