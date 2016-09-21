#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> in;
int main()
{
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		in.push_back(a);
	}
	sort(in.begin(), in.end());

	scanf("%d", &M);
	for (int a = 0; a < M; a++)
	{
		int input;
		scanf("%d", &input);
		int l = 0;
		int r = in.size();
		int ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (mid >= in.size())
				break;
			if (in[mid] <= input)
			{
				if (ans < mid)
					ans = mid;
				l = mid+1;
			}
			else
			{
				r = mid - 1;
			}
		}
		printf("%d\n", in[ans] == input);
	}


}