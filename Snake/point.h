#pragma once
#ifndef POINT_H
#define POINT_H
// ����ļ���������ͼ��

class Point
{
public:
	Point(){}
	// x,y ��ʾ���꣬��Point���˽�г�Ա
	Point(const int x, const int y) : x(x), y(y) {}
	// ��ӡ����
	void Print();
	//	��ȡ��ǰ�ַ���X,Y����
	int GetX();
	int GetY();
	// �ı���ŵ�X,Y����
	void ChangePosition(const int x, const int y);
	// ��ӡԲ��
	void PrintCircular();
	// �ж�����Point���ʵ�������ǲ�����ͬ��
	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
	// ������
	void Clear();
private:
	int x, y;
};
#endif // !POINT_H
