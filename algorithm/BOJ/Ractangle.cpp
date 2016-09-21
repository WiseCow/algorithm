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
	/* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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




		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n", maxxx);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

