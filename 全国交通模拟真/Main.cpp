#include<iostream>
#include"Map.h"
using namespace std;
Map* Map::map = NULL;
int main()
{
	Map *map=Map::getInstance();
	(*map).station_Show();
	system("pause");
	(*map).path_Show();
	//system("pause");
	//(*map).fromfilePath();
	//(*map).path_Show();
	//(*map).station_Show();
	//cout << endl;
	//(*map).addStation();
	//map.fromfileStation();
	//(*map).station_Show();
	//for (int i = 0; i < 3; i++) {
	//map.addPath();
	(*map).addPath();
	//}
	(*map).infilePath();
	//(*map).infilePath();
	//(*map).path_Show();
	system("pause");
	return 0;
}