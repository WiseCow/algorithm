#include<iostream>


using namespace std;


#define max 100
typedef struct _node{
	int data;

	_node*next;
} node;
typedef struct _list{
	int size;
	node* header;


	
} list;


list * createlist()
{
	list* tmp;
	tmp = new list;
	tmp->size = 0;
	tmp->header = NULL;
	return tmp;

}

                                                        

void addnode(list * L, int data)
{
	node* N = new node;
	N->data = data;
	N->next = NULL;
	if (L->header == NULL)
	{
		L->header = N;
		L->size++;

	}
	else
	{
		node* tmp = L->header;
		while (tmp->next != NULL)tmp = tmp->next;
		tmp->next = N;
		L->size++;



	}
}

void removenode(list* L, int index)
{
	if (L -> size == 0)return;
	else
	{
		node *del = L->header;
		node* tmp=NULL;
		if (index == 1)
		{
			tmp = del->next;
			L->header = tmp;
			delete del;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				tmp = del;
				del = del->next;
			}
			tmp->next = del->next;

			delete del;
		}
		L->size--;
	}
}



int serchnode(list *L, int data)
{
	int index = 0;

	node *tmp = L->header;
	for (index = 1; tmp->data != data&&tmp != NULL; index++)
		tmp = tmp->next;
	if (tmp == NULL)return - 1;
	return index;
}

int deletelist(list *L)
{
	node*tmp = L->header;
	while(tmp==NULL)
	{
	
		node *del = tmp;
		tmp = tmp->next;
		delete del;
	}

	delete L;
	return 0;

}

int main()
{
	list * L = createlist();
	addnode(L, 1);
	addnode(L, 2);
	addnode(L, 3);
	addnode(L, 4);
	removenode(L, 1);
	cout<<serchnode(L, 3)<<endl;
	deletelist(L);

}




