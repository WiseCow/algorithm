#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	int mm = 1;
	int arr[32] = { 0 };

	arr[1] = 0;
	for (int i = 2; i < 32; i++)
	{
		mm *= 2;
		arr[i] = arr[i - 1] + mm;
	}



	for (test_case = 1; test_case <= T; test_case++) {
		int K;
		scanf("%d", &K);
		printf("Case #%d\n", test_case);
		K--;
		while (K >= 0)
		{
			if (K == 0)
			{
				printf("4");
					break;
			}
			if (K == 1)
			{
				printf("7");
				break;
			}


			int p = 1;
			while (K >= arr[p])
				p++;

			int t = K - arr[p - 1];
			int mt = (arr[p] - arr[p - 1])/2;
			if (t+1 > mt)
			{
				printf("7");
				K -= mt * 2;
			}
			else
			{
				printf("4");
				K -= mt;
			}


		}

		printf("\n");
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}