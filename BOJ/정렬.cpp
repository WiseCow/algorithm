//#include <iostream>
//using namespace std;
//typedef struct ArrayListNodeType
//{
//	int data;
//
//}ArrayListNode;
//
//
//
//
//typedef struct ArrayListType
//{
//	int maxElementCount;
//	int currentElementCount;
//	ArrayListNode* pElement;
//
//}ArrayList;
//
//
//ArrayList * createArrayList(int maxElementCount){
//	ArrayList *pReturn = NULL;
//	int i = 0;
//
//	if (maxElementCount > 0){
//		pReturn = (ArrayList *)malloc(sizeof(ArrayList));
//
//		if (pReturn != NULL)
//		{
//			pReturn->maxElementCount = maxElementCount;
//			pReturn->currentElementCount = 0;
//			pReturn->pElement = NULL;
//
//		}
//		else
//		{
//			printf("오류 메모리 할당\n");
//			return NULL;
//		}
//
//	}
//	else
//	{
//		printf("오류 최대 원소개수는 0 이사이여야합니다\n");
//		return NULL;
//	}
//	`
//
//	pReturn->pElement = (ArrayListNode *)malloc(sizeof(ArrayList)*maxElementCount);
//	if (pReturn->pElement == NULL)
//	{
//		free(pReturn); return NULL;
//	}
//	memset(pReturn->pElement, 0, sizeof(ArrayListNode)*maxElementCount);
//
//	return pReturn;
//
//}
//
//
//
//int main()
//{
//	
//
//
//}



#include <iostream>
using namespace std;

void select(int value[], int count);
void shell(int * value, int start, int end, int count);
void shellInsert(int * value, int start, int end, int intervel);
void insert(int value[], int count);
void print(int value[], int count);

int main()
{
	int value[] = { 45, 20, 88, 43, 29, 21, 37, 90 };
	cout << "Before Sort\n";
	print(value, 8);

	select(value, 8);
	//insert(value, 8);
	//shell(value, 0, 7, 8);

	cout << "After Sort\n";
	print(value, 8);

}


void print(int value[], int count)
{
	for (int i = 0; i < count; i++)
		cout << value[i] << " ";
	cout << endl;
}


void shell(int * value, int start, int end, int count)
{
	int i = 0, interval = 0;
	//초기 간격의설정
	interval = count / 2;
	//각격이 1일때 까지 루프문을 수행
	while (interval > i)
	{
		for (int i = 0; i < interval; i++)
		{
			shellInsert(value, 0, count - 1, interval);

		}
		printf("interval -%d, ", interval);
		print(value, count);

		interval /= 2;
	}

}
void shellInsert(int * value, int start, int end, int interval)
{
	int i = 0; int item = 0, index = 0;
	//간격이용 정렬대상선정
	for (i = start + interval; i <= end; i += interval)
	{//삽입정렬의 키값과 위치값을 초기화 시킴
		item = value[i];
		index = i - interval;
		//루프문을 사용하여 삽입정렬을 수행할 위치를 찾음
		while ((index >= start) && item < value[index])
		{
			value[index + interval] = value[index];
			index = index - interval;

		}
		value[index + interval] = item;

	}

}void insert(int value[], int count)
{
	int i = 0, j = 0;
	int temp = 0;
	for (i = 1; i<count; i++) 
	{
		temp = value[i];
		j = i;
		while ((j>0) && value[j - 1]>temp)
		{
			value[j] = value[j - 1];
			j = j - 1;
		}
		value[j] = temp;

		cout << "Step - " << i << ":";
		print (value, count);
	}
}




void select(int value[], int count)
{
	int i = 0,j = 0;
	int min = 0, tmp =0;
 
	for (i = 0; i < count - 1; i++)
	{
		 
		min = i;
		for (j = i + 1; j < count; j++)
		{
			if (value[j] < value[min])min = j;

		}

		 
		tmp = value[i];
		value[i] = value[min];
		value[min] = tmp;

		cout << "step - " << i + 1<<endl;
		print(value, 8);
	}
}