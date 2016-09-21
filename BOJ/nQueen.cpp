#include<iostream>

using namespace std;

int arr[13][13];
int N;
int res;
void nQueen(int row, int Q)
{	
	if (row == N)
	{
		if (Q == N)
		{
			res++;

		}
		return ;

	}


	for (int i = 0; i < N; i++)
	{
		int p = 1;
		bool _flag = false;
		for (int j = row - 1; j >= 0; j--, p++)
		{


			if (arr[j][i] == 1)_flag = true;
			if (i - p >= 0 && arr[j][i - p] == 1)_flag = true;
			if (i + p < N && arr[j][i + p] == 1)_flag = true;
			if (_flag == true)break;
		}
		if (_flag == false)
		{
			arr[row][i] = 1;
			nQueen(row + 1, Q + 1);
			arr[row][i] = 0;
		}
	}


}
int main(){


		res = 0;
		cin >> N;
		nQueen(N, N);
		cout << res << endl;

}






//#include<iostream>
//
//
//using namespaces std;
//
//
//
//
//
//find()
//
//
//
//int nQueen(int *arr[100], size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		find(arr,i)
//	}
//}
//
//
//int main()
//
//{
//	int cnt;
//	cin >> cnt;
//	for (int itr = 0; itr < cnt; itr++)
//	{
//		int size;
//		cin >> size;
//
//		int arr[100][100]
//			nQueen(arr, size);
//	}
//
//}