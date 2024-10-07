#pragma once
#ifndef SNAKE_H
#define SNAKE_H


#include<deque>

#include "Food.h"
#include "point.h"
// ��ʳ����߰�
class Food;
class Snake
{
public:
	// �������˶�������������
	enum Direction {UP, DOWN, LEFT, RIGHT};
	// ��ʼ���ߵ���Ϣ
	Snake()
	{
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8);
		snake.emplace_back(16, 8);
		direction = Direction::DOWN;
	}
	// ��ʼ��Ԫ��
	void InitSnake();
	// ����������
	void Move();
	// ���ƶ�
	void NormalMove();
	// �ж��Ƿ񳬳�����
	bool OverEdge();
	// �ж��Ƿ�ײ���Լ�
	bool HitItSelf();
	// �ı䷽��
	bool ChangeDirection();
	// �߳Ե���Сʳ��
	bool GetFood(const Food&);
	// �߳Ե��˴�ʳ��
	bool GetBigFood(Food&);
private:
	std::deque<Point> snake;
	Direction direction;
	// ��Food���Ϊ��Ԫ�����ڷ���Food��˽��Ԫ��
	friend class Food;
};


#endif // !SNAKE_H
