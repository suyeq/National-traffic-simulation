#pragma once
#include"Map.h"
Map* Map::map = NULL;
void mainLoop();
void Menu();
bool Enter();
void mainLoop()
{

	/*Map *map = Map::getInstance();
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
	//(*map).infilePath();
	//(*map).infilePath();
	//(*map).path_Show();
	system("pause");*/
	Menu();
	cout<<Enter();
	system("pause");
}

void Menu()//菜单
{
	cout << " —————————————————————" << endl;
	cout << "             全国交通咨询模拟系统" << endl;
	cout << "              1、城市信息查询" << endl;
	cout << "              2、两城市的路径查询" << endl;
	cout << "              3、多城市访问路径查询" << endl;
	cout << "              4、多城市访问最优路径查询" << endl;
	cout << "              5、游客留言栏" << endl;
	cout << "              6、管理员登入" << endl;
	cout << "              0、退出系统" << endl;
	cout << " —————————————————————" << endl;
}

bool Enter()//登入
{
	cout << "请输入用户名：" << endl;
	string name;
	cin >> name;
	cout << "请输入密码：" << endl;
	string password;
	cin >> password;
	if (name == "邓林海"&&password == "123") {
		cout << "登入成功" << endl;
		return true;
	}
	cout << "登入失败！！！" << endl;
	return false;
}