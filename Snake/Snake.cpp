#include<iostream>
#include<conio.h>


#include "tools.h"
#include "Snake.h"

void Snake::InitSnake()
{
	for (auto& point : snake)
	{
		// 蛇身体的每一个元素是圆形
		point.PrintCircular();
	}
}


// 移动蛇
void Snake::Move()
{
	switch (direction)
	{
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	default:
		break;
	}
	SetColor(14);
	snake.back().PrintCircular();
}


// 蛇正常移动
void Snake::NormalMove()
{
	Move();
	snake.front().Clear();
	snake.pop_front();
}


//判断是否超出界面
bool Snake::OverEdge()
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}


// 判断是否撞到自己
bool Snake::HitItSelf()
{
	std::deque<Point>::size_type count = 1;
	// 获取头部坐标
	Point *head = new Point(snake.back().GetX(), snake.back().GetY());
	// 如果蛇身体中有的元素坐标就是蛇头坐标，那么这个蛇撞到自己了
	for (auto& point : snake)
	{
		if (!(point == *head))
		{
			count++;
		}
		else
		{
			break;
		}
	}
	delete head;
	if (count == snake.size())
		return true;
	else
		return false;
}


// 改变方向
bool Snake::ChangeDirection()
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效
					direction = Direction::UP;
				break;
			case 80:
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75:
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;

		case 27://ESC
			return false;

		default:
			return true;
		}
	}
	return true;
}


bool Snake::GetFood(const Food& cfood)
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
		return true;
	else
		return false;
}


bool Snake::GetBigFood(Food& cfood)
{
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1, 0);
		std::cout << "                                                            ";
		return true;
	}
	else
		return false;
}