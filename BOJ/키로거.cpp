#include<iostream>
using namespace std;
char input[1000001];
struct _node
{
	char data;
	_node * next;
	_node * prev;
	int fra;

};
//struct qu
//{
//	int num;
//	_node *front;
//	_node *rear;
//
//};
//
//qu* initial(void)
//{
//	qu *queue = new qu;
//	queue->num = 0;
//	queue->front = NULL;
//	queue->rear = NULL;
//	return queue;
//
//}




_node * init()
{
	_node * first = new _node;
	first->data = 0;
	first->fra = 1;
	first->prev = NULL;
	_node *rear = new _node;
	rear->data = 0;
	rear->fra = 2;
	rear->next = NULL;
	rear->prev = first;
	first->next = rear;
	return rear;
}


void print(_node *first)
{
	while (first)
	{
		if (first->fra == 0)
			cout << first->data;

		first = first->next;
	//	delete first->prev;
	}

}

int main()
{
	int itr;
	scanf("%d",&itr);


	for (int i = 0; i < itr; i++)
	{
		scanf("%s", input);
		int inputptr = 0;

		_node * ptr=init();
		_node *first = ptr->prev;
		int num = 0;
		bool flag = 0;;

		while (input[inputptr] != 0)
		{
			if (input[inputptr] == '<')
			{
				if (ptr->prev->fra != 1)
				{
					ptr = ptr->prev;
				}
			}
			else if (input[inputptr] == '>')
			{
				if (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
			}
			else if (input[inputptr] == '-')
			{
				if (ptr->prev->fra != 1)
				{
					_node *tmp = ptr->prev;
					ptr = ptr->prev->prev;
					ptr->next = tmp->next;
					tmp->next->prev = ptr;
					ptr = ptr->next;
					delete tmp;
				}
			}
			else
			{
				_node *newnode = new _node;
				newnode->data = input[inputptr];
				newnode->fra = 0;
				newnode->prev = ptr->prev;
				newnode->next = ptr;

				ptr->prev->next = newnode;
				ptr->prev = newnode;
			}

			inputptr++;
		}
		//cout << first->data << endl;
		print(first);
		cout << endl;
	}

	return 0;
}