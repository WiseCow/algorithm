#include<iostream>
using namespace std;
int hn,n, heap[100002];

void push(int x)
{
	heap[++hn] = x;
	for (int i = hn; i > 1; i /= 2)
	{
		if (heap[i / 2] < heap[i])
			swap(heap[i / 2], heap[i]);
		else
			break;
	}
}
int pop()
{
	int ans = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = -987654321;

	for (int i = 1; i * 2 <= hn;)
	{
		if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1])
			break;
		else if (heap[i * 2] > heap[i * 2 + 1])
		{
			swap(heap[i], heap[i * 2]);
			i *= 2;
		}
		else
		{
			swap(heap[i], heap[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}

	return ans;

}



int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int k;
		scanf("%d", &k);
		push(-k);
	}
	int sum = 0;
	while (hn!=1)
	{
		int a = -pop();
		int b = -pop();
		push(-(a + b));
		sum += a + b;
	}
	printf("%d",sum);
}