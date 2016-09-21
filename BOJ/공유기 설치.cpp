#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, c;

bool chk(vector<int> &a, int now)
{
	int prev = a[0],cnt=1;
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] - prev >= now)
		{
			cnt++;
			prev = a[i];
		}
	}

	return cnt >= c;
}
int main()
{
	scanf("%d %d", &n, &c);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	sort(a.begin(), a.end());

	int l = 0, r = a[n - 1];

	int ans=0;

	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (chk(a,mid))
		{

			if (ans < mid)
			{
				ans = mid;
			}

			l = mid+1;

		}
		else
		{
			r = mid - 1;
		}
	}

	printf("%d", ans);

}



//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//bool possible(vector<int> &a, int c, int x) {
//	int cnt = 1;
//	int last = a[0];
//	for (int house : a) {
//		if (house - last >= x) {
//			cnt += 1;
//			last = house;
//		}
//	}
//	return cnt >= c;
//}
//int main()
//{
//	int n, c;
//	scanf("%d %d", &n, &c);
//	vector<int> a;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		scanf("%d", &x);
//		a.push_back(x);
//	}
//	sort(a.begin(), a.end());
//
//	int l = 1;
//	int r = a[n - 1] - a[0];
//
//	int ans = l;
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		if (possible(a, c, mid)) {
//			if (ans < mid) {
//				ans = mid;
//			}
//			l = mid + 1;
//		}
//		else {
//			r = mid - 1;
//		}
//	}
//
//	cout << ans << '\n';
//	return 0;
//}