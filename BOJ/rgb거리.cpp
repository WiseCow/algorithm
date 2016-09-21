//https://www.acmicpc.net/problem/1149

#include<iostream>
using namespace std;

int result[1001][3];
int input[3];

int main()
{
	int itr;
	cin >> itr;
	for (int tc = 0; tc < itr; tc++)
	{
		cin >> input[0] >> input[1] >> input[2];
		if (tc == 0)
		{
			for (int i = 0; i < 3;i++)
			result[tc][i] = input[i];
		}
		else
		{
			result[tc][0] = result[tc - 1][1]>result[tc - 1][2] ? (result[tc - 1][2] + input[0]):(result[tc-1][1]+input[0]);
			result[tc][1] = result[tc - 1][0]>result[tc - 1][2] ? (result[tc - 1][2] + input[1]) : (result[tc - 1][0] + input[1]);
			result[tc][2] = result[tc - 1][0]>result[tc - 1][1] ? (result[tc - 1][1] + input[2]) : (result[tc - 1][0] + input[2]);
		}
	}
	int max = result[itr - 1][0];
	if (max > result[itr - 1][1])
		max = result[itr - 1][1];
	if (max > result[itr - 1][2])
		max = result[itr - 1][2];
	cout << max << endl;
}