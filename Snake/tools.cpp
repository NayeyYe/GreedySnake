#include<Windows.h>
#include<stdio.h>


#include "tools.h"

// ���ô��ڴ�С
void SetWindowSize(int cols, int lines)
{
	//���ô��ڱ���
	system("title GreedySnake");
	char cmd[30];
	// һ������ռ�������ַ�
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
	// �������´��ڳ��Ⱥ͸߶�
	system(cmd);
}

// �����ı���ɫ
void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}


// ������ƶ���(x, y)������
void SetCursorPosition(const int x, const int y)
{
	COORD position;
	// ����(x,y)�����λ��
	position.X = x * 2;
	position.Y = y;
	// ������̨�ϵĹ���ƶ���(x,y)��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


//�����ı���������ɫ
void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED
	);
}