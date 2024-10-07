#pragma once
#ifndef  CONTROLLER_H
#define CONTROLLER_H


// ��Ϸȫ�ֿ���
class Controller
{
public:
	// ���ƿ�ʼ����
	void Start();
	// ����һ����ʼ����
	void Select();
	// ��ʼ������Ϸ����
	void DrawGame();
	// ��Ϸ����ѭ��
	int PlayGame();
	// ��Ϸ�˵�
	int Menu();
	// ���·���
	void UpdateScore(const int&);
	// �ػ����
	void RewriteScore();
	// ��Ϸ����
	int GameOver();
	//	��Ϸһ��ѭ��
	void Game();
private:
	// ��ʾ�ߵ��ٶ�
	int speed;
	// ��ʾѡ����һ��ģʽ�Ĵ���
	int key;
	// ����
	int score;
};
#endif // ! CONTROLLER_H
