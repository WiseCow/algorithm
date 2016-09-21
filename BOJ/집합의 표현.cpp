#include<iostream>
using namespace std;
int arr[1000001];
int find(int a)
{
	if (a == arr[a])
		return a;
	else
	{
		int x = find(arr[a]);
		arr[a] = x;
		return x;
	}


}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	arr[b] = a;
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <=n; i++)
		arr[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0)
			uni(b, c);
		else
		{
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}


}