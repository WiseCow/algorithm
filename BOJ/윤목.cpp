#include <cstdio>
#include <iostream>
#include<cstring>
using namespace std;
int arr[6] = { 0 };
bool pr;
void find(int ans, int use, int now, int used)
{

	for (int i = 0; i <= use-used; i++)
	{
		
			arr[now] = i;
			if (now != 5)
			find(ans, use, now + 1, used + i);
			else
			{
				if (arr[1] + arr[2] * 2 + arr[3] * 3 + arr[4] * 4 + arr[5] * 5 == ans&&used+i==use&&pr == 0)
				{
					printf("%d %d %d %d %d\n", arr[1], arr[2], arr[3], arr[4], arr[5]);
					pr = 1;
				}
			}
	}

	arr[now] = 0;
}
int main(int argc, char** argv) {
	
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	
	for (test_case = 1; test_case <= T; test_case++) {
		double in;
		scanf("%lf", &in);
		int i = 1;
		while (1)
		{
			int k = (in*i)/1;
			if (k- (in*i) == 0)
				break;
			i++;
		}
		int findn = in*i;
		printf("Case #%d\n", test_case);
		pr = 0;
		find(findn, i,1,0);
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}