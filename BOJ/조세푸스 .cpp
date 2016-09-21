#include<iostream>

using namespace std;
typedef struct que
{
	int num;
	struct que *next;
	struct que *prev;
}queu;


void insert(int _num, queu *qu)
{
	queu *New = (queu *)malloc(sizeof(queu));
	New->num = _num;
	New->next = qu->next;
	qu->next->prev = New;
	New->prev = qu;
	qu->next = New;
}
void pop(queu **qu)
{
	queu *tmp = (*qu)->next->prev;
	(*qu)->prev->next = (*qu)->next;
	(*qu)->next->prev = (*qu)->prev;
	*qu = (*qu)->prev;
	free(tmp);

}
void next(queu **qu)
{
	*qu = (*qu)->prev;
}
void print(queu *qu)
{
	int i=qu->num;
	int j = qu->next->num;
	if (i < j)


		cout << i << " " << j << endl;

	else
		cout << j << " " << i << endl;
}
int main()
{
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int people, seq;
		cin >> people >> seq;
		queu *qu = (queu *)malloc(sizeof(queu));
		qu->num = 1;
		qu->next = qu;
		qu->prev = qu;
		for (int i = 2; i <= people; i++)
			insert(i, qu);

		pop(&qu);
		people - 1;
		for (int i = people; i > 3; i--)
		{
			for (int j = 0; j < seq-1; j++)
				next(&qu);
			pop(&qu);
		}
		print(qu);


	}
}
