
#include <iostream>
using namespace std;

typedef struct stc
{
	int num;
	struct stc *next;
	
} stack;


void push(stack **stk, int _num)
{
	if (*stk == NULL)
	{
		stack *st1 = (stack *)malloc(sizeof(stack));
		st1->next = NULL;
		st1->num = _num;
		*stk = st1;

	}
	else
	{
		stack *New = (stack *)malloc(sizeof(stack));
		New->num = _num;
		New->next = NULL;
		New->next = *stk;
		*stk = New;
	}

}
void pop(stack**stk)
{
	stack *tmp = *stk;
	cout << (*stk)->num<<endl;
	if ((*stk)->next != NULL)
		*stk = (*stk)->next;
	else
		*stk = NULL;
	free(tmp);
}
int main()
{

	int nCount;		

	cin >> nCount;

	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		stack *st1;
		int cnt;
		cin >> cnt;
		char order[2];
		int numb;
		int size = 0;

		for (int i = 0; i < cnt;)
		{
			cin >> order;
			if (order[0] == 'i')
			{
				cin >> numb;
				size++;
				i++;
				push(&st1, numb);
			}
			else if (order[0] == 'o')
			{
				if (size > 0){
					size--;
					i++;
					pop(&st1);
				}
				else{

					cout << "empty" << endl;
					i++;
				}


			}
			else
			{
				
				cout << size<<endl;
				i++;
			}
		}

		

		
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}