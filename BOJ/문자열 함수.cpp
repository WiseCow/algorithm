
#include<iostream>
#include<string>



using namespace std;
int  sttrlen(char str1[])
{
	int j = 0;
	for (j = 0; str1[j] != 0; j++);
	return j;

}
void sttrcat(char str1[], char str2[])
{
	int i = 0,j=0;
	for (j = 0; str1[j] != 0; j++);

	for (i = 0; str2[ i] != 0; i++)
	{
		str1[i+j] = str2[i];

	}
	str1[i+j] = NULL;
}

void sttrcpy(char str1[], char str2[])
{
	int i = 0;
	for (i = 0; str2[i] != 0; i++)
	{
		str1[i] = str2[i];

	}
	str1[i] = NULL;
}
int sttrcmp(char str1[], char str2[])
{//ret->0 완전일치 , 1이면 str1>str2 , -1 이면str1<str2
 
	int i = 0;

	for ( i = 0; str1[i] != NULL || str2[i] != NULL; i++)
	{
		if (str1[i] > str2[i])
		{
			return 1;
		}
		if (str1[i] < str2[i])
		{
			return -1;
		}
	}

	if (str1[i] == NULL && str2[i]==NULL)return 0;
	else if (str2[i] == NULL)return 1;
	else if (str1[i] == NULL)return -1;
  }
int main()
{
	char str1[100] = "none";
//	char str2[100] = "gjssm";
//
//
//	cout << "befor ==" << endl << str1 << endl << str2 << endl;
//
//
//	/*if (sttrcmp(str1, str2) == 0)cout << "일치합니다" << endl;
//	else if (sttrcmp(str1, str2) > 0)cout << "str1이 더 큽니다" << endl;
//	else cout << "str2가 더 큽니다" << endl;
//*/
//	cout << strlen(str1) << " ";
//	sttrcat(str1, str2);
//	cout<<strlen(str1)<< " " ;
//	cout << strlen(str2) << endl;;
//	//sttrcat(str1, str2);
//	//cout<<sttrcmp(str1, str2)<<endl;
//	//sttrcpy(str1, str2) ;
//	cout << "after ==" << endl << str1 << endl << str2 << endl;
	cin >> str1;
	cout << str1;

}	

