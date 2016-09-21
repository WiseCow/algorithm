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
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		int ans = 0, ans2 = 0;
		for (int i = 1; i <= N; i++)
		{
			ans += dist[i];
			ans2 += member[i];
		}
		printf("%d\n%d\n", ans, ans2);


	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}