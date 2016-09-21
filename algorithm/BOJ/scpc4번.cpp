#include <cstdio>
#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define INF 987654321
using namespace std;
int dist[100002];
int member[100002];
struct Edge {
	int from, to, cost;
	Edge(int a, int b, int c) {
		from = a;
		to = b;
		cost = c;
	}
};

bool cmp(Edge a, Edge b)
{
	return a.cost < b.cost;
}

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		memset(member, 0, sizeof(member));
		for (int i = 1; i <= N + 1; i++)
		{
			dist[i] = INF;
		}
		vector<Edge> edge;
		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edge.push_back(Edge(a, b, c));
			edge.push_back(Edge(b, a, c));
		}
		for (int i = 0; i < K; i++)
		{
			int a;
			scanf("%d", &a);
			edge.push_back(Edge(a, N + 1, 0));
			edge.push_back(Edge(N + 1, a, 0));
			member[a] = a;
		}
		dist[N + 1] = 0;
		sort(edge.begin(), edge.end(), cmp);
		for (int i = 1; i <= N + 1; i++) {
			for (int j = 0; j < (M + K) * 2; j++) {
				int x = edge[j].from;
				int y = edge[j].to;
				int z = edge[j].cost;
				if (dist[x] != INF && dist[y] > dist[x] + z) {
					dist[y] = dist[x] + z;
					if (member[x] == 0)
					{
						if (x != N + 1)
							member[y] = x;
					}
					else
					{
						member[y] = member[x];
					}
				}
			}
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		int ans = 0, ans2 = 0;
		for (int i = 1; i <= N; i++)
		{
			ans += dist[i];
			ans2 += member[i];
		}
		printf("%d\n%d\n", ans, ans2);


	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}