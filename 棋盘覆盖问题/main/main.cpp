#include<iostream>
#define ROW 4
#define COL 4
using namespace std;

int tile = 0;
int Board[ROW][COL];
static int c = 0;
FILE* fp;

void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	fprintf_s(fp, "第 %d 次\n",c++);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << Board[i][j]<<"\t";
			fprintf_s(fp, "%d\t", Board[i][j]);
		}
		cout << endl;
		fprintf_s(fp, "\n");
	}
	cout << endl;
	if (size == 1)
	{
		return;
	}
	int t = tile++;
	int s = size / 2;

	if (dr < tr + s && dc < tc + s)
	{
		ChessBoard(tr, tc, dr, dc, s);
	}
	else
	{
		Board[tr + s - 1][tc + s - 1] = t;
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
	}

	if (dr < tr + s && dc >= tc + s)
	{
		ChessBoard(tr, tc + s, dr, dc, s);
	}
	else
	{
		Board[tr + s - 1][tc + s] = t;
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
	}

	if (dr >= tr + s && dc < tc + s)
	{
		ChessBoard(tr + s, tc, dr, dc, s);
	}
	else
	{
		Board[tr + s][tc + s - 1] = t;
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
	}

	if (dr >= tr + s && dc >= tc + s)
	{
		ChessBoard(tr + s, tc + s, dr, dc, s);
	}
	else
	{
		Board[tr + s][tc + s] = t;
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
	}
}

int main()
{

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			Board[i][j] = -1;
		}
	}
	Board[0][1] = 0;
	fopen_s(&fp, "D:\\算法\\棋盘覆盖问题\\main\\result.txt", "w");
	ChessBoard(0, 0, 0, 1, 4);
}