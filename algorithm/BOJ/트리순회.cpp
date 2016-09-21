#include<cstdio>
char arr[27][3];
void pre(int now)
{
	printf("%c", arr[now][0] + 'A');
	if (arr[now][1] + 'A' != '.')
		pre(arr[now][1]);
	if (arr[now][2] + 'A' != '.')
		pre(arr[now][2]);

}
void in(int now)
{
	if (arr[now][1] + 'A' != '.')
		in(arr[now][1]);
	printf("%c", arr[now][0] + 'A');
	if (arr[now][2] + 'A' != '.')
		in(arr[now][2]);

}
void post(int now)
{
	if (arr[now][1] + 'A' != '.')
		post(arr[now][1]);
	if (arr[now][2] + 'A' != '.')
		post(arr[now][2]);
	printf("%c", arr[now][0] + 'A');
}
int main()
{
	int N;
	scanf("%d", &N);
	char a[2], b[2], c[2];

	int head;
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s %s", &a, &b, &c);
		arr[a[0] - 'A'][0] = a[0] - 'A';
		arr[a[0] - 'A'][1] = b[0] - 'A';
		arr[a[0] - 'A'][2] = c[0] - 'A';
		if (i == 0)
			head = a[0] - 'A';
	}
	pre(head); printf("\n");
	in(head); printf("\n");
	post(head); printf("\n");
	return 0;
}