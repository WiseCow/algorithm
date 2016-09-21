#include <cstdio>
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
	long long i; int cnt; Node(long long a, int b) { i = a; cnt = b; }
};
vector<long long> vc[65];
priority_queue<long long>pq[65];
queue<Node> q;
int last = 0;

bool cmp(long long a, long long b)
{
	return a > b;
}
void bfs(int F)
{
	pq[0].push(-1);
	for (int i = 0; i < vc[last].size(); i++)
	{
		q.push(Node(vc[last][i],last ));
	}
	while (q.size())
	{
		long long a= q.front().i;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt > F)
			break;

		if (a * 2<= (-pq[cnt].top())*1000)
		{
			pq[cnt + 1].push(-a * 2);
			q.push(Node(a * 2, cnt + 1));
			vc[cnt + 1].push_back(a * 2);
		}

		if (((a - 1) % 3==0)&& ((a - 1) / 3)%2 == 1&& ((a - 1) / 3) != 1)
		{
			if ((a - 1) / 3 <= (-pq[cnt].top()*1000))
			{
				pq[cnt + 1].push(-((a - 1) / 3));
				q.push(Node(((a - 1) / 3), cnt + 1));
				vc[cnt + 1].push_back(((a - 1) / 3));
			}
		}	
	}
}
int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� �������
	������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	vc[0].push_back(1);
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.

	int arr[40];
	int nx=0;
	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &arr[i]);
		if (nx < arr[i])
			nx = arr[i];
	}
	bfs(nx);

	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		

		unsigned long long k = 1;
		k <<= arr[test_case];

		printf("%lld %llu\n", -pq[arr[test_case]].top(),k);


	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}