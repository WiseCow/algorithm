#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
 
 
 
int main()
{
     
    int N,M;
 
    scanf("%d %d", &N, &M);
    vector<int> in[101];
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);
 
        in[a].push_back(b);
        in[b].push_back(a);
    }

	int cost[101];
	int group[101] = { 0 };
	int posi[101] = { 0 };
	for (int i = 1; i <= N; i++)
		cost[i] = 987654321;

	int gcnt=0;
 
    for (int i = 1; i <= N; i++)
    {
        int visit[101] = { 0 };
        visit[i] = 1;
        queue<pair<int, int>> qu;
         
        for (int l = 0; l < in[i].size(); l++)
        {
            qu.push(make_pair(in[i][l], 1));
        }
 
        int dmax = 0;
        if (group[i] == 0)
        {
            gcnt++;
            group[i] = gcnt;
        }
        while (!qu.empty())
        {
            pair<int, int> a = qu.front();
            qu.pop();
 
            if (group[a.first] == 0)
                group[a.first] = gcnt;
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
        if (dmax < cost[group[i]])
        {
            cost[group[i]] = dmax;
            posi[group[i]] = i;
        }
    }
 
 
    priority_queue<int> a;
 
    for (int i = 1; i <= gcnt; i++)
    {
        a.push(-posi[i]);
    }
    printf("%d\n", gcnt);
    while (!a.empty())
    {
        printf("%d\n",-a.top());
        a.pop();
    }
 
    return 0;
 
 
 
}