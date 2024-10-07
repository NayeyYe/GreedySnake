#include<Windows.h>


#include "Startinterface.h"

// �ߴ���߳��ֵ��������ֵĹ���
void StartInterface::PrintFirst()
{
	// startsnake��ʾ��ʼ�����е���
	// �ߵ�ÿһ��Ԫ�ض���ʾ����
	// ����ÿһ���е�ÿһ��Ԫ�أ���ÿһ��Ԫ�ض���ӡ����
	// speed��ʾ������Ҫ������
	for (auto& point : startsnake)
	{
		point.Print();
		Sleep(speed);
	}
}


// �ߴ�����ܵ��ұߵ�ȫ����
void StartInterface::PrintSecond()
{
	// ��ͷ��10λ���ƶ���40
	for (int i = 10; i != 40; i++)
	{
		// ������ͷ����һ��λ�ã����ҽ���ѹ��startsnake��
		// ���Ƴ��������ҽ���βȥ��
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		startsnake.emplace_back(Point(i, j));
		startsnake.back().Print();
		startsnake.front().Clear();
		startsnake.pop_front();
		Sleep(speed);
	}
}


// �ߴ��ұ���ʧ�Ĺ���
void StartInterface::PrintThird()
{
	//����߻�û����ʧ��������û���ƶ���ָ��λ�õ�ʱ��
	while (!startsnake.empty() || textsnake.back().GetX() < 33)
	{
		// �����û����ʧ
		if (!startsnake.empty())
		{
			// �����ұߵ���ͷ��ʧ
			startsnake.front().Clear();
			startsnake.pop_front();
		}
		// ������е�����
		ClearText();
		// ���Ƹ���λ��֮�������
		PrintText();
		Sleep(speed);
	}
}


// ��ӡ����
void StartInterface::PrintText()
{
	// textsnake��ʾSNAKE����
	// ��ÿһ��SNAKE�����еĿ�point���
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
		{
			point.Print();
		}
	}
}


//���SNAKE����
void StartInterface::ClearText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Clear();
		// �ı�һ�����ֵ�λ��
		point.ChangePosition(point.GetX() + 1, point.GetY());
	}
}

// �������ߴ���߳��ֵ���ʧ��ȫ������
void StartInterface::Action()
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}