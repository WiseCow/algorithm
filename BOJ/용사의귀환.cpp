#include <iostream>
using namespace std;

struct _node
{
	int x;
	int y;
	int cnt;
	struct _node *next;
};

struct Queue
{
	int num;
	_node *front;
	_node *rear;

};

void enqueu(Queue *Qu, int x, int y, int cnt)
{
	_node *NEW = new _node;

	NEW->x = x;
	NEW->y = y;
	NEW->cnt = cnt;
	NEW->next = NULL;
	if (Qu->num == 0)
	{
		Qu->front = NEW;
		Qu->rear = NEW;
	}
	else
	{
		Qu->rear->next = NEW;
		Qu->rear = NEW;
	}
	Qu->num++;
}



void fdequeu(Queue *Qu, char(*map)[50], int(*fmap)[50],int R, int C)
{
	while (Qu->num != 0)
	{
		_node *tmp = Qu->front;
		int x = tmp->x;
		int y = tmp->y;
		int cnt = tmp->cnt;

		if ((map[x][y] != 'X' || map[x][y] != 'D')&&fmap[x][y]==0)
		{
			fmap[x][y] = cnt;

			if (x - 1 >= 0 && (map[x - 1][y] == '.' || map[x - 1][y] == 'S'))
				enqueu(Qu, x - 1, y, cnt + 1);
			if (x + 1 < R && (map[x + 1][y] == '.' || map[x + 1][y] == 'S'))
				enqueu(Qu, x + 1, y, cnt + 1);
			if (y - 1 >= 0 && (map[x][y-1] == '.' || map[x][y-1] == 'S'))
				enqueu(Qu, x, y-1, cnt + 1);
			if (y+1<C && (map[x][y+1] == '.' || map[x][y+1] == 'S'))
				enqueu(Qu, x, y+1, cnt + 1);
		}
		Qu->front = Qu->front->next;
		Qu->num--;
		delete(tmp);
	}
}
void kdequeu(Queue *Qu, char(*map)[50], int(*fmap)[50],int (*kmap)[50], int R, int C)
{
	while (Qu->num != 0)
	{
		_node *tmp = Qu->front;
		int x = tmp->x;
		int y = tmp->y;
		int cnt = tmp->cnt;

		if (map[x][y] != 'X'&& kmap[x][y] == 0 && (fmap[x][y]>cnt || fmap[x][y]==0 || map[x][y] == 'D'))
		{
			kmap[x][y] = cnt;

			if (x - 1 >= 0 && (map[x - 1][y] == '.' || map[x - 1][y] == 'D'))
				enqueu(Qu, x - 1, y, cnt + 1);
			if (x + 1 < R && (map[x + 1][y] == '.' || map[x + 1][y] == 'D'))
				enqueu(Qu, x + 1, y, cnt + 1);
			if (y - 1 >= 0 && (map[x][y - 1] == '.' || map[x][y - 1] == 'D'))
				enqueu(Qu, x, y - 1, cnt + 1);
			if (y + 1<C && (map[x][y + 1] == '.' || map[x][y + 1] == 'D'))
				enqueu(Qu, x, y + 1, cnt + 1);
		}
		Qu->front = Qu->front->next;
		Qu->num--;
		delete(tmp);
	}
}

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int R, C;
		cin >> R >> C;
		char map[50][50] = { 0 };
		int firemap[50][50] = { 0 }, knightmap[50][50] = { 0 };

		Queue *Quf = new Queue;
		Quf->num = 0;
		Quf->front = NULL;
		Quf->rear = NULL;
		

		Queue *Quk = new Queue;
		Quk->num = 0;
		Quk->front = NULL;
		Quk->rear = NULL;
		int dx, dy;
		for (int i = 0; i < R; i++)
		{
			cin >> map[i];
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] == '*')
					enqueu(Quf, i, j, 1);
				if (map[i][j] == 'S')
					enqueu(Quk, i, j, 1);
				if (map[i][j] == 'D')
				{
					dx = i;
					dy = j;
				}
			}
		}

		fdequeu(Quf, map,firemap, R, C);
		kdequeu(Quk, map, firemap,knightmap ,R, C);

		if (knightmap[dx][dy] == 0)
			cout << "impossible" << endl;
		else
			cout << knightmap[dx][dy]-1 << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}