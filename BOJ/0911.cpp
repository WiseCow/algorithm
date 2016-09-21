#include<iostream>
using namespace std;

typedef struct tree
{
	int use;
	int t1;
	int t1_d;
	int t2;
	int t2_d;
	int t3;
	int t3_d;
	int t4;
	int t4_d;
}Tree;



int main()
{
	int tc;
	cin >> tc;
	
	for (int tcc = 0; tcc < tc; tcc++)
	{
		tree T[2001] = { 0 };
		int result = 0;
		int Tn;
		cin >> Tn;
		for (int p = 1; p < Tn; p++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			result += a;
			if (T[b].use == 0)
			{
				T[b].use = 1;
				T[b].t1 = c;
				T[b].t1_d = a;
			}
			else
			{
				if (T[b].use == 1)
				{
					T[b].use = 2;
					T[b].t2 = c;
					T[b].t2_d = a;
				}
				else if (T[b].use == 2)
				{
					T[b].use = 3;
					T[b].t3 = c;
					T[b].t3_d = a;
				}
				else if (T[b].use == 3)
				{
					T[b].use = 4;
					T[b].t4 = c;
					T[b].t4_d = a;
				}
			}
			if (T[c].use == 0)
			{
				T[c].use = 1;
				T[c].t1 = b;
				T[c].t1_d = a;
			}
			else
			{
				if (T[c].use == 1)
				{
					T[c].use = 2;
					T[c].t2 = b;
					T[c].t2_d = a;
				}
				else if (T[c].use == 2)
				{
					T[c].use = 3;
					T[c].t3 = b;
					T[c].t3_d = a;
				}
				else if (T[c].use == 3)
				{
					T[c].use = 4;
					T[c].t4 = b;
					T[c].t4_d = a;
				}
			}
		}

		cout << "#" << tcc + 1 << " "<<result<<endl;
	}

	return 0;

}