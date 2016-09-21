 
#include <iostream>
using namespace std;


int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int type;
		cin >> type;
		if (type == 0)
		{
			int front = 0, rear = 0;
			int queue[1000];
			while (1){
				char cmd[10];
				cin >> cmd;
				if (cmd[1] == 'U')
				{
					int input;
					cin >> input;
					queue[rear++] = input;
				}
				else if (cmd[1] == 'O')
				{
					if (front != rear)
						cout << queue[front++] << endl;
					else
						cout << -1 << endl;
				}
				else
				{
					for (int i = front; i < rear; i++)
					{
						cout << queue[i] << endl;
					}
					break;
				}
			}

			
		}
		else if (type == 1)
		{
			int front = 0, rear = 0;
			char queue[1000][1000];
			while (1)
			{
				char cmd[10];
				cin >> cmd;
				if (cmd[1] == 'U')
				{
					char input[1000];
					cin >> input;
					strcpy_s(queue[rear++], input);
				}
				else if (cmd[1] == 'O')
				{
					if (front != rear)
						cout << queue[front++] << endl;
					else
						cout << -1 << endl;
				}
				else
				{
					for (int i = front; i < rear; i++)
					{
						cout << queue[i] << endl;
					}
					break;
				}

			}
		}
		else if (type == 2)
		{
			int front = 0, rear = 0;
			double queue[1000];
			while (1){
				char cmd[10];
				cin >> cmd;
				if (cmd[1] == 'U')
				{
					double input;
					cin >> input;
					queue[rear++] = input;
				}
				else if (cmd[1] == 'O')
				{
					if (front != rear)
						printf("%.6f\n", queue[front++]);
					else
						cout << -1 << endl;
				}
				else
				{
					for (int i = front; i < rear; i++)
					{
						printf("%.6f\n", queue[i]);
					}
					break;
				}
			}

		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}