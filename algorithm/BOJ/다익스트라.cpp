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
      //memset�� ������
      //�޸𸮸� �ʱ�ȭ�ϴ°� a,b, c a�迭�� b������ cũ�⸸ŭ �ʱ�ȭ
      //�ٵ� 0, -1, INF == 10��6õ��
      //memset(a, 0, sizeof a) -1, 0x3f
      //0x3f3f3f3f = INF
      //�ٸ����� fill(arr,arr+N, data); O(N)
      dist[k] = 0;
      //����ϴ� ������ �Ÿ� 0
      pq.push(make_pair(0, k));
      while (!pq.empty())
      {
         int cost = -pq.top().first;//���
         int now=pq.top().second;//����
         pq.pop();
         if (dist[now] < cost)
            continue;
         for (int i = 0; i < Map[now].size(); i++)
         {
            int there = Map[now][i].first;//now���� ���� �ִ� ����
            int there_cost = Map[now][i].second;//there���� distance
            if (dist[there] > cost+there_cost)
            {
               dist[there] = cost+there_cost;
               pq.push(make_pair((-cost) + there + cost, there));
            }
         }
      }
      //���ͽ�Ʈ�� ��
      //dist[i] //k�������� i���������� �ִܰŸ��� �� ����ִ�.
      //������ 0x3f3f3f3f���� �� �ִ�.
   }

   cout << dist[0];

   return 0;
}