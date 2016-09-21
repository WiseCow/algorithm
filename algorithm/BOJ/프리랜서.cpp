

#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXX(a,b) ((a)>(b))?(a):(b)
using namespace std;[]
int map[2][10001], D[2][10001],N;
int sol(int p,int now)
{
	if (now >= N+1)return 0;
	int &ret = D[p][now];
	if (ret != -1)return ret;
	ret = 0;
	
	if (now == 0)
	{
		ret = sol(0, 1);
		ret = MAXX(ret, sol(1, 1));
		ret = MAXX(ret, sol(0, 2) + map[1][1]);
		ret = MAXX(ret, sol(1, 2) + map[1][1]);
	}
	else
	{
		if (p == 0)
		{
			ret = sol(0, now + 1) + map[0][now];
			ret = MAXX(ret, sol(1, now + 1) + map[0][now]);
		}
		else
		{
			if (now == N)
			{
				ret = 0;
				return ret;
			}
			ret = sol(0, now + 2) + map[1][now+1];
			ret = MAXX(ret, sol(1, now + 2) + map[1][now + 1]);
		}
	}

	return ret;
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
		scanf("%d", &N);
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= N; i++)
			scanf("%d", &map[0][i]);
		for (int i = 1; i <= N; i++)
			scanf("%d", &map[1][i]);
		memset(D, -1, sizeof(D));
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", sol(0,0));
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}