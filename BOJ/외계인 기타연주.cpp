#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s[7];


	int tc, max;
	cin >> tc >> max;


	int cnt=0;
	for (int itr = 0; itr < tc; itr++)
	{
		int line, code;
		cin >> line >> code;
		while (!s[line].empty()&&s[line].top()>code)
		{
			s[line].pop();
			cnt++;
		}
		if (!s[line].empty())
		{
			if (s[line].top() != code)
			{
				s[line].push(code);
				cnt++;
			}
		}
		else
		{
			s[line].push(code);
			cnt++;
		}
	}
	cout << cnt << endl;

}



//#include<iostream>
//using namespace std;
//struct _node
//{
//	int flat;
//	_node *prev;
//};
//
//struct sta
//{
//	int num;
//	_node *top;
//
//};
//
//sta* init()
//{
//	sta *stackt = new sta;
//	stackt->num = 0;
//	stackt->top = NULL;
//	return stackt;
//}
//sta* s1;
//sta* s2;
//sta* s3;
//sta* s4;
//sta* s5;
//sta* s6;
//int fing;
//void pop(int line, int fnumber)
//{
//	switch (line)
//	{
//	case 1:
//		while (s1->num != 0&&s1->top->flat > fnumber)
//		{
//			_node *tmp = s1->top;
//			s1->top = tmp->prev;
//			s1->num--;
//			delete tmp;
//			fing++;
//			//cout << "1¶À" << endl;
//		}
//		break;
//	case 2:
//		while (s2->num != 0&&s2->top->flat > fnumber)
//		{
//			_node *tmp = s2->top;
//			s2->top = tmp->prev;
//			s2->num--;
//			delete tmp;
//			fing++;
//			//cout << "2¶À" << endl;
//		}
//		break;
//	case 3:
//		while (s3->num != 0&&s3->top->flat > fnumber)
//		{
//			_node *tmp = s3->top;
//			s3->top = tmp->prev;
//			s3->num--;
//			delete tmp;
//			fing++;
//		}
//		break;
//	case 4:
//		while (s4->num != 0 && s4->top->flat > fnumber)
//		{
//			_node *tmp = s4->top;
//			s4->top = tmp->prev;
//			s4->num--;
//			delete tmp;
//			fing++;
//		}
//		break;
//	case 5:
//		while (s5->num != 0 && s5->top->flat > fnumber)
//		{
//			_node *tmp = s5->top;
//			s5->top = tmp->prev;
//			s5->num--;
//			delete tmp;
//			fing++;
//		}
//		break;
//	case 6:
//		while (s6->num != 0 && s6->top->flat > fnumber)
//		{
//			_node *tmp = s6->top;
//			s6->top = tmp->prev;
//			s6->num--;
//			delete tmp;
//			fing++;
//		}
//		break;
//	}
//}
//
//void push(int line, int fnumber)
//{
//	_node *new_node = new _node;
//	new_node->flat = fnumber;
//	new_node->prev = NULL;
//	switch (line)
//	{
//	case 1:
//		pop(line, fnumber);
//		if (s1->num == 0||s1->top->flat!=fnumber)
//		{	s1->num++;
//		new_node->prev = s1->top;
//		s1->top = new_node;
//		fing++;
//		}
//		break;
//	case 2:
//		pop(line, fnumber);
//		if (s2->num == 0 || s2->top->flat != fnumber)
//		{
//			s2->num++;
//			new_node->prev = s2->top;
//			s2->top = new_node;
//			fing++;
//		}
//
//	//	cout << "2´©¸§" << endl;
//		break;
//	case 3:
//		pop(line, fnumber);
//		if (s3->num == 0 || s3->top->flat != fnumber)
//		{
//			s3->num++;
//			new_node->prev = s3->top;
//			s3->top = new_node;
//			fing++;
//		}
//		break;
//	case 4:
//		pop(line, fnumber);
//		if (s4->num == 0 || s4->top->flat != fnumber)
//		{
//			s4->num++;
//			new_node->prev = s4->top;
//			s4->top = new_node;
//			fing++;
//		}
//		break;
//	case 5:
//		pop(line, fnumber);
//		if (s5->num == 0 || s5->top->flat != fnumber)
//		{
//			s5->num++;
//			new_node->prev = s5->top;
//			s5->top = new_node;
//			fing++;
//		}
//		break;
//	case 6:
//		pop(line, fnumber);
//		if (s6->num == 0 || s6->top->flat != fnumber)
//		{
//			s6->num++;
//			new_node->prev = s6->top;
//			s6->top = new_node;
//			fing++;
//		}
//		break;
//	}
//
//
//
//}
//int main()
//{
//
//	int N, flat;
//	scanf("%d %d", &N, &flat);
//	s1 = init();
//	s2 = init();
//	s3 = init();
//	s4 = init();
//	s5 = init();
//	s6 = init();
//	fing = 0;
//	
//
//	for (int i = 0; i < N; i++)
//	{
//		int line, fnumber;
//		scanf("%d %d", &line, &fnumber);
//
//		push(line, fnumber);
//
//	}
//
//	cout << fing << endl;
//
//
//
//
//
//}