//#include<iostream>
//using namespace std;
//int main()
//{
//	int tc;
//	scanf("%d", &tc);
//	for (int itr = 0; itr < tc; itr++)
//	{
//		int a, b, c, d,e,f,g,h;
//		scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f,&g,&h);
//
//		a += e;
//		b += f;
//		c += g;
//		d += h;
//
//
//		if (a < 1)
//			a = 1;
//		if (b < 1)
//			b = 1;
//		if (c < 0)
//			c = 0;/*
//		if (e < 1)
//			e = 1;
//		if (f < 1)
//			f = 1;
//		if (g < 0)
//			g = 0;*/
//		printf("%d\n", 1*a + 5 * b + 2 * c + 2 * d/*+1* e + 5 * f + 2 * g + 2 * h*/);
//	}
//
//}

//
//#include<stdio.h>
//int main()
//{
//	int tc;
//	scanf("%d", &tc);
//
//	for (int itr = 0; itr < tc; itr++)
//	{
//		int st, en, num=0;
//		scanf("%d %d", &st, &en);
//		if (st <= 1967 && en >= 1967)
//			num += 1;
//		if (st <= 1969 && en >= 1969)
//			num += 1;
//		if (st <= 1970 && en >= 1970)
//			num += 1;
//		if (st <= 1971 && en >= 1971)
//			num += 1;
//		if (st <= 1972 && en >= 1972)
//			num += 1;
//		if (st <= 1973 && en >= 1973)
//			num += 2;
//		if (st <= 1974 && en >= 1974)
//			num += 1;
//		if (st <= 1975 && en >= 1975)
//			num += 1;
//		if (st <= 1976 && en >= 1976)
//			num += 1;
//		if (st <= 1977 && en >= 1977)
//			num += 2;
//		if (st <= 1979 && en >= 1979)
//			num += 1;
//		if (st <= 1980 && en >= 1980)
//			num += 1;
//		if (st <= 1983 && en >= 1983)
//			num += 1;
//		if (st <= 1984 && en >= 1984)
//			num += 1;
//		if (st <= 1987 && en >= 1987)
//			num += 1;
//		if (st <= 1993 && en >= 1993)
//			num += 1;
//		if (st <= 1995 && en >= 1995)
//			num += 1;
//		if (st <= 1997 && en >= 1997)
//			num += 1;
//		if (st <= 1999 && en >= 1999)
//			num += 1;
//		if (st <= 2002 && en >= 2002)
//			num += 1;
//		if (st <= 2003 && en >= 2003)
//			num += 1;
//		if (st <= 2013 && en >= 2013)
//			num += 1;
//		if (st <= 2016 && en >= 2016)
//			num += 1;
//		printf("%d\n", num);
//		if (st <= 1967 && en >= 1967){
//			printf("1967 DavidBowie\n");
//		}
//		if (st <= 1969 && en >= 1969){
//			printf("1969 SpaceOddity\n");
//		}
//		if (st <= 1970 && en >= 1970) {
//			printf("1970 TheManWhoSoldTheWorld\n");
//		}
//		if (st <= 1971 && en >= 1971) {
//			printf("1971 HunkyDory\n");
//		}
//		if (st <= 1972 && en >= 1972) {
//			printf("1972 TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars\n");
//		}
//		if (st <= 1973 && en >= 1973) {
//			printf("1973 AladdinSane\n");
//			printf("1973 PinUps\n");
//		}
//		if (st <= 1974 && en >= 1974) {
//			printf("1974 DiamondDogs\n");
//		}
//		if (st <= 1975 && en >= 1975) {
//
//			printf("1975 YoungAmericans\n");
//		}
//		if (st <= 1976 && en >= 1976) {
//			printf("1976 StationToStation\n");
//		}
//		if (st <= 1977 && en >= 1977) {
//			printf("1977 Low\n1977 Heroes\n");
//		}
//		if (st <= 1979 && en >= 1979) {
//			printf("1979 Lodger\n");
//		}
//		if (st <= 1980 && en >= 1980) {
//			printf("1980 ScaryMonstersAndSuperCreeps\n");
//		}
//		if (st <= 1983 && en >= 1983) {
//			printf("1983 LetsDance\n");
//		}
//		if (st <= 1984 && en >= 1984) {
//			printf("1984 Tonight\n");
//		}
//		if (st <= 1987 && en >= 1987) {
//			printf("1987 NeverLetMeDown\n");
//		}
//		if (st <= 1993 && en >= 1993) {
//			printf("1993 BlackTieWhiteNoise\n");
//		}
//		if (st <= 1995 && en >= 1995) {
//			printf("1995 1.Outside\n");
//		}
//		if (st <= 1997 && en >= 1997) {
//			printf("1997 Earthling\n");
//		}
//		if (st <= 1999 && en >= 1999) {
//			printf("1999 Hours\n");
//		}
//		if (st <= 2002 && en >= 2002) {
//			printf("2002 Heathen\n");
//		}
//		if (st <= 2003 && en >= 2003) {
//			printf("2003 Reality\n");
//		}
//		if (st <= 2013 && en >= 2013) {
//			printf("2013 TheNextDay\n");
//		}
//		if (st <= 2016 && en >= 2016) {
//			printf("2016 BlackStar\n");
//		}
//	}
//	return 0;
//}





#include<iostream>
using namespace std;
int arr[1000001];
int main()
{
	int man;
	scanf("%d", &man);
	for (int i = 1; i <= man; i++)
		scanf("%d", &arr[i]);
	int i = 2;
	while (i <= 2 * 1000000000)
	{
		int k = 0;
	}




}