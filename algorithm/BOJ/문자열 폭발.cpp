//https://www.acmicpc.net/problem/9935
//개같은문제 이거 답이 좀이상함
#include<iostream>
using namespace std;
char input[1000001];
char ex[100];
bool popword[1000001];
int exlen;

struct node
{
	int inp;
	int exp;
	node *next;

};
struct stack
{
	int num;
	node *top;
};

void push(stack *S, int in, int ex)
{
	node *Ne = new node;
	Ne->inp = in;
	Ne->exp = ex;

	if (S->num == 0)
	{
		Ne->next = NULL;
		S->top = Ne;
	}
	else
	{
		Ne->next = S->top;
		S->top = Ne;
	}
	S->num++;
}
void popone(stack *S)
{
	if (S->num != 0)
	{
		node *tmp = S->top;
		S->top = S->top->next;
		S->num--;

		delete tmp;
	}
}

void pop(stack *s)
{
	while (s->num != 0)
	{
		node *tmp = s->top;

		s->top = s->top->next;
		s->num--;
		delete tmp;
	}
}

int main()
{
	int len = 0;
	scanf("%s", &input);
	scanf("%s", &ex);

	while (input[len] != 0)len++;
	while (ex[exlen] != 0)exlen++;

	stack *S = new stack;
	S->top = NULL;
	S->num = 0;

	int flag = 0;
	int cnt = 0;
	if(exlen!=1)
	for (int i = 0; input[i] != 0; i++)
	{
		if (popword[i] == 1)
			continue;
		int p;
		if (S->num == 0)
			p = -1;
		else
			p = S->top->exp;
		p++;



		if (input[i] == ex[0])
		{
			push(S, i, 0);
		}
		else
		{
			if (S->num != 0)
			{
				if (input[i] == ex[S->top->exp + 1])
				{
					push(S, i, S->top->exp + 1);
					if (S->top->exp + 1 == exlen)
					{
						for (int l = 0; l < exlen; l++)
						{
							popword[S->top->inp] = 1;
							popone(S);
						}
					}
				}
				else
				{
					pop(S);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
			if (input[i] == ex[0])
				popword[i] = 1;
	}
	bool chkp = 0;

		for (int i = 0; i < len; i++)
		{
			if (popword[i] == 0)
			{
				cout << input[i];
				chkp = 1;
			}
		}
		if (chkp == 0)
			cout << "FRULA";
		cout << endl;

}


//#include <cstdio>
//#include <stack>
//#include <cstring>
//using namespace std;
//char a[1000001];
//bool erased[1000001];
//char b[100];
//int main() {
//	scanf("%s", a);
//	scanf("%s", b);
//	int n = strlen(a);
//	int m = strlen(b);
//	if (m == 1) {
//		for (int i = 0; i<n; i++) {
//			if (a[i] == b[0]) {
//				erased[i] = true;
//			}
//		}
//	}
//	else {
//		stack<pair<int, int>> s;
//		for (int i = 0; i<n; i++) {
//			if (a[i] == b[0]) {
//				s.push(make_pair(i, 0));
//			}
//			else {
//				if (!s.empty())
//				{
//					auto p = s.top();
//					if (a[i] == b[p.second + 1])
//					{
//						s.push(make_pair(i, p.second + 1));
//						if (p.second + 1 == m - 1) {
//							for (int k = 0; k<m; k++)
//							{
//								auto p = s.top();
//								erased[p.first] = true;
//								s.pop();
//							}
//						}
//					}
//					else
//					{
//						while (!s.empty())
//						{
//							s.pop();
//						}
//					}
//				}
//			}
//		}
//	}
//	bool printed = false;
//	for (int i = 0; i<n; i++) {
//		if (erased[i]) continue;
//		printf("%c", a[i]);
//		printed = true;
//	}
//	if (!printed) {
//		printf("FRULA\n");
//	}
//	return 0;
//}
