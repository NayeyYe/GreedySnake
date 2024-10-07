#pragma once
#ifndef FOOD_H
#define FOOD_H


#include "Snake.h"


class Snake;
class Food
{
public:
	Food() : count(0), flash_flag(false), big_flag(false), x(0), y(0), big_x(0), big_y(0), progress_bar(0) {}
	// 加上Snake的原因是，不要让食物的坐标和蛇的坐标重合
	// 画一个小食物
	void DrawFood(Snake&);
	// 画一个限时大食物
	void DrawBigFood(Snake&);
	// 获取食物生成了多少
	int GetCount();
	// 闪烁限时食物
	void FlashBigFood();
	// 判断是否需要大食物
	bool GetBigFlag();
	// 获取进度条
	int GetProgressBar();
private:
	// 限时食物的坐标
	int big_x, big_y;
	// 小食物的坐标
	int x, y;
	// 食物出现个数，计数器，记录出现了多少次食物
	int count;
	// 进度条计时器
	int progress_bar;
	// 限时食物标记判断
	bool big_flag;
	// 进度条判断器
	bool flash_flag;
	// 把Snake变成友元
	friend class Snake;
};

#endif // !FOOD_H
