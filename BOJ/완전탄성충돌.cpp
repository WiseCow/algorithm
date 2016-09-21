#include <iostream>
using namespace std;
#define max 300001
int arr[max],dis[max], tmp[max], dis_t[max];

void marge_sort(int *arr, int *dis, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;

	while (i <= mid&&j <= right)
	{
		if (arr[i] < arr[j]){
			dis_t[k] = dis[i];
			tmp[k++] = arr[i++];
		}
		else{

			dis_t[k] = dis[j];
			tmp[k++] = arr[j++];
		}
	}
	if (i <= mid)
	{
		while (i <= mid){

			dis_t[k] = dis[i];
			tmp[k++] = arr[i++];
		}
	}
	else
	{
		while (j <= right)
		{
			dis_t[k] = dis[j];
			tmp[k++] = arr[j++];
		}
	}
	i = left;
		while (i <= right)
		{
			dis[i] = dis_t[i];
			arr[i] = tmp[i++];
		}
}



void marge(int *arr, int *dis, int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		marge(arr,dis,left, mid);
		marge(arr,dis,mid + 1, right);
		marge_sort(arr,dis,  left, mid, right);
	}
}

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int size, N, K;
		cin >> size >> N >> K;
		for (int i = 0; i < N; i++)
		{
			//fflush(stdin);
			cin >> arr[i]>>dis[i];
		}
		marge(arr, dis,0, N - 1);

		int count = 0;
		int i;
		for ( i = 1;N-i>=0; i++)
		{
			if (dis[N - i] == 1)
				count++;
			if (count == K)
				break;
		}
		


		cout << size-(arr[N-i])<< " " << arr[N - K] << endl;



	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}