#include<iostream>
#include <time.h>
using namespace std;
#define MAX 100000

void select(int *arr, int right);
int arr[MAX];

int main(void)
{
	
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand();
	}
	double now = clock();
	select(arr, MAX);
	double finish = clock();

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << " ";

	cout << endl << "선택정렬 " << MAX << "개 소요시간 : " << finish-now << "ms" << endl;

	return 0;
}

void select(int *arr, int right)
{
	for (int i = 0; i < right; i++)
	{
		int min = i;
		for (int j = i + 1; j < right; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i)
		{
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}