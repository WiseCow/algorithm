#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

priority_queue<int, vector<int>> a,b, c,d;
int main()
{
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t1, t2;
		scanf("%d%d",&t1,&t2);

		a.push(t1);
		b.push(-t1);
		c.push(t2);
		d.push(-t2);
		printf("%d\n",min(a.top() + (-d.top()), (-b.top()) + c.top()));
	}
}