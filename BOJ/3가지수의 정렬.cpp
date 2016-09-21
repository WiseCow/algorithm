
#include <iostream>
using namespace std;
void _swap(int *I, int *j)
{
	int tmp = *I;
	*I = *j;
	*j = tmp;
}
int main()
{

	int nCount;		 

	cin >> nCount;	 

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int cnt;
		cin >> cnt;
		int arr[2000];
		int chk[2000];
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
			chk[i] = arr[i];
		}
		for (int i = 0; i < cnt; i++)
		{
			int min = i;
			for (int j = i + 1; j < cnt; j++)
			{
				if (arr[j] < arr[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				_swap(&arr[i], &arr[min]);
			}
		}



		int count = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (chk[i] == arr[i])
				continue;
			else
			{
				int k;
				for ( k= i + 1; k < cnt; k++)
				{
					if (arr[i] == chk[k]&&chk[i]==arr[k])
						break;
				}
				if (arr[i] == chk[k]&&k!=cnt)
				{
					count++;
					_swap(&chk[i], &chk[k]);
				}
				else if(k == cnt)
				{

					for (k = i + 1; k < cnt; k++)
						if (arr[i]==chk[k]&&arr[k]!=chk[k])
							break;
					_swap(&chk[i], &chk[k]);
					count++;
					/*for (k = i + 1; k < cnt; k++)
						if (chk[i] == arr[k] && arr[k] != chk[k])
							break;
					_swap(&chk[i], &chk[k]);
					count++;*/
				}
			}
		}
		cout << count << endl;
	}

	return 0;	 

}