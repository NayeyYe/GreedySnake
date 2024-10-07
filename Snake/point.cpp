#include<iostream>


#include "point.h"
#include "tools.h"

void Point::Print()
{
	// 调用tools.h中的SetCursorPosition函数
	// 将光标移动到(x,y)位置
	// 输出方块元素
	SetCursorPosition(x, y);
	// 用utf8编码来打出方块字符
	std::cout << "■";
}

// 获取符号的X坐标
int Point::GetX()
{
	return this->x;
}


//获取符号的Y坐标
int Point::GetY()
{
	return this->y;
}


// 改变符号的坐标
void Point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
}


// 打印圆形
void Point::PrintCircular()
{
	// 调用tools.h中的SetCursorPosition函数
	// 将光标移动到(x,y)位置
	// 输出实心圆元素
	SetCursorPosition(x, y);
	std::cout << "●";
}


//清除输出
void Point::Clear()
{
	SetCursorPosition(x, y);
	std::cout << "  ";
}