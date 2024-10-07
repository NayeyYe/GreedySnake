#pragma once
#ifndef POINT_H
#define POINT_H
// 这个文件用来画出图像

class Point
{
public:
	Point(){}
	// x,y 表示坐标，是Point类的私有成员
	Point(const int x, const int y) : x(x), y(y) {}
	// 打印方块
	void Print();
	//	获取当前字符的X,Y坐标
	int GetX();
	int GetY();
	// 改变符号的X,Y坐标
	void ChangePosition(const int x, const int y);
	// 打印圆形
	void PrintCircular();
	// 判断两个Point类的实例对象是不是相同的
	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
	// 清除输出
	void Clear();
private:
	int x, y;
};
#endif // !POINT_H
