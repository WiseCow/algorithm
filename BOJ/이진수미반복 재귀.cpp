#include<iostream>


using namespace std;
int flag = 0;
void FF(int *arr, int num, int cnt)
{
	if (cnt < 1){
		for (int i = 0; i < 2; i++)
		{
			arr[cnt] = i;
			FF(arr, num, cnt + 1);
		}
	}
	else
	{
		if (cnt < num){
			if (arr[cnt-1] == 0)
			{
				for (int i = 0; i < 2; i++)
				{
					arr[cnt] = i;
					FF(arr, num, cnt + 1);
				}
			}
			else
			{
				arr[cnt] = 0;
				FF(arr, num, cnt + 1);
			}
		}
		else{
			flag++;
			return;
		}
	}
}
int main()
{
	int nCount;
	cin >> nCount;
	for (int itr = 0; itr < nCount; itr++)
	{
		int num;
		cin >> num;
		int arr[100] = { 0, };

		//FF(arr, num, 0);

		if (num < 3)
		{
			if (num == 1)
				cout << "2"<<endl;
			else
				cout << "3"<<endl;

		}
		else
		{
			arr[0] = 2;
			arr[1] = 3;
			int i;
			for (  i = 2; i < num; i++)
			{
				arr[i] = arr[i - 1] + arr[i - 2];

			}
			cout << "retult : " << arr[i-1] << endl;

		}

		//cout <<"retult : "<< flag << endl;
		flag = 0;

	}


}