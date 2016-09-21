#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int> in[201];
bool visit[201];
int ans[201];
bool serch(int now)
{
	if (visit[now])
		return 0;
	visit[now] = 1;
	for (int i = 0; i<in[now].size(); i++)
	{
		int k = in[now][i];
		if (ans[k] == 0 || serch(ans[k]))
		{
			ans[k] = now;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		int Si;
		scanf("%d", &Si);
		for (int j = 0; j < Si; j++)
		{
			int a;
			scanf("%d", &a);
			in[i].push_back(a);
		}
	}
	int cnt=0;
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (serch(i))
			cnt++;
	}
	printf("%d\n", cnt);
}


//#include <vector>
//#include <cstring>
//#include <iostream>
//using namespace std;
// 
//int n, m,s;
//vector<int>v[201];
//bool visit[201];
//int res[201];
// 
//bool chk(int now)
//{
//    if (visit[now])return false;
//    visit[now] = 1;
//    for (auto i : v[now])
//    {
//        if (!res[i] || chk(res[i]))
//        {
//            res[i] = now;
//            return true;
//        }
//    }
//    return false;
//}
// 
//int main()
//{
//    int num;
//    scanf("%d %d", &n, &m);
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d", &s);
//        while (s--)
//        {
//            scanf("%d", &num);
//            v[i].push_back(num);
//        }
//    }
//    int cnt = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        memset(visit, 0, sizeof(visit));
//        if (chk(i))
//            cnt++;
//    }
//    printf("%d\n", cnt);
// 
// 
// 
//    return 0;
//}