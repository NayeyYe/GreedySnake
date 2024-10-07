#include<iostream>


#include "point.h"
#include "tools.h"

void Point::Print()
{
	// ����tools.h�е�SetCursorPosition����
	// ������ƶ���(x,y)λ��
	// �������Ԫ��
	SetCursorPosition(x, y);
	// ��utf8��������������ַ�
	std::cout << "��";
}

// ��ȡ���ŵ�X����
int Point::GetX()
{
	return this->x;
}


//��ȡ���ŵ�Y����
int Point::GetY()
{
	return this->y;
}


// �ı���ŵ�����
void Point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
}


// ��ӡԲ��
void Point::PrintCircular()
{
	// ����tools.h�е�SetCursorPosition����
	// ������ƶ���(x,y)λ��
	// ���ʵ��ԲԪ��
	SetCursorPosition(x, y);
	std::cout << "��";
}


//������
void Point::Clear()
{
	SetCursorPosition(x, y);
	std::cout << "  ";
}