#include<iostream>
#include"Map.h"
using namespace std;
int main()
{
	Map map(100);
	map.fromfilePath();
	map.path_Show();
	//map.fromfileStation();
	//map.station_Show();
	//cout << endl;
	//map.addStation();
	//map.fromfileStation();
	//map.station_Show();
	//for (int i = 0; i < 3; i++) {
	map.addPath();
	//}
	map.infilePath();
	//map.path_Show();
	system("pause");
	return 0;
}