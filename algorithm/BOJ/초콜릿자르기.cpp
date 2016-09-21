#include<time.h>
#include<cstdio>
int main()
{
	char buf[100];
	time_t t = time(NULL);
	tm *now = localtime(&t);
	strftime(buf, 100, "%Y-%m-%d", now);
	printf("%s", buf);
}