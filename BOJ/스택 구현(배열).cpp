//#include<iostream>
//using namespace std;
//
//typedef struct node{
//	int x;
//	struct node *next;
//}Node;
//
//
//
//typedef struct stack
//{
//	Node *next;
//}Stack;
//
//
//void push(Stack *Q, int data)
//{
//	Stack *S = Q;
//	Node *New = new Node;
//	New->x = data;
//	New->next = NULL;
//	if (S->next == NULL)
//	{
//		S->next = New;
//	}
//	else
//	{
//		New->next = S->next;
//		S->next = New;
//
//	}
//}
//
//void pop(Stack *S)
//{
//	if (S->next == NULL)
//		cout << "Stack Empty" << endl;
//	else
//	{
//		int a = S->next->x;
//		S->next = S->next->next;
//		cout << "Pop : " << a << endl;
//	}
//}
//int main()
//{
//
//	Stack *S = new Stack;
//
//	S->next = NULL;
//
//	for (int i = -0; i < 30; i++)
//	{
//		push(S, i);
//
//	}
//	for (int i = -0; i < 20; i++)
//	{
//		pop(S);
//
//	}
//}



//#include<iostream>
//using namespace std;
//
//typedef struct node{
//	int x;
//	struct node *next;
//}Node;
//
//typedef struct stack
//{
//	Node *next;
//}Stack;
//
//
//int main()
//{
//	char arr[100] = { 0, };
//	cin >> arr;
//
//	for (int i = 0; arr[i] != 0; i++)
//	{
//		if (arr[i]>48 && arr[i]<59)
//
//	}
//}


#include<iostream>
using namespace std;

typedef struct node{
	char x;
	struct node *next;
}Node;

typedef struct stack
{
	Node *next;
}Stack;

void push(Stack *Q, char data)
{
	Stack *S = Q;
	Node *New = new Node;
	New->x = data;
	New->next = NULL;
	if (S->next == NULL)
	{
		S->next = New;
	}
	else
	{
		New->next = S->next;
		S->next = New;

	}
}
char pop(Stack *S)
{
	if (S->next == NULL)
		cout << "Stack Empty" << endl;
	else
	{
		char a = S->next->x;
		S->next = S->next->next;
		return a;
	}
}

int main()
{
	bool flag=0;
	char arr[100] = { 0, };
		Stack *S = new Stack;
		S->next = NULL;


	gets_s(arr);
	bool same = 0;
	for (int i = 0; arr[i] != 0; i++)
	{
		if (arr[i] == 'X'&&flag == 0)
		{
			i++;
			flag = 1;
		}
		if (flag == 0)
		{
			push(S, arr[i]);
		}
		else
		{
			if (arr[i] != pop(S))
			{
				same = 1;
				break;
			}
			else
				continue;
		}
	}
	if (same == 0&&flag==1)
	{
		cout << "회문" << endl;
	}
	else
		cout << " 회문이아님" << endl;



}