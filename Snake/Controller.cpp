#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>

#include "StartInterface.h"
#include "tools.h"
#include "Controller.h"
#include "Map.h"
#include "Snake.h"
#include "Food.h"

// ���ÿ�ʼ����
void Controller::Start()
{
	// ���ô��ڴ�С����
	SetWindowSize(41, 32);
	// ���ÿ�ʼ������ɫ
	SetColor(2);
	// ��ʼ����
	// ����һ��start��̬ʵ�����ڿ���Action����
	StartInterface* start = new StartInterface();
	start->Action();
	// ɾ��start���ͷ��ڴ�
	delete start;

	// ���ù���λ�ã����������ʾ��ȴ�������������
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start ...";
	SetCursorPosition(13, 27);
	system("pause");
}


// ����һ����Ϸѡ�����
void Controller::Select()
{
	// ��ʼ������ѡ��
	SetColor(3);
	// �����϶
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	// ��ʼѡ����Ϸ�Ѷ�
	SetCursorPosition(6, 21);
	std::cout << "Choose Game Difficulty��";
	SetCursorPosition(6, 22);
	std::cout << "Select with up and down keys";
	SetCursorPosition(6, 23);
	std::cout << "Enter to confirm";
	SetCursorPosition(27, 22);
	// ��һ��tools.h�е�SetBackColor��������һ�±�����ɫ
	// ��ɫ��ʾ������ѡ����һ��ѡ��
	SetBackColor();
	// ��ʼѡ��ģʽ�Ѷ�
	std::cout << "Simple Mode";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "Normal Mode";
	SetCursorPosition(27, 26);
	std::cout << "Hard Mode";
	SetCursorPosition(27, 28);
	std::cout << "Purgatory Mode";
	SetCursorPosition(0, 31);
	score = 0;


	// �������¼�ѡ��ģ��
	// ch��ʾ�����Ǽ����е����°���
	// ��72��UP����80��DOWN����
	int ch;
	// ��¼ѡ�е�ѡ���ʼѡ���ǵ�һ��
	key = 1;
	// ��¼�Ƿ���Enter��������ʼĬ��Ϊfalse
	bool flag = false;
	// ������UP��DOWNʱ��¼�밴�����жϰ���
	while ((ch = _getch()))
	{
		// ���¼��İ���
		switch (ch)
		{
		// ��������UP����
		case 72 :
			// �����ʱѡ�е�ʱ��һ��
			// ��ôUP�����ʱû�����õ�
			if (key > 1)
			{
				// �����������һ��ѡ��
				switch (key)
				{
				// �������ָ�������ͨģʽ
				case 2:
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "Simple Mode";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "Normal Mode";

					--key;
					break;

				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "Normal Mode";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "Hard Mode";

					--key;
					break;

				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "Hard Mode";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "Purgatory Mode";

					--key;
					break;
				}
			}
			break;
		// �����ʱ���µ���DOWN�����
		case 80:
			// �����ʱ�Ѿ�ѡ��������ģʽ
			// �Ͳ���������ѡ����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "Normal Mode";

					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "Simple Mode";

					++key;
					break;

				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "Hard Mode";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "Normal Mode";

					++key;
					break;

				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "Purgatory Mode";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "Hard Mode";

					++key;
					break;
				}
			}
			break;
		
		// ������µ���Enter�س���
		case 13:
			flag = true;
			break;

		// ������µ�����Ч����
		default:
			break;

		}

		// ����Enterȷ�����˳�ѡ�����
		if (flag)
			break;

		// ������ƶ������½��У���ֹ���Ӱ����Ϸ����
		SetCursorPosition(0, 31);
	}

	// ����Enter֮��Ҫ���˿�ѡ���ģʽ
	// ���ж�key��ֵ
	switch (key)
	{
	case 1:
		// �����ߵ��ٶ�Ϊ135
		speed = 135;
		break;
	case 2:
		// �����ߵ��ٶ�Ϊ135
		speed = 100;
		break;
	case 3:
		// �����ߵ��ٶ�Ϊ135
		speed = 60;
		break;
	case 4:
		// �����ߵ��ٶ�Ϊ135
		speed = 30;
		break;
	default:
		break;
	}
}


// ������Ϸ����
void Controller::DrawGame()
{
	// ����
	system("cls");
	// ���Ƶ�ͼ
	SetColor(3);
	Map* init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	//���Ʋ����
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(31, 4);
	std::cout << "Difficulty:";
	SetCursorPosition(36, 5);
	// �ж�һ��������ʲô�Ѷ�
	//������k��ֵ
	switch (key)
	{
	case 1:
		std::cout << "Simple Mode";
		break;
	case 2:
		std::cout << "Normal Mode";
		break;
	case 3:
		std::cout << "Hard Mode";
		break;
	case 4:
		std::cout << "Purgatory Mode";
		break;
	default:
		break;
	}
	// ��ʾ�÷�
	SetCursorPosition(31, 7);
	std::cout << "Scores:";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << "Press the directional keys to move";
	SetCursorPosition(33, 15);
	std::cout << "Press ESC to pause";
}


