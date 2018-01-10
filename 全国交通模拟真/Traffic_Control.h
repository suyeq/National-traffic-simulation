#pragma once
#include<Windows.h>
#include"Map.h"
Map* Map::map = NULL;
void mainLoop();
void Menu();
bool Enter();
void Manage(Map *map);
//void DeleteStation(Map *map);
void DeletePath(Map *map);
void Message_control(Map *map);
void Path_short(Map *map);
void SerchStationMessage(Map *map);
void SerchStation(Map *map);
void mainLoop()
{
	
	Map *map = Map::getInstance();
	map->fromfileMessage();
	map->fromfilePath();
	map->fromfileStation();
	while (true)
	{
		Menu();
		int choice;
		cout << "请输入你的选择:";
		cin >> choice;
		switch (choice)
		{
		case 1:SerchStationMessage(map); break;
		case 2:Path_short(map); break;
		case 3:map->OptimumPath(); break;
		case 4:Message_control(map); break;
		case 5:Manage(map); break;
		case 6:map->path_Show(); break;
		case 0:exit(0);
		}
		cin.get();
		getchar();
		system("cls");
	}
	
}

void Menu()//菜单
{
	cout << " —————————————————————" << endl;
	cout << "             全国交通咨询模拟系统" << endl;
	cout << "              1、城市信息查询" << endl;
	cout << "              2、两城市的路径查询" << endl;
	cout << "              3、多城市访问最优路径查询" << endl;
	cout << "              4、游客留言栏" << endl;
	cout << "              5、管理员登入" << endl;
	cout << "              6、列车时刻表" << endl;
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
		//cout << "              2、删除城市" << endl;
		cout << "              2、增加路线" << endl;
		cout << "              3、删除路线" << endl;
		//cout << "              5、增加交通工具" << endl;
	   //	cout << "              6、增加留言" << endl;
		cout << "              0、退出系统" << endl;
		cout << " —————————————————————" << endl;
		int choice;
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice) {
		case 1:map->addStation(); break;
		//case 2:DeleteStation(map); break;
		case 2:map->addPath(); break;
		case 3:DeletePath(map); break;
		//case 5:break;
	//	case 6:(*map).addMessage();
		case 0:break;
		default:break;
		}
	}
}
/*void DeleteStation(Map *map) {
	cout << "请输入要删除的城市名字:";
	string choice;
	cin >> choice;
	map->deleteStation(map->toId(choice));
}*/
void DeletePath(Map *map) {
	cout << "请输入该路线链接的两座城市名字:";
	string name1, name2;
	cin >> name1 >> name2;
	map->deletePath(map->toId(name1), map->toId(name2));
}
void Message_control(Map *map) {
	cout << "1.查看留言栏      " << "2.留言" << endl;
	cout << "请选择以上操作:";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:map->Message_Show(); break;
	case 2:map->addMessage(); break;
	}
}
void Path_short(Map *map) {
	cout << "请做出选择:1.两城市最短路径查询   2.两城市所有路径查询"<<endl;
	int choice;
	cin >>choice ;
	cout << "请输入要查询的两座城市：";
	string name1, name2;
	cin >> name1 >> name2;
	int temp=0;
	switch (choice) {
	case 1: {
		cout << "请选择哪种属性:1.最短路径    2.最短时间" << endl;
		int chose;
		cin >> chose;
		if (chose == 2) {
			map->voluation_Time();
			map->Short_Floyd();
			map->show_ShowTime(name1, name2);
		}
		else {
			map->voluation_Length();
			map->Short_Floyd();
			map->show_ShortPath(name1, name2);
		}
	    }break;
	case 2:
		  map->voluation_Length();
		  map->DFS(map->toId(name1), map->toId(name2),temp);
		  if (temp == 0) {
			  cout << "不存在这样的路线！！！" << endl;
		  }
		  break;
	}
	
}
void SerchStationMessage(Map *map)
{
	cout << "请选择操作:1.全部查询     2.单独查询"<<endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:map->station_Show(); break;
	case 2:SerchStation(map); break;
	}
}

void SerchStation(Map *map)
{
	cout << "请输入城市名字:";
	string name;
	cin >> name;
	if (map->isStation(name)) {
		cout << "城市名字" << "    " << "城市代号" << "    " << "城市介绍" << endl;
		for (int i = 0; i < map->getList().Size(); i++) {
			if (map->getList()[i].getName() == name) {
				cout << map->getList()[i].getName() << "         " << map->getList()[i].getId() << "         "
					<< map->getList()[i].getIntroduce() << endl;
				break;
			}
		}
	}
	else {
		cout << "该城市不存在！！！" << endl;
	}
	
}