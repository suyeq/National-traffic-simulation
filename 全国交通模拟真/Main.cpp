#include<iostream>
#include"Map.h"
using namespace std;
int main()
{
	Map map(100);
	for (int i = 0; i < 3; i++) {
		map.addStation();
	}
	map.station_Show();

	for (int i = 0; i < 3; i++) {
		map.addPath();
	}
	map.path_Show();
	system("pause");
	return 0;
}