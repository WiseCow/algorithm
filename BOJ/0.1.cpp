#include<cstdio>
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
