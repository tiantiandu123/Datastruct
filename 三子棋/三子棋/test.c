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
	init_board(board, ROWS, COLS);//���̳�ʼ��
	display_board(board, ROWS, COLS);//��ӡ����
	while (1)
	{
		player_board(board, ROWS, COLS);//�������
		display_board(board, ROWS, COLS);
		if (winner(board, ROWS, COLS) == 1)
		{
			printf("��Ӯ��\n");
			break;
		}
		else if (winner(board, ROWS, COLS) == 3)
		{
			printf("ƽ��\n");
			break;
		}
		comp_board(board, ROWS, COLS);//��������
		display_board(board, ROWS, COLS);
		if (winner(board, ROWS, COLS) == 2)
		{
			printf("����Ӯ��\n");
			break;


		}
		else if (winner(board, ROWS, COLS) == 3)
		{
			printf("ƽ��\n");
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
		printf("��ѡ�� ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("�������");
			break;
		}
	} while (input);
	return 0;
}