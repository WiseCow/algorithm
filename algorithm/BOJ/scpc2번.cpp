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
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
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
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}