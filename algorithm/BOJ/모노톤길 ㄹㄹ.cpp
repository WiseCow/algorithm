#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int x, y;
	node(int a, int b) {
		x = a;
		y = b;
	}
};
bool cmp(const node &a, const node &b)
{
	if (a.x > b.x)
		return 0;
	else
		if (a.x == b.x)
			if (a.y > b.y)
				return 0;
			else
				return 1;
		else
			return 1;
}


int main()
{
	int T;
	scanf("%d", &T);
	for (int itr = 0; itr < T; itr++)
	{
		int n;
		scanf("%d", &n);
		vector<node> in;
		int d[100001] = { 0 };
		int p[100001] = { 0 };
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			in.push_back(node(a, b));
			d[a]++;
		}
		sort(in.begin(), in.end(), cmp);


		int idx = 1;
		bool chk = 0;
		int now;
		int lastx, lasty;
			if (in[0].x == 0 && in[0].y == 0)
			{
				p[idx] = 0;
				lastx = in[0].x;
				lasty = in[0].y;
				now = 0;
			}
		else
		{
			p[idx] = d[0];
			chk = 1;
			lastx = in[d[0]].x;
			lasty = in[d[0]].y;
			now = d[0];
		}
		idx++;

		while (idx != n + 1)
		{
			if (chk)
			{
				now--;
				if (in[now].x == lastx)
				{
					p[idx] = now;
					lastx = in[now].x;
					lasty = in[now].y;
				}
				else
				{

				}



			}
			else
			{
				now++;
			}















			idx++;
		}





	}

}