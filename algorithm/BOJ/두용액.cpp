#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int abs(int a)
{
	return (a) > 0 ? (a) : (-a);
}
int main()
{
	int N;
	scanf("%d",&N);
	vector<int>in(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &in[i]);
	sort(in.begin(), in.end());

	int mini = 987654321;
	int minil = 0;
	int minir = N - 1;
	int last = in[N - 1] + in[0];
	int l = 0, r = N - 1;
	while (l < r)
	{
		if (mini > abs(in[r] + in[l]))
		{

			minil = l;
			minir = r;
			mini = abs(in[r] + in[l]);
			if (mini == 0)
				break;
		}
		last = in[r] + in[l];
		if (last > 0)
		{
			last = in[r] + in[l];
			r--;
		}
		else
		{
			last = in[r] + in[l];
			l++;
		}
	}

	printf("%d %d", in[minil], in[minir]);


}