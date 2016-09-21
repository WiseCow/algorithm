#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 20000000000
#define SIZE 1002
int n, m;
vector<pair<int, int> > Map[SIZE];
int dist[1002];
priority_queue<pair<int, int> >pq;

int main(void)
{
   scanf("%d%d", &n, &m);
   int a, b, d;
   for (int i = 0; i < m; i++)
   {
      scanf("%d%d%d", &a, &b, &d);
      Map[a].push_back(make_pair(b, d));
      Map[b].push_back(make_pair(a, d));
   }
   for (int k = 1; k <= n; k++)
   {
      memset(dist, 0x3f, sizeof(dist));
      //memset은 개빠름
      //메모리를 초기화하는거 a,b, c a배열을 b값으로 c크기만큼 초기화
      //근데 0, -1, INF == 10억6천만
      //memset(a, 0, sizeof a) -1, 0x3f
      //0x3f3f3f3f = INF
      //다른경우는 fill(arr,arr+N, data); O(N)
      dist[k] = 0;
      //출발하는 지점은 거리 0
      pq.push(make_pair(0, k));
      while (!pq.empty())
      {
         int cost = -pq.top().first;//비용
         int now=pq.top().second;//정점
         pq.pop();
         if (dist[now] < cost)
            continue;
         for (int i = 0; i < Map[now].size(); i++)
         {
            int there = Map[now][i].first;//now에서 갈수 있는 정점
            int there_cost = Map[now][i].second;//there까지 distance
            if (dist[there] > cost+there_cost)
            {
               dist[there] = cost+there_cost;
               pq.push(make_pair((-cost) + there + cost, there));
            }
         }
      }
      //다익스트라 끝
      //dist[i] //k정점부터 i정점까지의 최단거리가 다 들어있다.
      //못가면 0x3f3f3f3f값이 들어가 있다.
   }

   cout << dist[0];

   return 0;
}