#include <cstdio>
#include <iostream>
#include <cstring>
#define div 1000000009
using namespace std;
int map[50001][102];
int boom[50001];
bool chk[50001][102];
int sum[50001];
int N, K, L;

int find(int now, int jmp)
{
	if (now - jmp == 0)
	{
		map[now][jmp] = 1;
		chk[now][jmp] = 1;
		return 1;
	}
	if (chk[now][jmp])
		return map[now][jmp];
	chk[now][jmp] = 1;
	int &res = map[now][jmp];
	for (int i = K; i >= 1; i--)
	{
		if (now - jmp - i >= 0 && !boom[now - jmp - i] && jmp != i)
		{
			res += find(now - jmp, i);
			res %= div;
		}
	}
	res %= div;
	return res;
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

		scanf("%d %d %d", &N, &K, &L);
		memset(map, 0, sizeof(map));
		memset(sum, 0, sizeof(sum));
		memset(boom, 0, sizeof(boom));
		
		for (int i = 0; i < L; i++)
		{
			int a;
			scanf("%d", &a);
			boom[a] = 1;
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		int ans = 0;
		/*for (int i = K; i >= 1; i--)
		{
			if(N-i>=0&&boom[N-i]==0)
				ans += find(N, i);
			ans %= div;
		}*/


		for (int i = 1; i <= N; i++)
		{
			if (boom[i])
				continue;
			for (int j = 1; j <= K; j++)
			{
				if (i - j == 0)
				{
					map[i][j] = 1;
					sum[i] += 1;
				}
				else if(i - j < 0)
					break;
				else
				{
					if (sum[i - j] - map[i - j][j] <= 0)
					{
						map[i][j] = sum[i - j] + div - map[i - j][j];
						map[i][j] %= div;						
					}
					else
						map[i][j] = sum[i - j] - map[i - j][j];
					map[i][j] %= div;
					sum[i] += map[i][j];
					sum[i] %= div;
				}
			}
			sum[i] %= div;
		}
		printf("%d\n",sum[N]);
	}
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}