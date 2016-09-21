
#include <iostream>
using namespace std;
int A[1000000];
int B[1000000];

int _abs(int i)
{
	return i >= 0 ? i : -i;
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int N, K;
		cin >> N >> K;
		
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
		}
		for (int i = 0; i <K; i++)
		{
			cin >> B[i];
		}
		int n_p=0, k_p=0;

		for (k_p = 0; k_p < K; k_p++)
		{
			int min=100000;
			for (int n_n = n_p; n_n <= N; n_n++)
			{
				int now = _abs(B[k_p] - A[n_n]);
				if (n_n == N)
				{
					n_p = n_n - 1;
					break;
				}
				if (now < min)
					min = now;
				else
				{
					n_p = n_n-1;
					break;
				}
			}

			if (A[n_p] - B[k_p] >= 0)
			{
				cout << "+" << A[n_p] - B[k_p]<<" ";
			}
			else
			{
				cout << A[n_p] - B[k_p]<<" ";
			}
			
		}
		cout << endl;
		





	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}