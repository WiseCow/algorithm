#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 1987654321;
int d[100002];
vector< pair<int, int> >gra[100002];
int pa[100002];

int main(int argc, char** argv) {


	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);   // Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {

		memset(pa, 0, sizeof(pa));
		memset(d, 0, sizeof(0));
		int n, m, k, a, b, c;
		scanf("%d %d %d", &n, &m, &k);

		int sum = 0, dsum = 0;
		for (int i = 1; i <= n; i++)
			d[i] = inf;

		for (int i = 0; i < m; i++) {

			scanf("%d %d %d", &a, &b, &c);
			gra[a].push_back(make_pair(b, c));
			gra[b].push_back(make_pair(a, c));
		}

		for (int i = 0; i < k; i++)
		{
			scanf("%d", &a);
			pa[a] = a;
			gra[n + 1].push_back(make_pair(a, 0));
			gra[a].push_back(make_pair(n + 1, 0));
		}


		priority_queue< pair<int, int> >pq;
		pq.push(make_pair(0, n + 1));
		pa[n + 1] = n + 1;

		while (pq.size())
		{
			int weight = -pq.top().first;
			int node = pq.top().second;
			pq.pop();

			for (int j = 0; j < gra[node].size(); j++)
			{
				int to = gra[node][j].first;
				int cost = gra[node][j].second;
				if (weight + cost < d[to])
				{
					d[to] = weight + cost;
					if (pa[node] != n + 1) pa[to] = pa[node];
					pq.push(make_pair(-(d[to]), to));
				}

			}
		}


		printf("Case #%d\n", test_case);

		for (int i = 1; i <= n; i++)
		{
			sum += d[i];
			dsum += pa[i];
		}
		cout << sum << '\n' << dsum << '\n';

		for (int i = 1; i <= n + 1; i++)
			gra[i].clear();
	}
	return 0;   // 정상종료 시 반드시 0을 리턴해야 합니다.

}