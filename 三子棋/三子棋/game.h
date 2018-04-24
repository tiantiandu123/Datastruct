#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#define ROWS 3
#define COLS 3
void init_board(char board[ROWS][COLS], int row, int col);
void display_board(char board[ROWS][COLS], int row, int col);
void com_board(char board[ROWS][COLS], int row, int col);
void player_board(char board[ROWS][COLS], int row, int col);

int winner(char board[ROWS][COLS], int row, int col);
int loser(char board[ROWS][COLS], int row, int col);
#endif
