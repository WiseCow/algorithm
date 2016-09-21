#include<iostream>
#include<algorithm>
using namespace std;

int L, C;

char input[20];
void dfs(int now,int jari,int map[20])
{
	if (jari == L)
	{
		int jcnt = 0,mcnt=0;
		for (int i = 0; i < L; i++)
		{
			char a = input[map[i]];
			if (a == 'a' || a == 'e' || a == 'i'|| a == 'o'  || a == 'u')
				mcnt++;
			else
				jcnt++;
		}

		if (jcnt >= 2 && mcnt >= 1)
		{
			for (int i = 0; i < L; i++)
			{
				printf("%c", input[map[i]]);
			}
			printf("\n");
		}
	}
	else
	{
		for (int i = now + 1; i < C; i++)
		{
			map[jari] = i;
			dfs(i, jari + 1, map);
			map[jari] = 0;
		}
	}
}

int main()
{
	scanf("%d %d ", &L, &C);

	for (int i = 0; i < C; i++)
	{
		char a[2];
		scanf("%s", &a);
		input[i] = a[0];
	}
	sort(input, input + C);


	for (int i = 0; i < C; i++)
	{
		int map[20]={ 0 };
		map[0] = i;
		dfs(i, 1, map);
		map[0] = 0;
	}
	return 0;
}