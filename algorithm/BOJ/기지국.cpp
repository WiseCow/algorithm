#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> arr[100000];
int D[100000],N;
int solve(int idx)
{
	if (idx == N)
		return 0;
	int &ret = D[idx];
	if (ret != -1)
		return ret;
	ret = 0x3f3f3f3f;
	int max_hight = 0;
	for (int i = idx; i < N; i++) {
		max_hight = max(max_hight, abs(arr[i].second));
		int width = max(max_hight * 2, arr[i].first - arr[idx].first);
		ret = min(ret, solve(i + 1) + width);
	}
	return ret;
}

int main()
{
	memset(D, -1, sizeof(D));
	scanf("%d", &N);
	printf("%d", solve(0));
}