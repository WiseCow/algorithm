#include<iostream>
using namespace std;
int arr[100001];
int itr;
int cost[100001][5][5];
int solve(int a, int b)
{
	if (a == 0)
	{
		return 2;
	}
	else if (a == 1)
	{
		switch (b)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 4;
			break;
		case 4:
			return 3;
			break;
		}
	}
	else if (a == 2)
	{
		switch (b)
		{
		case 1:
			return 3;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;
		
		}
	}
	else if (a == 3)
	{
		switch (b)
		{
		case 1:
			return 4;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 1;
			break;
		case 4:
			return 3;
			break;
		}
	}
	else
	{
		switch (b)
		{
		case 1:
			return 3;
			break;
		case 2:
			return 4;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 1;
			break;
		}
	}
}

void dbg(int i)
{
	cout << "i " << i << " " << arr[i] << ' ';
	for (int l = 0; l < 5; l++)
	{

		for (int r = 0; r < 5; r++)
		{
			if (cost[i][l][r] != 0)
				cout << "( " << l << " " << r << " )=" << cost[i][l][r] << ' ';
		}

	}
	cout << endl;
}
int main()
{
	while (1)
	{
		scanf("%d", &arr[itr]);
		if (arr[++itr] == 0)
			break;
	}

	//dbg(0);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cost[0][i][j] = 4;
	for (int i = 0; i < 5; i++)
	{
		cost[0][0][i] = 2;
		cost[0][i][0] = 2;
	}
	cost[0][0][0] = 0;
	for (int i = 1; i < itr; i++)
	{
		int k = arr[i];
		for (int ll = 0; ll < 5; ll++)
		{
			for (int rr = 0; rr < 5; rr++)
			{
				int lcost = solve(ll, k);
				int rcost = solve(rr, k);
				if (lcost < rcost)
				{
					cost[i][]
				}

			}
		}


	}














	for (int i = 1; i < itr-1; i++)
	{
		if (arr[i - 1] == arr[i])
		{
			int r;
			for (int k = 0; k < 5; k++)
			{
				if (cost[i - 1][arr[i - 1]][k]!= 0)
					r = k;
			}
			cost[i][arr[i]][r] = cost[i - 1][arr[i - 1]][r] + 1;
		}
		else
		{
			int ll=0, rr=0;
			for (int l = 0; l < 5; l++)
			{
				for (int r = 0; r < 5; r++)
				{
					if (cost[i - 1][l][r] != 0)
					{
						ll = l;
						rr = r;
						break;
					}
				}
				if (ll != 0 && rr != 0)
					break;
			}








		}

		//dbg(i);
	}

	int min=99999999;
	for (int l = 0; l < 5; l++)
		for (int r = 0; r < 5;r++)
			if (cost[itr - 2][l][r]!=0&&cost[itr - 2][l][r] < min)
			{
				min = cost[itr - 2][l][r];
			}

	cout << min << endl;
}