#include<Windows.h>


#include "Map.h"


void Map::PrintInitmap()
{
	for (auto& point : initmap)
	{
		// ��ӡ������
		point.Print();
		Sleep(10);
	}
}