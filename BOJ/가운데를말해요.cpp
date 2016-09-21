//https://www.acmicpc.net/problem/1655
#include<iostream>
#include<queue>

using namespace std;
int main()
{

	int tc;
	scanf("%d", &tc);
	priority_queue <int> min,max;
	for (int i = 1; i <= tc; i++)
	{
		int a;
		scanf("%d",&a);
		if (min.empty() || max.empty())
		{
			min.push(a);
		}
		else
		{
			if (a <= min.top())
				min.push(a);
			else if (a >= -max.top())
				max.push(-a);
			else
				min.push(a);
		}
		while (!(min.size() == max.size() || min.size() == max.size() + 1))
		{
			if (min.size() > max.size())
			{
				max.push(-min.top());
				min.pop();
			}
			else
			{
				min.push(-max.top());
				max.pop();
			}
		}
			printf("%d\n", min.top());
	}
	return 0;
}



/*
#include<iostream>
#include<vector>
using namespace std;

void push_max(vector<int>&heap, int value)
{
	heap.push_back(value);
	int idx = heap.size() - 1;
	while (idx > 0 && heap[idx] < heap[(idx - 1) / 2])
	{
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}
void push_min(vector<int>&heap, int value)
{
	heap.push_back(value);
	int idx = heap.size() - 1;
	while (idx > 0 && heap[idx] > heap[(idx - 1) / 2])
	{
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

void pop_max(vector<int>&heap)
{
	heap[0] = heap.back();
	heap.pop_back();
	int hear = 0;

	while (1)
	{
		int left = hear * 2 + 1, right = hear * 2 + 2;

		if (left >= heap.size())
			break;
		int next = hear;
		if (heap[next] > heap[left])
			next = left;
		if (right<heap.size()&&heap[next] > heap[right])
			next = right;
		if (next == hear)break;

		swap(heap[hear], heap[next]);
		hear = next;
	}




}

void pop_min(vector<int>&heap)
{

	heap[0] = heap.back();
	heap.pop_back();
	int hear = 0;


	while (1)
	{
		int left = hear * 2 + 1, right = hear * 2 + 2;

		if (left >= heap.size())
			break;

		int next = hear;
		if (heap[next] < heap[left])
			next = left;
		if (right<heap.size() && heap[next] < heap[right])
			next = right;
		if (next == hear)break;

		swap(heap[hear], heap[next]);
		hear = next;
	}




}
int main()
{

	vector<int> big;
	vector<int> small;


		int input;
		bool flag = 0;
		scanf("%d", &input);
		for (int i = 0; i < input; i++)
		{
			int a;
			scanf("%d", &a);
			if (i == 0)
			{
				push_max(big, a);
				printf("%d\n", a);
			}
			else if (i==1)
			{
				if (a >= big[0])
				{
					push_min(small, big[0]);
					pop_max(big);
					push_max(big, a);
				}
				else
				{
					push_min(small, a);
				}

				cout << small[0] << endl;
			}
			else
			{
				if (big.size()-small.size()==0)
				{
					if (a > big[0])
					{
						push_max(big, a);
					}
					else if (a > small[0] && big[0] >= a)
					{
						push_max(big, a);
					}
					else
					{
						push_max(big, small[0]);
						pop_min(small);
						push_min(small, a);
					}
				}
				else if (big.size() - small.size() == 1)
				{
					if (a > big[0])
					{
						push_min(small, big[0]);
						pop_max(big);
						push_max(big, a);
					}
					else if (a > small[0] && big[0] >= a)
					{
						push_min(small, big[0]);
						pop_max(big);
						push_max(big, a);
					}
					else
					{
						push_min(small, a);
					}
				}

				if ((i + 1) % 2 != 0)
					cout << big[0] << endl;
				else
					cout << small[0] << endl;


				//cout << "레벨 big" << big.size() << " 레벨 small" << small.size() << " big[0]" << (int)big[0] << " small[0]" << (int)small[0] << endl;
			}
		}

}
*/
//#include <iostream>
//int arr[20002], n, left, right, mid, a;
//
//int main()
//{
//	scanf("%d", &n);
//	scanf("%d", &mid);
//	arr[mid + 10000]++;
//	printf("%d\n", mid);
//	for (int i = 1; i < n; i++)
//	{
//		scanf("%d", &a);
//		arr[a + 10000]++;
//
//		if (a < mid)
//		{
//			left++;
//			while (left >= right + arr[mid + 10000] || arr[mid+10000] == 0)
//			{
//				right += arr[mid+10000];
//				mid--;
//				left -= arr[mid+10000];
//			}
//
//		}
//		else if (a > mid)
//		{
//			right++;
//			while (right >= left + 1 + arr[mid + 10000] || arr[mid + 10000] == 0)
//			{
//				left += arr[mid + 10000];
//				mid++;
//				right -= arr[mid + 10000];
//			}
//		}
//		printf("%d\n", mid);
//	}
//	return 0;
//}