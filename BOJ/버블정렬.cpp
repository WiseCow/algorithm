#include<iostream>
#include <time.h>
using namespace std;
#define MAX 100000

void bubble(int *arr, int right);
int arr[MAX];
int main(void)
{

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand();
	}
	double now = clock();
	bubble(arr, MAX);
	double finish = clock();

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << " ";

	cout << endl << "버블정렬 " << MAX << "개 소요시간 : " << finish - now << "ms" << endl;

	return 0;
}

void bubble(int *arr, int right)
{
	for (int i = 0; i < right-1; i++)
	{
		for (int j = 0; j < right -i -1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}