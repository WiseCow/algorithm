#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
#define MAXX(a, b) ((a)>(b)) ? (a) : (b)
struct rect {
	ll x1, y1, x2, y2;
	ll size;
	rect(ll a, ll b, ll c, ll d, ll s)
	{
		x1 = a; y1 = b; x2 = c; y2 = d; size = s;
	}
};
bool cmp(const rect &a,const rect &b)
{
	return a.size < b.size;
}


int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int K, mapt[5000];
		ll N, M;
		scanf("%lld %lld %d", &N, &M, &K);
		memset(mapt, 0, sizeof(mapt));

		vector<rect> r;
		for (int i = 0; i < K; i++)
		{
			ll a, b, c, d;
			scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
			r.push_back(rect(a, b, c, d, (c - a)*(d - b)));
			mapt[i] = 1;
		}
		sort(r.begin(), r.end(), cmp);


		for (int i = 0; i < K; i++)
		{
			for (int j = 0; j < K; j++)
			{
				if (i == j)
					continue;
				if (r[i].x1 <= r[j].x1&&r[i].y1 <= r[j].y1&&r[i].x2 >= r[j].x2&&r[i].y2 >= r[j].y2)
				{
					mapt[i] = MAXX(mapt[i], mapt[j] + 1);
				}
			}
		}
		int maxxx = 0;
		for (int i = 0; i < K; i++)
		{
			maxxx = MAXX(maxxx, mapt[i]);
		}




		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", maxxx);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}

