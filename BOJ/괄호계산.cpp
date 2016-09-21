//#include <iostream>
//using namespace std;
//typedef struct _node
//{
//	char value;
//	struct _node* before;
//}node;
//
//typedef node* nptr;
//
//typedef struct _stack
//{
//	int size;
//	nptr top;
//}stack;
//
//stack* createStack()
//{
//	stack* S = new stack;
//	S->size = 0;
//	S->top = NULL;
//	return S;
//}
//
//int push(stack* sptr, char value)
//{
//	nptr N = new node;
//	N->value = value;
//	N->before = NULL;
//
//	if (sptr->size == 0)
//	{
//		sptr->top = N;
//	}
//	else
//	{
//		N->before = sptr->top;
//		sptr->top = N;
//	}
//
//	sptr->size++;
//
//	return 0;
//}
//
//char pop(stack* sptr)
//{
//	if (sptr->size == 0)
//	{
//		return ' ';
//	}
//
//	char tmp = sptr->top->value;
//	nptr ntmp = sptr->top;
//	sptr->top = ntmp->before;
//
//	free(ntmp);
//	sptr->size--;
//	return tmp;
//}
//
//void deleteStack(stack* sptr)
//{
//	while (sptr->size != 0)
//	{
//		pop(sptr);
//	}
//
//	free(sptr);
//}
//
//
//int _strlen(char* str)
//{
//	int i = 0;
//	for (; str[i] != NULL; i++);
//	return i;
//}
//
//int main()
//{
//
//	int nCount;      /* 문제의 테스트 케이스 */
//
//	cin >> nCount;   /* 테스트 케이스 입력 */
//
//	for (int itr = 0; itr<nCount; itr++)
//	{
//
//		cout << "#testcase" << (itr + 1) << endl;
//
//		/*
//
//		알고리즘이 들어가는 부분
//
//		*/
//
//		char c;
//		stack* mys = createStack();
//
//		int flag = 0;
//		int result = 0;
//		int arr[100] = { 0, };
//		bool bflag[100] = { 0, };
//		int tmp = 0;
//
//		char str[100] = { 0, };
//
//		cin >> str;
//
//		for (int j = 0; j < _strlen(str); j++)
//		{
//			if (str[j] == '[' || str[j] == '(')
//			{
//				push(mys, str[j]);
//				flag++;
//			}
//			else
//			{
//				char ctmp = pop(mys);
//
//				if (str[j] == ']' && ctmp == '[')
//				{
//					tmp = 1;
//					for (int i = flag + 1; arr[i] != 0; i++)
//					{
//						tmp *= arr[i];
//						arr[i] = 0;
//					}
//					tmp *= 3;
//
//					arr[flag] += tmp;
//
//					flag--;
//				}
//				else if (str[j] == ')' && ctmp == '(')
//				{
//					tmp = 1;
//					for (int i = flag + 1; arr[i] != 0; i++)
//					{
//						tmp *= arr[i];
//						arr[i] = 0;
//					}
//					tmp *= 2;
//
//					arr[flag] += tmp;
//
//					flag--;
//				}
//			}
//		}
//
//		cout << arr[1] << endl;
//	}
//
//	return 0;   /* 반드시 return 0으로 해주셔야합니다. */
//
//}


 

#include <iostream>
using namespace std;

int _strlen(char *arr)
{
	int i = 0;
	for (; i < arr[i] != 0; i++);
	return i;
}


typedef struct node
{
	char cha;
	struct node *next;

}Node;

typedef struct stack
{
	int size;
	Node *top;

}Stack;

void push(Stack *S, char a)
{
	Node *New = new Node;
	New->cha = a;
	New->next = NULL;

	if (S->size == 0)
	{
		S->size++;
		S->top = New;
	}
	else
	{
		S->size++;
		New->next = S->top;
		S->top = New;
	}
}
char pop(Stack *S)
{
	if (S->size == 0)
		return 0;
	else
	{
		Node *tmp = S->top;
		S->size--;
		S->top = S->top->next;
		char a = tmp->cha;
		delete(tmp);

		return a;
	}
}

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int err_chk = 0;
		cout << "#testcase" << (itr + 1) << endl;
		char arr[100];
		cin >> arr;
		Stack *S = new Stack;
		S->size = 0;
		S->top = NULL;
		int flag = 0;
		int tmp[100] = { 0, };

		for (int i = 0; i < _strlen(arr); i++)
		{
			if (arr[i] == '(' || arr[i] == '[')
			{
				push(S, arr[i]);
				flag++;
			}
			else
			{
				char pa = pop(S);
				if (arr[i] == ']'&&pa == '[')
				{
					int res = 1;
					for (int k = flag; tmp[k] != 0; k++)
					{
						res *= tmp[k];
						tmp[k] = 0;
					}
					res *= 3;
					flag--;
					tmp[flag] += res;
					
				}
				else if (arr[i] == ')'&&pa == '(')
				{
					int res = 1;
					for (int k = flag; tmp[k] != 0; k++)
					{
						res *= tmp[k];

						tmp[k] = 0;
					}
					res *= 2;
					flag--;
					tmp[flag] += res;
					
				}
				else
				{
					err_chk++;
				}
			}
		}
		if (err_chk == 0&&S->size==0)
			cout << tmp[flag] << endl;
		else
			cout << 0 << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}