#include<iostream>
using namespace std;

int n;
int heap[100002];
int hn;
void push(int x) {
	heap[++hn] = x;
	for (int i = hn; i > 1; i /= 2) {
		if (heap[i / 2] < heap[i])
			swap(heap[i / 2], heap[i]);
		else break;
	}
}

int pop() {
	int ans = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = -1987654321;

	for (int i = 1; i * 2 <= hn;) {

		if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1])
			break;
		else if (heap[i * 2] > heap[i * 2 + 1])
		{
			swap(heap[i * 2], heap[i]);
			i *= 2;
		}
		else {
			swap(heap[i], heap[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}
	return ans;
}

int main() {

	scanf("%d", &n);
	int a;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		push(a);
	}
	while (hn > 0) {
		printf("%d\n", pop());
	}
	return 0;
}