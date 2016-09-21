#include<cstdio>
#include<algorithm>
using namespace std;

int map[5000000];
char buf[1 << 18];//여기에 저장함

int idx, nidx;//현재 인덱스 nidx 총몇개 입력받았는지

			  //stdin 구간만큼 입력받고 버퍼 배열에 저장 리턴은 한글자만 리턴
static inline char read()
{
	if (idx == nidx)
	{
		nidx = fread(buf, 1, 1 << 18, stdin);
		idx = 0;
	}
	return buf[idx++];
}
//한정수 리턴
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
