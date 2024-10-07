#include<Windows.h>


#include "Map.h"


void Map::PrintInitmap()
{
	for (auto& point : initmap)
	{
		// 打印正方形
		point.Print();
		Sleep(10);
	}
}