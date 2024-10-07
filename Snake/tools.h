#pragma once
#ifndef TOOLS_H
#define TOOLS_H

// 设置窗口大小
// cols表示列长，lines表示行长
void SetWindowSize(int cols, int lines);
// 设置开始界面的文本颜色
void SetColor(int colorID);
// 将光标移动到(x,y)位置
void SetCursorPosition(const int x, const int y);
// 设置文本背景颜色
void SetBackColor();
#endif // !TOOLS_H
