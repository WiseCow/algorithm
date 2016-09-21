#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N, K,sx,sy;
char map1[100002];
bool co[100002];
int dx[4] = { 1,1,-1,-1 }, dy[4] = { 1,-1,1,-1 };
struct leap {
	int x, y, code;
};

vector<leap> inx,iny;
bool cmp(const leap &a, const leap &b)
{
	if (a.x < b.x)
		return 1;
	else if (a.x > b.x)
		return 0;

	if (a.y < b.y)
		return 1;
	else 
		return 0;
}
bool cmp1(const leap &a, const leap &b)
{
	if (a.y < b.y)
		return 1;
	else if (a.y > b.y)
		return 0;

	if (a.x < b.x)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d%d", &N, &K);
	scanf("%s", &map);
	scanf("%d%d", &sx, &sy);
	inx.push_back({ sx,sy ,0});
	for (int i = 1; i < N; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		inx.push_back({ a,b,i });
		iny.push_back({ a,b,i });

	}
	int a;
	sort(inx.begin(), inx.end(), cmp);
	sort(iny.begin(), iny.end(), cmp1);

	for (int i = 0; i < K; i++)
	{

	}



}