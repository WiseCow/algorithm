#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int ccount[100000];
int numb[100000];
bool cmp(const pair<int, int> &A, const pair<int, int> &B)
{
	if (A.first < B.first)
		return 1;
	else if (A.first > B.first)
		return 0;
	else
	{
		if (A.second < B.second)
			return 1;
		else

			return 0;
	}

}


int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{

		memset(ccount, 0, sizeof(ccount));
		memset(numb, 0, sizeof(numb));

		int inputc;
		scanf("%d", &inputc);


		vector<pair<int, int>> in;
		int inputmax = 0;
		for (int i = 0; i < inputc; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			ccount[a]++;
			in.push_back(make_pair(a, b));
		}

		for (int i = 0; i <= inputmax; i++)
		{
			sort(in.begin(), in.end(), cmp);
		}

		int tx, ty;
		int i;
		bool visit[100000] = { 0 };
		bool chk = 0;
		if (in[0].first == 0 && in[0].second == 0)
		{
			tx = in[0].first;
			ty = in[0].second;
			numb[1] = 0;
			i = 1;
			visit[0] = 1;
		}
		else
		{
			i=ccount[0]-1;
			tx = in[i].first;
			ty = in[i].second;
			numb[1] = i;
			visit[i] = 1;
			i--;
			chk = 1;
		}
		int p = 2;		
		for (; p <= inputc&&i<in.size();)
		{
			if (visit[i] == 0)
			{
				if (tx == in[i].first)
				{
					if (chk == 0)
					{
						visit[i] = 1;
						tx = in[i].first;
						ty = in[i].second;
						numb[p++] = i++;
					}
					else
					{
						visit[i] = 1;
						tx = in[i].first;
						ty = in[i].second;
						numb[p++] = i--;
						if (i < 0)
							i = ccount[0];
					}
				}
				else
				{
					if (ty == in[i].second)
					{
						visit[i] = 1;
						tx = in[i].first;
						ty = in[i].second;
						numb[p++] = i++;
						chk = 0;
					}
					else
					{
						i += ccount[in[i].first]-1;
						visit[i] = 1;
						tx = in[i].first;
						ty = in[i].second;
						numb[p++] = i--;
						chk = 1;
					}
				}
			}
			else
			{
				while (visit[i] == 1)
					i++;
			}
		}
		int req;
		scanf("%d", &req);
		for (int i = 0; i < req; i++)
		{
			int a;
			scanf("%d", &a);

			printf("%d %d\n", in[numb[a]].first, in[numb[a]].second);

		}
//		cout << endl;
	}
	return 0;
}