#include<cstdio>
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
	while (now == ' ' || now == '\n')
		now = read();

	while (now != ' '&&now != '\n')
	{
		sum *= 10;
		sum += now-'0';
		now = read();
	}
	return sum;
}
int main()
{
	long long a, tmp, sum = 0;
	a = readInt();
	int M = a;
	while (M--)
		sum += readInt();

	printf("%lld\n", a);
	printf("%lld\n", sum);

	return 0;
}
