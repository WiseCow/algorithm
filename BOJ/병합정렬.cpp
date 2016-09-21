//void merge_sort(int array[], int left, int right);   //���� �Լ�
//void merge(int num[], int left, int mid, int right);   //���� �Լ�
//
//const int ITEMSIZE = 6;
//int result[ITEMSIZE];
//
//int main(void)
//{
//	int array[ITEMSIZE] = { 3, 8, 0, 2, 1, 4 };
//	merge_sort(array, 0, ITEMSIZE - 1);
//}
//
//void merge_sort(int array[], int left, int right)
//{
//	int mid;
//
//	// ������ �� ���� �ʾ��� ��� if �� ����  
//	if (left < right){
//		mid = (left + right) / 2;
//
//		merge_sort(num, left mid);      //���� ��� ����
//		merge_sort(num, mid + 1, right);  //������ ��� ����
//		merge(num, left, mid, right);   //���ҵ� ��� ����
//	}
//}
//
//void merge(int array[], int left, int mid, int right)
//{
//	int i, j, k, m;
//
//	i = left;
//	j = mid + 1;
//	k = left;    //��� �迭�� �ε���
//
//	//left���� mid ������ ��ϰ� mid+1���� right������ ����� ���� ���ϴ� �κ�
//	while (i <= mid && j <= right)
//	{
//		if (array[i] < array[j])
//		{   //left index ���� right index ������ ������ left index ���� ��� result�� ����
//			result[k] = array[i];
//			i++;
//			k++;
//		}
//		else
//		{        //�ƴ϶�� right index ���� ��� result�� ����
//			result[k] = num[j];
//			j++;
//			k++;
//		}
//	}
//
//	// left ����� ���� �� ó���Ǿ��µ� right ����� index�� ���� �������� ���
//	// right index�� ���������� ��� result�� ����
//	if (i > mid)
//	{
//		for (m = j; m <= right; m++){
//			result[k] = array[m];
//			k++;
//		}
//	}
//	else
//	{                    // left ����� index�� ���� �������� ��� left index�� ���������� ��� result�� ���� 
//		for (m = i; m <= mid; m++){
//			result[k] = array[m];
//			k++;
//		}
//	}
//}



#include<iostream>
#include <time.h>
using namespace std;
#define MAX 100000

void marge(int *arr, int left, int right);
void marge_sort(int *arr, int left, int mid, int right);

int arr[MAX];
int main(void)
{
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand();
	}

	double now = clock();
	marge(arr, 0, MAX-1);
	double finish = clock();

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << " ";

	cout <<endl<< "�������� " << MAX << "�� �ҿ�ð� : " <<finish-now <<"ms"<< endl;

	return 0;
}

void marge(int *arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		marge(arr, left, mid);
		marge(arr, mid + 1, right);
		marge_sort(arr, left, mid, right);
	}
}
void marge_sort(int *arr, int left, int mid, int right)
{
	int tmp[MAX] = { 0 };
	int l_p = left;
	int r_p = mid+1;
	int arr_p = left;

	while (l_p <= mid&&r_p <= right)
	{
		if (arr[l_p] < arr[r_p])
		{
			tmp[arr_p++] = arr[l_p++];
		}
		else
		{
			tmp[arr_p++] = arr[r_p++];
		}
	}
	if (l_p <= mid)
	{
		while (l_p <= mid)
		{
			tmp[arr_p++] = arr[l_p++];
		}

	}
	else
	{
		while (r_p <= right)
		{
			tmp[arr_p++] = arr[r_p++];
		}
	}
	l_p = left;
		while (l_p <= right)
	{
		arr[l_p] = tmp[l_p];
		l_p++;
	}
}