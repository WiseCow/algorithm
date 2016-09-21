#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
	int st, en, ne;
	double prio;
	Node(int a, int b, int c)
	{
		st = a; en = b; ne = c;
	}
};
bool cmp(Node a, Node b)
{
	return a.prio > b.prio;
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
		int N,K;
		scanf("%d %d", &N, &K);
		vector<Node> vc;
		int arr[101] = { 0 };
		int fwork = 0;
		int swork = 987654321;
		for (int i = 0; i < N; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			vc.push_back(Node(a + 1, b, c));
			if (fwork < b)
				fwork = b;
			if (swork > a+1)
				swork = a+1;

		}
		for (int i = 0; i < K; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			for (int i = a + 1; i <= b; i++)
				arr[i]++;
		}

		bool chk = 1;
		for (int i = swork; i <= fwork; i++)
		{
			for (int k = 0; k < vc.size(); k++)
			{
				if (i >= vc[k].st&&i <= vc[k].en)
					vc[k].prio = (double)vc[k].ne/(double)(vc[k].en - i+1) *(double)100;
				else
					vc[k].prio = 0;
			}
			sort(vc.begin(), vc.end(), cmp);
			for (int n = 0;n<vc.size(); n++)
			{
				if (vc[n].prio > 0)
				{
					if (vc[n].prio > 100)
					{
						chk = 0;
						break;
					}
					arr[i]--;
					vc[n].ne--;
					if (arr[i] == 0)
						break;
				}
				else
					break;

			}

			if (chk == 0)
				break;
		}
		







		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", chk);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}