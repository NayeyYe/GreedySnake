#include<Windows.h>


#include "Startinterface.h"

// 蛇从左边出现到完整出现的过程
void StartInterface::PrintFirst()
{
	// startsnake表示开始动画中的蛇
	// 蛇的每一个元素都表示方块
	// 遍历每一蛇中的每一个元素，将每一个元素都打印出来
	// speed表示动画需要动起来
	for (auto& point : startsnake)
	{
		point.Print();
		Sleep(speed);
	}
}


// 蛇从左边跑到右边的全过程
void StartInterface::PrintSecond()
{
	// 蛇头从10位置移动到40
	for (int i = 10; i != 40; i++)
	{
		// 计算蛇头的下一个位置，并且将其压入startsnake中
		// 绘制出来，并且将蛇尾去掉
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		startsnake.emplace_back(Point(i, j));
		startsnake.back().Print();
		startsnake.front().Clear();
		startsnake.pop_front();
		Sleep(speed);
	}
}


// 蛇从右边消失的过程
void StartInterface::PrintThird()
{
	//如果蛇还没有消失或者文字没有移动到指定位置的时候
	while (!startsnake.empty() || textsnake.back().GetX() < 33)
	{
		// 如果蛇没有消失
		if (!startsnake.empty())
		{
			// 让最右边的蛇头消失
			startsnake.front().Clear();
			startsnake.pop_front();
		}
		// 清除已有的文字
		ClearText();
		// 绘制更新位置之后的文字
		PrintText();
		Sleep(speed);
	}
}


// 打印文字
void StartInterface::PrintText()
{
	// textsnake表示SNAKE文字
	// 将每一个SNAKE文字中的块point输出
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
		{
			point.Print();
		}
	}
}


//清除SNAKE文字
void StartInterface::ClearText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Clear();
		// 改变一下文字的位置
		point.ChangePosition(point.GetX() + 1, point.GetY());
	}
}

// 动画：蛇从左边出现到消失的全部过程
void StartInterface::Action()
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}