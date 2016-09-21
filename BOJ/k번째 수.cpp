#include<cstdio>
#include<algorithm>
using namespace std;

int map[5000000];
char buf[1 << 18];//���⿡ ������

int idx, nidx;//���� �ε��� nidx �Ѹ �Է¹޾Ҵ���

			  //stdin ������ŭ �Է¹ް� ���� �迭�� ���� ������ �ѱ��ڸ� ����
static inline char read()
{
	if (idx == nidx)
	{
		nidx = fread(buf, 1, 1 << 18, stdin);
		idx = 0;
	}
	return buf[idx++];
}
//������ ����
static inline int readInt()
{
	int sum = 0;
	char now = read();
	bool flag = 0;

	while (now == ' ' || now == '\n')
		now = read();
	if (now == '-')
	{
		flag = true;
		now = read();
	}
	while (now != ' '&&now != '\n'&&now!=EOF)
	{
		sum *= 10;
		sum += now - '0';
		now = read();
	}
	if (flag)
		sum *= -1;
	return sum;
}
int main()
{
	int N, K;
	N = readInt();
	K = readInt();

	int M = N;
	while (M--)
		map[M] = readInt();
	nth_element(map, map + K - 1, map + N);
	printf("%d", map[K-1]);
	return 0;
}
