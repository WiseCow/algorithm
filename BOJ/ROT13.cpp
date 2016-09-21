#include<stdio.h>
int main()
{
	char arr[101] = { 0 };
	gets(arr);
	for (int i = 0; arr[i]; i++)
	{
		if ((arr[i] >= 'A'&&arr[i] <= 'M') || (arr[i] >= 'a'&&arr[i] <= 'm'))
			arr[i] += 13;
		else if ((arr[i] >= 'N'&&arr[i] <= 'Z') || (arr[i] >= 'n'&&arr[i] <= 'z'))
			arr[i] -= 13;
	}
	printf("%s\n", arr);
}