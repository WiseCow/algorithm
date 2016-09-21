#include <iostream>
using namespace std;
typedef struct st
{
	int data;
	struct st *Next;
} Stack;
void Push(Stack **stk, int num)
{
	if (*stk == NULL)
	{
		*stk = (Stack *)malloc(sizeof(Stack));
		(*stk)->data = num;
		(*stk)->Next = NULL;
	}
 	else
	{
		Stack *New  = (Stack *)malloc(sizeof(Stack));
		New->data = num;
		New->Next = *stk;
		*stk = New;
	}
}
void Pop(Stack **stk)
{
	Stack *tmp = *stk;

	cout << "Pop " << (*stk)->data << endl; 

	*stk = (*stk)->Next;
	

}
void Min(Stack *stk)
{
	int max=10000; 
	if (stk == NULL)
	{
		cout << "Empty" << endl;
		return;
	}

	while (1)
	{
		if ((stk)->data < max)
		{
			max = (stk)->data;
		}
		if ((stk)->Next != NULL)
		{
			stk = (stk)->Next;
		}
		else
		{
			break;
		}
	}
	cout << "Min " << max<<endl;


}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		Stack *stk=NULL;
		int num;
		cin >> num;
		
		for (int i = 0; i < num;)
		{
			char cmd[6];
			cin >> cmd;
			if (cmd[0] == 'P'&&cmd[1] == 'u')
			{
				i++;
				int j;
				cin >> j;
				Push(&stk, j);
				 
			}
			else if (cmd[0] == 'M')
			{
				i++;
				Min(stk);
			}
			else
			{
				i++;
				Pop(&stk);
			}
		}
	 
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}