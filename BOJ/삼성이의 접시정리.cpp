#include <iostream>
#include<string.h>
using namespace std;

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

void push(Stack *S, char cha)
{
	Node *New = new Node;
	New->cha = cha;
	New->next = NULL;
	if (S->size == 0)
	{
		S->top = New;
		S->size++;
	}
	else
	{
		New->next = S->top;
		S->top = New;
		S->size++;
	}
}
void pop(Stack *S)
{
	char a;
	if (S->size == 0)
	{
		return;
	}
	else
	{
		a = S->top->cha;
		Node *tmp = S->top;
		S->top = S->top->next;
		S->size--;
		delete(tmp);
	}

}
char lookstack(Stack *S)
{
	if (S->size == 0)
		return 0;
	else
		return S->top->cha;

}


int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;


		Stack *S = new Stack;
		S->size = 0;
		S->top = NULL;

		char arr[40] = { 0, };
		char first[40] = { "abcdefghijklmnopqrstuvwxyz" };

		cin >> arr;
		int cnt;		
		for (cnt = 0; arr[cnt] != 0; cnt++);

		char msg[100][5];
		int msg_po = 0;

		int flag = 0;

		int i = 0, j = 0;
		push(S, first[i++]);
		strcpy_s(msg[msg_po++], "push");
		while (1)
		{
			if (arr[j] < lookstack(S))
			{
				flag++;
				break;
			}
			if (j>=cnt)
				break;
			if (arr[j] == lookstack(S))
			{
				pop(S);
				strcpy_s(msg[msg_po++], "pop");
				j++;
				continue;
			}
			else
			{
				push(S, first[i++]);
				strcpy_s(msg[msg_po++], "push");
			}
		}



		if (flag == 1)
		{
			cout << "impossible" << endl;
		}
		else
		{
			for (int x = 0; x < msg_po; x++)
			{
				cout << msg[x] << endl;
			}
		}



	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}