#include<Windows.h>
#include<stdio.h>


#include "tools.h"

// 设置窗口大小
void SetWindowSize(int cols, int lines)
{
	//设置窗口标题
	system("title GreedySnake");
	char cmd[30];
	// 一个方块占用两个字符
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
	// 设置以下窗口长度和高度
	system(cmd);
}

// 设置文本颜色
void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}


// 将光标移动到(x, y)坐标上
void SetCursorPosition(const int x, const int y)
{
	COORD position;
	// 设置(x,y)坐标的位置
	position.X = x * 2;
	position.Y = y;
	// 将控制台上的光标移动到(x,y)上
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


//设置文本背景的颜色
void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED
	);
}