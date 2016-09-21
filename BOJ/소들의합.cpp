#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;

}Node;
typedef struct stack
{
	int size;
	Node *top;

}Stack;
void push(Stack *S, int data)
{
	Node *New = new Node;
	New->data = data;
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
int pop(Stack *S)
{
	if (S->size == 0)
	{
		return 0;
	}
	else
	{
		S->size--;
		int data = S->top->data;
		Node *tmp = S->top->next;
		int cnt=0;
		while (1)
		{
			if (tmp==NULL||data < tmp->data)
				break;
			else
				cnt++;
			tmp = tmp->next;
		}
		Node *fre = S->top;
		S->top = S->top->next;
		delete(fre);
		return cnt;
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
		int cnt;

		cin >> cnt;

		for (int i = 0; i < cnt; i++)
		{
			int num;
			cin >> num;
			push(S, num);
		}
		int count = 0;
		while (S->size != 0)
		{
			count += pop(S);
		}

		cout << count << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}