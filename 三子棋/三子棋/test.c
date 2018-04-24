#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void venu()
{
	printf("*****************************\n");
	printf("******1.play 0.exit**********\n");
	printf("*****************************\n");


}
game()
{

	char board[ROWS][COLS];
	init_board(board, ROWS, COLS);//棋盘初始化
	display_board(board, ROWS, COLS);//打印棋盘
	while (1)
	{
		player_board(board, ROWS, COLS);//玩家下棋
		display_board(board, ROWS, COLS);
		if (winner(board, ROWS, COLS) == 1)
		{
			printf("你赢了\n");
			break;
		}
		else if (winner(board, ROWS, COLS) == 3)
		{
			printf("平局\n");
			break;
		}
		comp_board(board, ROWS, COLS);//电脑下棋
		display_board(board, ROWS, COLS);
		if (winner(board, ROWS, COLS) == 2)
		{
			printf("电脑赢了\n");
			break;


		}
		else if (winner(board, ROWS, COLS) == 3)
		{
			printf("平局\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	venu();
	do
	{
		printf("请选择 ：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入错误");
			break;
		}
	} while (input);
	return 0;
}