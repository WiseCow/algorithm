#include<cstdio>
int main()
{
	char a[20], b[20], tmp[20],res[30];
	
	scanf("%s", &a);
	scanf("%s", &tmp);
	int i = 0;
	while (a[i])i++;
	int j = 0;
	while (tmp[j]) {
		a[i++] = tmp[j++];
	}
	a[i] = 0;
	scanf("%s", &b);
	scanf("%s", &tmp);
	int k = 0;
	while (b[k])k++;
	j = 0;
	while (tmp[j]) {
		b[k++] = tmp[j++];
	}
	b[k] = 0;
	i--; k--;
	int p = k > i ? k : i;
	res[p+1] = 0;
	int c = 0;
	for (;  p>= 0; p--)
	{

		int aa=0;
		if(i>=0)
		aa= a[i] - '0';
		int bb=0;
		if(k>=0)
		bb= b[k] - '0';
		int next=c;
		c = 0;
		next += aa + bb;
		if (next>= 10)
		{
			c = 1;
			next -= 10;
		}
		res[p] = next + '0';
		i--;
		k--;
	}
	if (c == 1)
		printf("1");
	printf("%s\n", res);

}