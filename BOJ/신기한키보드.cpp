//https://www.acmicpc.net/problem/1796
#include <iostream>	
using namespace std;

char arr[1001];
int alphabet[26];
int alphaposition[26][1001];
int dist[26][1001];

int _abs(int a)
{
	return a >= 0 ? a : -a;
}

int chk(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return -1;
	}
}


int main() 
{
	scanf("%s", &arr[1]);
	int i;
	for (i = 1; arr[i] != 0; i++)
	{
		alphaposition[arr[i] - 'a'][alphabet[arr[i] - 'a']] = i;
		alphabet[arr[i] - 'a']++;
	}
	bool first = 0;
	int last;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] > 0)
		{
			if (first == 0)
			{
				first = 1;
				for (int l = 0; l < alphabet[i]; l++)
				{
					int a, b;
					int flag = chk(1, alphaposition[i][0], alphaposition[i][alphabet[i] - 1]);

					if (flag == -1)
					{
						a = _abs(1 - alphaposition[i][alphabet[i] - 1]) + _abs(alphaposition[i][alphabet[i] - 1] - alphaposition[i][l]);
					}
					else if (flag == 0)
					{
						a = _abs(1 - alphaposition[i][0]) + _abs(alphaposition[i][0] - alphaposition[i][alphabet[i] - 1]) + _abs(alphaposition[i][alphabet[i] - 1] - alphaposition[i][l]);
						int b =_abs(1 - alphaposition[i][alphabet[i] - 1]) + _abs(alphaposition[i][0] - alphaposition[i][alphabet[i] - 1]) + _abs(alphaposition[i][0] - alphaposition[i][l]);
						if (a > b)
							a = b;
					}
					else
					{
						a =  _abs(1 - alphaposition[i][0]) + _abs(alphaposition[i][0] - alphaposition[i][l]);
					}

						dist[i][l] = a;
				}
				last = i;
			}
			else
			{


				for (int itr = 0; itr < alphabet[last]; itr++)
				{
					for (int l = 0; l < alphabet[i]; l++)
					{
						int flag = chk(alphaposition[last][itr], alphaposition[i][0], alphaposition[i][alphabet[i] - 1]);
						int a;

						if (flag == -1)
						{
							a = dist[last][itr]+ _abs(alphaposition[last][itr] - alphaposition[i][alphabet[i] - 1])+ _abs(alphaposition[i][alphabet[i] - 1] - alphaposition[i][l]);
						}
						else if(flag==0)
						{
							a = dist[last][itr] + _abs(alphaposition[last][itr] - alphaposition[i][0]) + _abs(alphaposition[i][0] - alphaposition[i][alphabet[i] - 1]) + _abs(alphaposition[i][alphabet[i] - 1] - alphaposition[i][l]);
							int b = dist[last][itr] + _abs(alphaposition[last][itr] - alphaposition[i][alphabet[i] - 1]) + _abs(alphaposition[i][alphabet[i] - 1]- alphaposition[i][0]) + _abs(alphaposition[i][0] - alphaposition[i][l]);
							if (a > b)
								a = b;
						}
						else
						{
							a = dist[last][itr] + _abs(alphaposition[last][itr] - alphaposition[i][0]) + _abs(alphaposition[i][0] - alphaposition[i][l]);
						}

							if (dist[i][l] == 0)
								dist[i][l] = a;
							else if(dist[i][l]>a)
								dist[i][l] = a;
					}
				}
				last = i;
			}
		}
	}

	int mini = 99999999999;
	for (int i = 0; i < alphabet[last]; i++)
	{
		if (dist[last][i] < mini)
		{
			mini = dist[last][i];
		}
	}
	cout << mini + i-1 << endl;

}