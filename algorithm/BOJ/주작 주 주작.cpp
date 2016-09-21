#include<cstdio>
char buf[1 << 19];
int idx, nidx;
static inline char read()
{
	if (idx == nidx)
	{
		nidx = fread(buf, 1, 1 << 19, stdin);
		idx = 0;
	}
	return buf[idx++];
}
static inline int readInt()
{
	int sum = 0;
	char now = read();
	while (now == ' ' || now == '\n')
		now = read();
	while (now != ' '&&now != '\n')
	{
		sum = sum * 10 + now - '0';
		now = read();
	}
	return sum;
}
int main()
{
	int N, t;
	N = readInt();
	for (int i = 1; i <= N; i++)
	{
		t = readInt();
		if (i == t)
		{
			printf("-1");
			return 0;
		}
	}
	printf("1000003");
}