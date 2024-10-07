#pragma once
#ifndef FOOD_H
#define FOOD_H


#include "Snake.h"


class Snake;
class Food
{
public:
	Food() : count(0), flash_flag(false), big_flag(false), x(0), y(0), big_x(0), big_y(0), progress_bar(0) {}
	// ����Snake��ԭ���ǣ���Ҫ��ʳ���������ߵ������غ�
	// ��һ��Сʳ��
	void DrawFood(Snake&);
	// ��һ����ʱ��ʳ��
	void DrawBigFood(Snake&);
	// ��ȡʳ�������˶���
	int GetCount();
	// ��˸��ʱʳ��
	void FlashBigFood();
	// �ж��Ƿ���Ҫ��ʳ��
	bool GetBigFlag();
	// ��ȡ������
	int GetProgressBar();
private:
	// ��ʱʳ�������
	int big_x, big_y;
	// Сʳ�������
	int x, y;
	// ʳ����ָ���������������¼�����˶��ٴ�ʳ��
	int count;
	// ��������ʱ��
	int progress_bar;
	// ��ʱʳ�����ж�
	bool big_flag;
	// �������ж���
	bool flash_flag;
	// ��Snake�����Ԫ
	friend class Snake;
};

#endif // !FOOD_H
