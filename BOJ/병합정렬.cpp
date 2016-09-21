//void merge_sort(int array[], int left, int right);   //분할 함수
//void merge(int num[], int left, int mid, int right);   //병합 함수
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
//	// 분할이 다 되지 않았을 경우 if 문 실행  
//	if (left < right){
//		mid = (left + right) / 2;
//
//		merge_sort(num, left mid);      //왼쪽 블록 분할
//		merge_sort(num, mid + 1, right);  //오른쪽 블록 분할
//		merge(num, left, mid, right);   //분할된 블록 병합
//	}
//}
//
//void merge(int array[], int left, int mid, int right)
//{
//	int i, j, k, m;
//
//	i = left;
//	j = mid + 1;
//	k = left;    //결과 배열의 인덱스
//
//	//left부터 mid 까지의 블록과 mid+1부터 right까지의 블록을 서로 비교하는 부분
//	while (i <= mid && j <= right)
//	{
//		if (array[i] < array[j])
//		{   //left index 값이 right index 값보다 작으면 left index 값을 결과 result에 복사
//			result[k] = array[i];
//			i++;
//			k++;
//		}
//		else
//		{        //아니라면 right index 값을 결과 result에 복사
//			result[k] = num[j];
//			j++;
//			k++;
//		}
//	}
//
//	// left 블록의 값은 다 처리되었는데 right 블록의 index가 아직 남아있을 경우
//	// right index를 순차적으로 결과 result에 복사
//	if (i > mid)
//	{
//		for (m = j; m <= right; m++){
//			result[k] = array[m];
//			k++;
//		}
//	}
//	else
//	{                    // left 블록의 index가 아직 남아있을 경우 left index를 순차적으로 결과 result에 복사 
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

	cout <<endl<< "병합정렬 " << MAX << "개 소요시간 : " <<finish-now <<"ms"<< endl;

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