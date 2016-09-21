#include <iostream>
using namespace std;
struct Node{
	int data;
	Node * next;
};
struct Stack
{
	int size;
	Node *head;
};
void push(Stack *S, int data)
{
	Node *New = new Node;
	New->data = data;
	New->next = NULL;

	if (S->size == 0)
	{
		S->head = New;
	}
	else
	{
		New->next = S->head;
		S->head = New;
	}
	S->size++;
}



void pop(Stack *S)
{
	if (S->size == 0)
	{
		return;
	}
	else if (S->size == 1)
	{
		Node *tmp = S->head;
		S->head = NULL;
		S->size = 0;
		delete tmp;

	}
	else
	{
		Node *tmp = S->head;
		S->head = S->head->next;
		S->size--;
		delete tmp;
	}
}
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt;
		cin >> cnt;
		int arr[10000];
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
		}

		int sp = 1;
		int flag = 0;
		int i = 0;
		Stack *S = new Stack;
		S->size = 0;
		S->head = NULL;
		push(S, sp++);
		while (1)
		{
			if (i == cnt)
				break;
			if (sp == cnt+2)
			{
				flag = 1;
				break;
			}
			if (S->head!=NULL&&arr[i] == S->head->data)
			{
				pop(S);
				i++;
			}
			else
			{
				push(S, sp++);
			}
		}
		if (flag == 1)
		{
			cout << "No" << endl;
		}
		else
			cout << "Yes" << endl;



	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}