#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX(a,b) a>b?a:b
using namespace std;

int n,t;
char buf[1 << 18];
int idx, nidx,maxx;
vector<int> vc;
static inline char read()
{
	if (idx == nidx)
	{
		nidx = fread(buf, 1, 1 << 18, stdin);
		idx = 0;
	}
	return buf[idx++];
}
static inline int readInt()
{
	int sum = 0;
	char now = read();
	while (now == ' ' || now == '\n')
		now = read();

	while (now != ' '&&now != '\n'&&now!=EOF)
	{
		sum *= 10;
		sum += now - '0';
		now = read();
	}
	return sum;
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&t);
		int k = lower_bound(vc.begin(), vc.end(),t) - vc.begin();
		if (vc.size() <= k)
			vc.push_back(t);
		else
			vc[k] = t;
	}
	printf("%d", vc.size());
}