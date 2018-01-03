#pragma once
#include"Map.h"
Map* Map::map = NULL;
void mainLoop();
void Menu();
bool Enter();
void Manage(Map *map);
void DeleteStation(Map *map);
void DeletePath(Map *map);
void Message_control(Map *map);
void mainLoop()
{
	
	Map *map = Map::getInstance();
	while (true)
	{
		Menu();
		int choice;
		cout << "请输入你的选择:";
		cin >> choice;
		switch (choice)
		{
		case 1:map->station_Show(); break;
		case 2:(*map).station_Show(); break;
		case 3:(*map).station_Show(); break;
		case 4:(*map).station_Show(); break;
		case 5:Message_control(map); break;
		case 6:Manage(map); break;
		case 0:exit(0);
		}
	}
}

void Menu()//菜单
{
	cout << " —————————————————————" << endl;
	cout << "             全国交通咨询模拟系统" << endl;
	cout << "              1、城市信息查询" << endl;
	cout << "              2、两城市的路径查询" << endl;
	cout << "              3、两城市所有访问路径查询" << endl;
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

void Manage(Map *map)//管理员操作
{
	if (Enter()) {
		cout << " —————————————————————" << endl;
		cout << "             全国交通咨询管理员操作" << endl;
		cout << "              1、增加城市" << endl;
		cout << "              2、删除城市" << endl;
		cout << "              3、增加路线" << endl;
		cout << "              4、删除路线" << endl;
		cout << "              5、增加交通工具" << endl;
	//	cout << "              6、增加留言" << endl;
		cout << "              0、退出系统" << endl;
		cout << " —————————————————————" << endl;
		int choice;
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice) {
		case 1:map->addStation(); break;
		case 2:DeleteStation(map); break;
		case 3:map->addPath(); break;
		case 4:DeletePath(map); break;
		case 5:break;
	//	case 6:(*map).addMessage();
		case 0:break;
		default:break;
		}
	}
}
void DeleteStation(Map *map) {
	cout << "请输入要删除的城市名字:";
	string choice;
	cin >> choice;
	map->deleteStation(map->toId(choice));
}
void DeletePath(Map *map) {
	cout << "请输入该路线链接的两座城市名字:";
	string name1, name2;
	cin >> name1 >> name2;
	map->deletePath(map->toId(name1), map->toId(name2));
}
void Message_control(Map *map) {
	cout << "1.查看留言栏 " << "2.留言" << endl;
	cout << "请选择以上操作:";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:map->Message_Show(); break;
	case 2:map->addMessage(); break;
	}
}