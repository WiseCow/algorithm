#include <iostream>
#include<malloc.h>
using namespace std;

typedef struct que
{
	char cha[100];
	struct que *next;
	struct que *prev;
	int flag;
} que;

void dequeue(que *deq)
{
	que *tmp;

 	tmp = deq->prev->next;
	deq->next->prev = deq->prev;
	deq->prev->next = deq->next;

	free(tmp);
}

int main()
 {

	int nCount;		
	int num[100];
	char message[100];
	que *cmd=NULL;



	cin >> nCount;	
	for (int itr = 0; itr < nCount; itr++)
	{
		cin >> num[itr];

		for (int i = 0; i < num[itr];)
		{
			cin >> message;
			if (strcmp(message, "ADD")==0)
			{
				cin >> message;
				que * New = (que *)malloc(sizeof(que));
				strcpy_s(New->cha, message);
				if (cmd == NULL)
				{
					New->next = New;
					New->prev = New;
					cmd = New;
				}
				else
				{
					cmd->next->prev = New;
					New->next = cmd->next;
					New->prev = cmd;
					cmd->next = New;
				}
				i++;
			}
			else if (strcmp(message, "DEL")==0)
			{
				
				if (cmd->next != cmd)
				{
					que *tmp = cmd->prev->next;

					cmd = cmd->prev;
					cmd->next->next->prev = cmd;
					cmd->next = cmd->next->next;
					free(tmp);
				}
				else if (cmd->next == cmd){
					free(cmd);
					cmd = NULL;
				}
				else
				{
					cmd = NULL;
				}
				i++;
			}

		}
		cout << "#testcase" << (itr + 1) << endl;
		
		while (1){
			if (cmd->next != cmd)
			{
				cout << cmd->cha<<" ";
				que *tmp = cmd->prev->next;

				cmd = cmd->prev;
				cmd->next->next->prev = cmd;
				cmd->next = cmd->next->next;
				free(tmp);
			}
			else if (cmd->next == cmd){
				cout << cmd->cha << endl;;
				free(cmd);
				cmd = NULL;
				break;
			}
		}


	}



	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}