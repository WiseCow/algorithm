#include<iostream>

typedef struct data{
	int x;
	int y;
	struct data * next;


}data;

typedef struct queue{
	data *rear;
	data *front;
	int size;
}Queue;



void createnode(Queue *Q, int x, int y)
{
	data *New = new data;
	New->x = x;
	New->y = y;
	New->next = NULL;

	Q->front = New;
	Q->rear = New;
	Q->size++;
	
}
void insertnode(Queue *Q, int x, int y)
{
	if (Q->size != 0)
	{
		data *New = new data;
		New->x = x;
		New->y = y;
		New->next = NULL;

		Q->rear->next = New;
		Q->rear = New;
		Q->size++;
		//data *tmp = Q->front;

		//while (tmp->next != NULL)
		//{
		//	tmp = tmp->next;
		//}
		//tmp->next = New;
		//Q->rear = New;

	}
}
void deletenode(Queue *Q)
{
	if (Q->size != 0)
	{
		data* tmp = Q->front;
		if (tmp->next != NULL)
			Q->front = Q->front->next;
		else
		{
			Q->front = NULL;
			Q->rear = NULL;
		}
		delete(tmp);
	}
}

int main()
{

	Queue Q;
	int x = 0; 
	int y = 1;
	createnode(&Q, x, y);
	x++, y++;
	insertnode(&Q, x, y);
	deletenode(&Q);

	std::cout << Q.front->x << " " << Q.front->y << std::endl;
}