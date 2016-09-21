#include<cstdio>
char input[31];
int num[31], idx;
struct node
{
	char data;
	int value;
	node *next;
};
struct stack
{
	int size;
	node *front;
};

stack st;
void pop()
{
	st.size--;
	st.front = st.front->next;
}
void sum()
{
	if (st.size>1 && st.front->next->data == 0)
	{
		st.front->next->value += st.front->value;
		pop();
		sum();
	}
}
int push(char in)
{
	if (st.size == 0)
	{
		node *tmp = new node;
		tmp->data = in;
		tmp->next = NULL;
		st.front = tmp;
		st.size++;
	}
	else
	{
		if (in == '(')
		{
			node *tmp = new node;
			tmp->data = in;
			tmp->next = st.front;
			st.front = tmp;
			st.size++;
		}
		else if (in == '[')
		{
			node *tmp = new node;
			tmp->data = in;
			tmp->next = st.front;
			st.front = tmp;
			st.size++;
		}
		else if (in == ']')
		{
			if (st.size&&st.front->data == '[')
			{
				st.front->data = 0;
				st.front->value = 3;
				sum();
			}
			else if (st.size&&st.front->data == 0)
			{
				if (st.size - 1 > 0 && st.front->next->data == '[')
				{
					int k = st.front->value;
					k *= 3;
					pop();
					st.front->data = 0;
					st.front->value = k;
					sum();
				}
				else
					return -1;
			}
		}
		else if (in == ')')
		{
			if (st.size&&st.front->data == '(')
			{
				st.front->data = 0;
				st.front->value = 2;
				sum();
			}
			else if (st.size&&st.front->data == 0)
			{
				if (st.size - 1 > 0 && st.front->next->data == '(')
				{
					int k = st.front->value;
					k *= 2;
					pop();
					st.front->data = 0;
					st.front->value = k;
					sum();
				}
				else
					return -1;
			}
		}
	}
	return 0;
}


int main()
{
	scanf("%s", &input);
	st.size = 0;
	st.front = NULL;

	for (int i = 0; input[i] != 0; i++)
	{
		if (push(input[i]) == -1)
		{
			printf("0\n");;
			return 0;
		}
	}
	if (st.front->data != 0||st.size!=1)
		printf("0\n");
	else
		printf("%d", st.front->value);
}