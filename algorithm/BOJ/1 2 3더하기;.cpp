#include<iostream>
using namespace std;
int main()
{
	int D[20];
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	int tc;
	scanf("%d", &tc);
	for (int i = 4; i < 12; i++)
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];



	for (int itr = 0; itr < tc; itr++)
	{
		int a;
		scanf("%d", &a);
		printf("%d\n", D[a]);
	}

}/*


#include<iostream>
using namespace std;
int in[100];
int D[20];
int main()
{
	int tc;
	scanf("%d", &tc);
	int max = 0;
	for (int i = 0; i < tc; i++)
	{
		scanf("%d", &in[i]);
	}

	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	for (int i = 4; i < 12; i++)
	{

		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}
	for (int i = 0; i < tc; i++)
	{
		cout << D[in[i]] << '\n';
	}
}*/