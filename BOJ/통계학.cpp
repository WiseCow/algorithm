#include<iostream>
#define rev 4000
#define min(a,b) ((a)<(b))?a:b
#define max(a,b) ((a)>(b))?a:b
using namespace std;
long long sum;
int num[8003];
int N;
int mi, mx;
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		sum += a;
		num[a + rev]++;
		if (i == 0) { mi = a; mx = a; }
		mi=min(mi, a);
		mx=max(mx, a);
	}

	printf("%.0lf\n", (double)sum / N);

	int c=0;
	int ma=mi;
	int mac=num[mi+rev];


	int find = N/2+1;
	int findsum=0;
	for (int i = mi; i <= mx; i++)
	{		
		if (findsum + num[i + rev]>= find&&findsum < find)
			printf("%d\n", i);
		findsum += num[i + rev];
		if (mac <= num[i + rev])
		{
			if (mac == num[i + rev])
			{
				c++;
				if (c == 2)
					ma = i;

			}
			else
			{
				ma = i;
				mac = num[i + rev];
				c = 1;
			}
		}
	}
	printf("%d\n", ma);
	printf("%d\n", mx - mi);

}