// ��Ϸ����ѭ��
int Controller::PlayGame()
{
	// ��ʼ���ߺ�ʳ��
	Snake* csnake = new Snake();
	Food* cfood = new Food();
	SetColor(6);
	// ��ʼ��csnakeԪ��
	csnake->InitSnake();
	// ������������ӣ���ʳ����������λ��
	srand((unsigned)time(NULL));
	cfood->DrawFood(*csnake);
	
	// ��Ϸѭ��
	// �ж��Ƿ񳬳����棬ײ���Լ�
	while (csnake->OverEdge() && csnake->HitItSelf())
	{
		// ����ѡ��˵�
		// �������Esc����
		if (!csnake->ChangeDirection())
		{
			int tmp = Menu();
			switch (tmp)
			{
			// ������Ϸ
			case 1:
				break;

			// ���¿�ʼ
			case 2:
				delete csnake;
				delete cfood;
				// ��1��ΪPlayGame��������ֵ
				return 1;

			case 3://�˳���Ϸ
				delete csnake;
				delete cfood;
				//��2��ΪPlayGame�����ķ���ֵ���ص�Game������
				// ��ʾ�˳���Ϸ
				return 2;
			default:
				break;
			}
		}

		// ����߳Ե���ʳ���ô������
		if (csnake->GetFood(*cfood)) //�Ե�ʳ��
		{
			csnake->Move();//������
			UpdateScore(1);//���·�����1Ϊ����Ȩ��
			RewriteScore();//���»��Ʒ���
			cfood->DrawFood(*csnake);//������ʳ��
		}
		else
		{
			csnake->NormalMove();//�������ƶ�
		}

		// ����߳Ե���ʱʳ��
		if (csnake->GetBigFood(*cfood)) //�Ե���ʱʳ��
		{
			csnake->Move();
			//����������ʱʳ�������ȷ��
			UpdateScore(cfood->GetProgressBar() / 5);
			RewriteScore();
		}

		//�����ʱ����ʱʳ���˸��
		if (cfood->GetBigFlag()) 
		{
			cfood->FlashBigFood();
		}

		//�����ߵ��ƶ�Ч��
		Sleep(speed);
	}
	/*������*/
	delete csnake;//�ͷŷ�����ڴ�ռ�
	delete cfood;
	int tmp = GameOver();//������Ϸ�������棬��������ѡ��
	switch (tmp)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 2;
	}
}


// ��Ϸ�˵�
int Controller::Menu()
{
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "Menu:";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "Continue";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "Restart";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "Exit";
	SetCursorPosition(0, 31);

	// ��ʼѡ��
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "Continue";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "Restart";

					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "Restart";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "Exit";

					--tmp_key;
					break;
				}
			}
			break;

		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "Restart";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "Continue";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "Exit";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "Restart";

					++tmp_key;
					break;
				}
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		SetCursorPosition(0, 31);
	}
	if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
	{
		SetCursorPosition(32, 19);
		std::cout << "      ";
		SetCursorPosition(34, 21);
		std::cout << "        ";
		SetCursorPosition(34, 23);
		std::cout << "        ";
		SetCursorPosition(34, 25);
		std::cout << "        ";
	}
	return tmp_key;
}


//���·���
void Controller::UpdateScore(const int& tmp)
{
	//���÷���������Ϸ�Ѷȼ����˵Ĳ���tmpȷ��
	score += key * 10 * tmp;
}


//�ػ����
void Controller::RewriteScore()
{
	/*Ϊ���ַ���β�����룬������������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������*/
	SetCursorPosition(37, 8);
	SetColor(11);
	int bit = 0;
	int tmp = score;
	while (tmp != 0)
	{
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i)
	{
		std::cout << " ";
	}
	std::cout << score;
}


// ��Ϸ����
int Controller::GameOver()//��Ϸ��������
{
	/*������Ϸ��������*/
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "����������������������������������������������������������������������������������������";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ��               Game Over !!!              ��";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ��                 YOU DIED                 ��";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ��             YOUR SCORES:                 ��";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ��              TRY AGAIN?                  ��";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ��        YES                 NO            ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "����������������������������������������������������������������������������������������";

	Sleep(100);
	SetCursorPosition(14, 18);
	SetBackColor();
	std::cout << "YES";
	SetCursorPosition(0, 31);

	/*ѡ�񲿷�*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://LEFT
			if (tmp_key > 1)
			{
				SetCursorPosition(14, 18);
				SetBackColor();
				std::cout << "YES";
				SetCursorPosition(24, 18);
				SetColor(11);
				std::cout << "NO";
				--tmp_key;
			}
			break;

		case 77://RIGHT
			if (tmp_key < 2)
			{
				SetCursorPosition(24, 18);
				SetBackColor();
				std::cout << "NO";
				SetCursorPosition(14, 18);
				SetColor(11);
				std::cout << "YES";
				++tmp_key;
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		SetCursorPosition(0, 31);
		if (flag) {
			break;
		}
	}

	SetColor(11);
	switch (tmp_key)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 1;
	}
}


// ��Ϸһ��ѭ��
void Controller::Game()//��Ϸһ��ѭ��
{
	Start();//��ʼ����
	while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������
	{
		Select();//ѡ�����
		DrawGame();//������Ϸ����
		int tmp = PlayGame();//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp
		if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) //����ֵΪ2ʱ�˳���Ϸ
		{
			break;
		}
		else
		{
			break;
		}
	}
}