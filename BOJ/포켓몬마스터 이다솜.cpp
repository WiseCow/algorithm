#include<string>
#include<cstdio>
#include<map>
using namespace std;
int N, M;
char input[21];
string str;
map<string, string> arr1, arr2;



int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", &input);
		str = input;
		arr1[str] = to_string(str);
		arr2[to_string(str)] = str;

	}
	for (int i = 0; i < M; i++)
	{
		scanf("%s", input);
		str = input;
		if(input[0])
	}
}