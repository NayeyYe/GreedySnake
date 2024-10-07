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

// 设置开始界面
void Controller::Start()
{
	// 设置窗口大小函数
	SetWindowSize(41, 32);
	// 设置开始动画颜色
	SetColor(2);
	// 开始动画
	// 分配一个start动态实例用于开启Action方法
	StartInterface* start = new StartInterface();
	start->Action();
	// 删除start，释放内存
	delete start;

	// 设置光标的位置，并且输出提示语，等待任意键输出结束
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start ...";
	SetCursorPosition(13, 27);
	system("pause");
}


// 设置一下游戏选择界面
void Controller::Select()
{
	// 初始化界面选项
	SetColor(3);
	// 来点空隙
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	// 开始选择游戏难度
	SetCursorPosition(6, 21);
	std::cout << "Choose Game Difficulty：";
	SetCursorPosition(6, 22);
	std::cout << "Select with up and down keys";
	SetCursorPosition(6, 23);
	std::cout << "Enter to confirm";
	SetCursorPosition(27, 22);
	// 用一下tools.h中的SetBackColor函数设置一下背景颜色
	// 颜色表示你正在选中哪一个选项
	SetBackColor();
	// 开始选择模式难度
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


	// 设置上下键选择模块
	// ch表示按键是键盘中的上下按键
	// 即72：UP键，80：DOWN按键
	int ch;
	// 记录选中的选项，初始选择是第一个
	key = 1;
	// 记录是否按了Enter按键，初始默认为false
	bool flag = false;
	// 当按下UP和DOWN时，录入按键，判断按键
	while ((ch = _getch()))
	{
		// 检测录入的按键
		switch (ch)
		{
		// 如果输入的UP按键
		case 72 :
			// 如果此时选中的时第一项
			// 那么UP方向键时没有作用的
			if (key > 1)
			{
				// 检测现在是哪一个选项
				switch (key)
				{
				// 如果现在指向的是普通模式
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
		// 如果此时按下的是DOWN方向键
		case 80:
			// 如果此时已经选到了炼狱模式
			// 就不能再往下选择了
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
		
		// 如果按下的是Enter回车键
		case 13:
			flag = true;
			break;

		// 如果按下的是无效按键
		default:
			break;

		}

		// 输入Enter确定，退出选项界面
		if (flag)
			break;

		// 将光标移动到左下角中，防止光标影响游戏体验
		SetCursorPosition(0, 31);
	}

	// 按下Enter之后，要检测此刻选择的模式
	// 即判断key的值
	switch (key)
	{
	case 1:
		// 设置蛇的速度为135
		speed = 135;
		break;
	case 2:
		// 设置蛇的速度为135
		speed = 100;
		break;
	case 3:
		// 设置蛇的速度为135
		speed = 60;
		break;
	case 4:
		// 设置蛇的速度为135
		speed = 30;
		break;
	default:
		break;
	}
}


// 绘制游戏界面
void Controller::DrawGame()
{
	// 清屏
	system("cls");
	// 绘制地图
	SetColor(3);
	Map* init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	//绘制侧边栏
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(31, 4);
	std::cout << "Difficulty:";
	SetCursorPosition(36, 5);
	// 判断一下现在是什么难度
	//即看看k的值
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
	// 显示得分
	SetCursorPosition(31, 7);
	std::cout << "Scores:";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << "Press the directional keys to move";
	SetCursorPosition(33, 15);
	std::cout << "Press ESC to pause";
}


// 游戏二级循环
int Controller::PlayGame()
{
	// 初始化蛇和食物
	Snake* csnake = new Snake();
	Food* cfood = new Food();
	SetColor(6);
	// 初始化csnake元素
	csnake->InitSnake();
	// 设置随机数种子，让食物出现在随机位置
	srand((unsigned)time(NULL));
	cfood->DrawFood(*csnake);
	
	// 游戏循环
	// 判断是否超出界面，撞到自己
	while (csnake->OverEdge() && csnake->HitItSelf())
	{
		// 调出选择菜单
		// 如果按下Esc按键
		if (!csnake->ChangeDirection())
		{
			int tmp = Menu();
			switch (tmp)
			{
			// 继续游戏
			case 1:
				break;

			// 重新开始
			case 2:
				delete csnake;
				delete cfood;
				// 将1作为PlayGame函数返回值
				return 1;

			case 3://退出游戏
				delete csnake;
				delete cfood;
				//将2作为PlayGame函数的返回值返回到Game函数中
				// 表示退出游戏
				return 2;
			default:
				break;
			}
		}

		// 如果蛇吃到了食物，那么蛇增长
		if (csnake->GetFood(*cfood)) //吃到食物
		{
			csnake->Move();//蛇增长
			UpdateScore(1);//更新分数，1为分数权重
			RewriteScore();//重新绘制分数
			cfood->DrawFood(*csnake);//绘制新食物
		}
		else
		{
			csnake->NormalMove();//蛇正常移动
		}

		// 如果蛇吃到限时食物
		if (csnake->GetBigFood(*cfood)) //吃到限时食物
		{
			csnake->Move();
			//分数根据限时食物进度条确定
			UpdateScore(cfood->GetProgressBar() / 5);
			RewriteScore();
		}

		//如果此时有限时食物，闪烁它
		if (cfood->GetBigFlag()) 
		{
			cfood->FlashBigFood();
		}

		//制造蛇的移动效果
		Sleep(speed);
	}
	/*蛇死亡*/
	delete csnake;//释放分配的内存空间
	delete cfood;
	int tmp = GameOver();//绘制游戏结束界面，并返回所选项
	switch (tmp)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 2;
	}
}


// 游戏菜单
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

	// 开始选择
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
	if (tmp_key == 1) //选择继续游戏，则将菜单擦除
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


//更新分数
void Controller::UpdateScore(const int& tmp)
{
	//所得分数根据游戏难度及传人的参数tmp确定
	score += key * 10 * tmp;
}


//重绘分数
void Controller::RewriteScore()
{
	/*为保持分数尾部对齐，将最大分数设置为6位，计算当前分数位数，将剩余位数用空格补全，再输出分数*/
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


// 游戏结束
int Controller::GameOver()//游戏结束界面
{
	/*绘制游戏结束界面*/
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ┃               Game Over !!!              ┃";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ┃                 YOU DIED                 ┃";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ┃             YOUR SCORES:                 ┃";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ┃              TRY AGAIN?                  ┃";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ┃        YES                 NO            ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	SetCursorPosition(14, 18);
	SetBackColor();
	std::cout << "YES";
	SetCursorPosition(0, 31);

	/*选择部分*/
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
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 1;
	}
}


// 游戏一级循环
void Controller::Game()//游戏一级循环
{
	Start();//开始界面
	while (true)//游戏可视为一个死循环，直到退出游戏时循环结束
	{
		Select();//选择界面
		DrawGame();//绘制游戏界面
		int tmp = PlayGame();//开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp
		if (tmp == 1) //返回值为1时重新开始游戏
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) //返回值为2时退出游戏
		{
			break;
		}
		else
		{
			break;
		}
	}
}