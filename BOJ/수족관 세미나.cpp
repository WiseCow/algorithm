//#include<iostream>
//using namespace std;
//struct Line {
//	int x1, x2, y;
//	bool k;
//	Line(int x1, int x2, inty, bool k) :x1(x1), x2(x2), y(y), k(k);
//
//	const bool operator <()
//};
//struct Hole {
//	int a, b, c, d;
//};
//pair<int, int> arr[5000];
//Hole hole[5000];
//
//int main()
//{
//	scanf("%d ", &N);
//	for (int i = o; i < N; i++)
//		scanf("%d%d", &arr[i].first, &arr[i].second);
//
//	scanf("%d ", &K);
//	for (int i = 0i < K; i++)
//		scanf("%d %d %d %d", &hole[i].a, &hole[i].b, &hole[i].c, &hole[i].d)
//
//		sort(hole, hole + K);
//	int kidx = 0;
//	for (int ji = 1; i < N - 1; i += 2)
//	{
//		bool flag = false;
//		if(kidx<K&&arr[i])
//	}
//
//}



#include<algorithm>
#include<iostream>
using namespace std;
int arr[300000], N, M;
bool possi(int num )
{
	int ret = 0;
	for (int i = 0; i < M; i++)
	{
		ret = min(N+1,ret+(arr[i] / num) + (arr[i] % num != 0));
	}
	return ret <= M;


}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &arr[i]);
	}

	int le=0, ri=1e9, mid;
	int ans;
	while (ri >= le)
	{
		mid = (le + ri) / 2;
		if (possi(mid))
		{
			ans = mid;
			ri = mid - 1;

		}
		else
			le = mid + 1;
	}

	printf("%d", ans);
}

#include "bits/stdc++.h"
using namespace std;

int n, m;
int arr[300000];

bool possi(int num) {

	int ret = 0;
	for (int i = 0; i<m; i++) {
		ret = min(n + 1, ret + (arr[i] / num) + (arr[i] % num != 0));
	}
	return ret <= n;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i<m; i++)
		cin >> arr[i];
	int le, ri, mid;
	le = 0;
	ri = 1e9;
	int ans;
	while (ri >= le) {
		mid = (le + ri) / 2;
		if (possi(mid)) {
			ans = mid;
			ri = mid - 1;
		}
		else
			le = mid + 1;
	}
	printf("%d\n", ans);
	return 0;


}



#include<iostream>
int arr[300];
int D[300][300];
int win[300][300];
int N;


int solv(int left, int right)
{
	if (left == right)
		return 0;
	int &ret = D[left][right];
	if (ret != -1)return ret;
	ret = 0x3f3f3f3f;
	for (int i = left; i < right;i++)
		ret = min(ret, 
}

int main()
{
	memset(D, -1, sizeof(D));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);


	for (int i = 0; i < N; i++)
	{
		win[i][i] = arr[i];


		for (int j = i + 1; j < N; j++)
		{
			win[i][j] = min(win[i][j - 1], arr[ij]);
		}
	}
	printf("%d \n", solve(0, N));

}