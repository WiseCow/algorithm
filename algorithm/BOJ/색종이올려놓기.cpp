//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int N;
//int D[101];
//
//struct pa
//{
//	int x, y;
//	pa(int a, int b) { x = a; y = b; }
//};
//bool cmp(const pa &a, const pa &b)
//{
//	if (a.x < b.x)
//		return 1;
//	else if(a.x > b.x)
//		return 0;
//	else
//	{
//		if (a.y < b.y)
//			return 1;
//		else return 0;
//	}
//}
//
//int main()
//{
//	scanf("%d", &N);
//
//	vector<pa> ve;
//
//	for (int i = 1; i <= N; i++)
//	{
//		int a, b;
//		scanf("%d %d", &a, &b);
//		if (a < b)
//		{
//			ve.push_back(pa(a, b));
//		}
//		else
//		{
//			ve.push_back(pa(b, a));
//		}
//	}
//
//	sort(ve.begin(), ve.end(), cmp);
//
//
//	int cx=ve[0].x, cy = ve[0].y, cnt=1;
//
//
//
//	D[0] = 1;
//
//	for (int i = 1; i < N; i++)
//	{
//		int a=0;
//		for (int j = 0; j <i; j++)
//		{
//			if (ve[i].x >= ve[j].x&&ve[i].y >= ve[j].y&&D[j]>a)
//				a = D[j];
//		}
//		D[i] = a + 1;
//	}
//
//
//	int maxx = 0;
//	for (int i = 0; i < N; i++)s
//		if (maxx < D[i]) maxx = D[i];
//
//	cout << maxx<<'\n';
//
//
//	return 0;
//
//
//}



#include<algorithm>
#include<vector>
#include<cstdio>
int N,D[101];struct pa{int x,y;pa(int a,int b){x=a;y=b;}};bool cmp(const pa &a,const pa &b){if (a.x<b.x)return 1; else if (a.x > b.x)return 0; else { if (a.y < b.y)return 1; else return 0; }}int main(){scanf("%d", &N);std::vector<pa> ve;for(int i=1;i<=N;i++){int a,b;scanf("%d %d", &a,&b);if(a<b){ve.push_back(pa(a,b));}else{ve.push_back(pa(b, a));}}sort(ve.begin(), ve.end(), cmp);int cx=ve[0].x,cy=ve[0].y,cnt=1;D[0]=1;for(int i=1;i<N;i++){int a=0;for(int j=0;j<i;j++){if(ve[i].x>=ve[j].x&&ve[i].y>=ve[j].y&&D[j]>a)a=D[j];}D[i]=a+1;}int maxx=0;for(int i=0;i<N;i++)if(maxx<D[i])maxx=D[i];printf("%d\n",maxx);return 0;}