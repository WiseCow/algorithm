#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char input[503];
int idx, D[501][501];
int sol(int le, int ri)
{
	int size = ri - le + 1;
	if (size < 2)return 0;
	int &ret = D[le][ri];
	if (ret != -1)return ret;
	ret = 0;
	if (input[le] == 'a'&&input[ri] == 't')
		ret = max(ret, sol(le + 1, ri - 1) + 2);
	if (input[le] == 'g'&&input[ri] == 'c')
		ret = max(ret, sol(le + 1, ri - 1) + 2);
	for (int i = le; i < ri; i++)
		ret = max(ret, sol(le, i) + sol(i + 1, ri));
	return ret;
}
int main()
{
	memset(D, -1, sizeof(D));
	scanf("%s", &input);
	while (input[idx++] != 0);
	printf("%d", sol(0, idx - 2));
}