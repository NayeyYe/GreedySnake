#include<iostream>


#include "food.h"
#include "tools.h"


// 绘制食物
void Food::DrawFood(Snake& csnake)
{
	// 利用rand函数获得食物坐标
	// 将范围限制在2-29内， 即在地图内
	// 如果食物坐标和蛇的坐标重合，就重新获取食物坐标
	// 每5个食物就会出现一个限时食物
	while (true)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;

		// 获取每一个蛇身子方块的坐标
		// 如果和食物坐标相同，就重新获取随机数
		for (auto& point : csnake.snake)
		{
			// 食物分为小食物和限时大食物 
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y))
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			continue;
		}

		x = tmp_x;
		y = tmp_y;
		SetCursorPosition(x, y);
		SetColor(13);
		std::cout << "★";
		// 每次食物出现就给计数器加1
		count++;

		// 出现5次小食物就要出现一次大食物
		if (count % 5 == 0)
		{
			DrawBigFood(csnake);
		}
		break;
	}
}


// 画一个大食物
void Food::DrawBigFood(Snake& csnake)
{
	// 画一个进度条
	SetCursorPosition(5, 0);
	SetColor(11);
	// 进度条
	std::cout << "------------------------------------------";
	progress_bar = 42;
	while (true)
	{
		// 前面的判断和DrawFood步骤一样
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.snake)
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		// 开始设置大食物的坐标big_x, big_y
		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(big_x, big_y);
		SetColor(18);
		// 大食物的形状是方块
		std::cout << "■";
		// big_flag 用来判断他是不是限时食物
		big_flag = true;
		// flash_flag用来判断食物进度条
		flash_flag = true;
		break;
	}

}	


// 获取食物生成了多少
int Food::GetCount()
{
	return count;
}


// 闪烁限时食物
void Food::FlashBigFood()
{
	SetCursorPosition(big_x, big_y);
	SetColor(18);
	// 如果此时食物闪烁标记为True，就开始闪烁食物
	if (flash_flag)
	{
		std::cout << "  ";
		flash_flag = false;
	}
	else
	{
		std::cout << "■";
		flash_flag = true;
	}

	SetCursorPosition(26, 0);
	SetColor(11);
	// 进度条缩短
	for (int i = 42; i >= progress_bar; --i)
	{
		std::cout << "\b \b";
	}
	--progress_bar;
	if (progress_bar == 0)
	{
		SetCursorPosition(big_x, big_y);
		std::cout << "  ";
		big_flag = false;
		big_x = 0;
		big_y = 0;
	}
}


// 判断是否需要大食物
bool Food::GetBigFlag()
{
	return big_flag;
}


// 获取进度条
int Food::GetProgressBar()
{
	return progress_bar;
}