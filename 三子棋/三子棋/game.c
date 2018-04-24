#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void init_board(char board[ROWS][COLS], int row, int col)//棋盘初始化
{
	memset(board ,' ', ROWS*COLS*sizeof(board[0][0]));
}
void display_board(char board[ROWS][COLS], int row, int col)//棋盘的打印展示
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i != 2)
		{
			printf("---|---|---\n");
		}
	}
}
void player_board(char board[ROWS][COLS], int row, int col)//玩家下棋
	{
		int x = 0;
		int y = 0;
		flag1:
		printf("请输入坐标:");
		scanf("%d%d",&x,&y);
		x = x - 1;
		y = y - 1;
		if ((x >= 0) && (x <= 2) && (y >= 0) && (y <= 2))
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = 'x';
			}
			else
			{
				printf("输入错误\n");
				goto flag1;
			}
		}
		else
		{
			goto flag1;
		}
		printf("\n");
	}
void comp_board(char board[ROWS][COLS], int row, int col)//电脑下
	{
	srand((unsigned int)time(NULL));
		while (1)
		{
			int x = rand() % 3;
			int y = rand() % 3;
			if (board[x][y] == ' ')
			{
				board[x][y] = 'o';
				break;
		      }
		}
		printf("\n");
	}
int winner (char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == 'x')//人的行判断
		{
			return 1;
		}
		
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == 'o')//电脑的行判断
		{
			return 2;
		}
	}
	for (j = 0; j < col; j++)
	{


		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] == 'x')//人的列判断
		{
			return 1;
		}
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] == 'o')//电脑的列判断
		{
			return 2;
		}
	}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'x')//人的斜判断
		{
			return 1;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'x')//人的斜判断
		{
			return 1;
		}
		
		
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'o')//电脑的斜判断
		{
			return 2;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'o')//电脑的斜判断
		{
			return 2;
		}
		int C = is_full(board, ROWS, COLS);//判断是否满了
		if (C == 5)
		{
			return 3;
		}
}
int is_full(char board[ROWS][COLS], int row, int col)
{
		int i = 0;
		int j = 0;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					
					return 4;
				}
			}
		}
			return 5;	
}

