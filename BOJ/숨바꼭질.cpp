#include<iostream>
#include<queue>
using namespace std;
int arr[100001];
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	queue<pair<int, int>>q;
	q.push({ a,1 });

	bool chk = 0;
	while (q.size())
	{
		int d = q.front().first;
		int c = q.front().second;
		q.pop();
		if (chk==0&&(arr[d] == 0 || arr[d] > c+1))
		{
			arr[d] = c;
			if (d == b)
			{
				chk = 1;
				continue;
			}
			if (d - 1 >= 0 && (arr[d - 1] > c+1 || arr[d-1] == 0))
				q.push({ d - 1,c + 1 });
			if (d + 1 <= 100000 && (arr[d + 1]>  c+1|| arr[d + 1]==0))
				q.push({ d + 1,c + 1 });
			if (d * 2 <= 100000 && (arr[d * 2] > c + 1|| arr[d *2]==0))
				q.push({ d * 2,c + 1 });
		}
	}
	printf("%d", arr[b]-1);
}