#include<cstdio>
char in[3], in1[3];
int tc, kingx, kingy, stonx, stony;
int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,-1,1,1,1,-1,-1};
int chk()
{
	int d;
	switch (in[0])
	{
		case 'R':
			if (in[1] == 0)
				d = 0;
			else
			{
				if (in[1] == 'T')
					d = 4;
				else
					d = 6;
			}
			break;
		case'L':
			if (in[1] == 0)
				d = 1;
			else
			{
				if (in[1] == 'T')
					d = 5;
				else
					d = 7;
			}
			break;
		case 'B':
			d = 2;
			break;
		case'T':
			d = 3;
			break;
	}
	return d;
}
int main()
{
	scanf("%s %s %d", &in, &in1, &tc);
	kingx = in[0]-'A';
	kingy = in[1]-'1';
	stonx = in1[0] - 'A';
	stony = in1[1]-'1';

	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%s", &in);
		int d = chk();
		int knx=kingx+dx[d], kny=kingy+dy[d], snx=stonx+dx[d] ,sny=stony+dy[d];
		if (knx == stonx&&kny == stony)
		{
			if (snx >= 0 && snx < 8 && sny >= 0 && sny < 8)
			{
				kingx = knx;
				kingy = kny;
				stonx = snx;
				stony = sny;
			}
		}
		else
		{
			if (knx >= 0 && knx < 8 && kny >= 0 && kny < 8)
			{
				kingx = knx;
				kingy = kny;
			}
		}
	}
	in[0] = 'A' + kingx;
	in[1] = '1' + kingy;
	in[2] = 0;
	in1[0] = 'A' + stonx;
	in1[1] = '1' + stony;
	in1[2] = 0;
	printf("%s\n%s\n", in, in1);


}