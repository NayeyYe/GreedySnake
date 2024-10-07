#pragma once
#ifndef SNAKE_H
#define SNAKE_H


#include<deque>

#include "Food.h"
#include "point.h"
// 把食物和蛇绑定
class Food;
class Snake
{
public:
	// 定义蛇运动方向：上下左右
	enum Direction {UP, DOWN, LEFT, RIGHT};
	// 初始化蛇的信息
	Snake()
	{
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8);
		snake.emplace_back(16, 8);
		direction = Direction::DOWN;
	}
	// 初始化元素
	void InitSnake();
	// 蛇增长身体
	void Move();
	// 蛇移动
	void NormalMove();
	// 判断是否超出界面
	bool OverEdge();
	// 判断是否撞到自己
	bool HitItSelf();
	// 改变方向
	bool ChangeDirection();
	// 蛇吃到了小食物
	bool GetFood(const Food&);
	// 蛇吃到了大食物
	bool GetBigFood(Food&);
private:
	std::deque<Point> snake;
	Direction direction;
	// 把Food类变为友元，便于访问Food的私有元素
	friend class Food;
};


#endif // !SNAKE_H
