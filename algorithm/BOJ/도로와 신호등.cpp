#include<cstdio>
#include<vector>
using namespace std;
int N, L,res,idx;
struct Node
{
	int D,R,G;
}; 
int main()
{
	scanf("%d%d", &N, &L);

	vector<Node> vc(N);
	for (int i = 0; i < N; i++)scanf("%d%d%d", &vc[i].D, &vc[i].R, &vc[i].G);
	for (int i = 1; i <= L; i++)
	{
		res++;
		if (idx<vc.size()&&vc[idx].D == i)
		{
			int k = res % (vc[idx].G + vc[idx].R);
			if (k < vc[idx].R)
				res += vc[idx].R - k;
			idx++;
		}
			
	}
	printf("%d\n", res);
}
