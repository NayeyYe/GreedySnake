#pragma once
#ifndef  CONTROLLER_H
#define CONTROLLER_H


// 游戏全局控制
class Controller
{
public:
	// 绘制开始界面
	void Start();
	// 设置一个开始界面
	void Select();
	// 开始绘制游戏界面
	void DrawGame();
	// 游戏二级循环
	int PlayGame();
	// 游戏菜单
	int Menu();
	// 更新分数
	void UpdateScore(const int&);
	// 重绘分数
	void RewriteScore();
	// 游戏结束
	int GameOver();
	//	游戏一级循环
	void Game();
private:
	// 表示蛇的速度
	int speed;
	// 表示选中哪一个模式的代号
	int key;
	// 分数
	int score;
};
#endif // ! CONTROLLER_H
