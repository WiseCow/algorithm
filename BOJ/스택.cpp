 

#include <iostream>
using namespace std;

typedef struct node
{
	int x;
	struct node *next;

}Node;

typedef struct stack
{
	int size;
	Node *top;
}Stack;
void push(Stack *S, int dat)
{
	Node *New = new Node;
	New->next = NULL;
	New->x = dat;
	
	if (S->size == 0)
	{
		cout << "PUSH SUCCESS(" << dat << ")" << endl;
		S->size++;
		S->top = New;
	}
	else if (S->size > 19)
	{
		cout << "STACK FULL" << endl;
	}
	else
	{
		cout << "PUSH SUCCESS(" << dat << ")" << endl;
		New->next = S->top;
		S->top = New;
		S->size++;
	}
}
void pop(Stack *S)
{
	if (S->size == 0)
	{
		cout << "STACK EMPTY" << endl;
		return;
	}
	else
	{
		Node *tmp = S->top;
		cout << S->top->x << endl;
		S->top = S->top->next;
		S->size--;
		delete(tmp);

	}
}



int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;


		Stack *S = new Stack;
		S->size = 0;
		S->top = NULL;

		char cmd[10];
		while (1)
		{
			cin >> cmd;

			if (cmd[1] == 'U')
			{
				int data;
				cin >> data;
				push(S, data);

			}
			else if (cmd[1] =='O')
			{
				pop(S);
			}
			else
			{
				cout << "BYE" << endl;
				break;
			}

		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}