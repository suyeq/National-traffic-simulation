#include<iostream>
#include"SeqList.h"
#include"Station.h"
#include"Path.h"
#define MAXNUM 100
#define IPOSSIBLE_NUM -1
class Map
{
private:
	SeqList<Station> list;
	double Edges[MAXNUM][MAXNUM];
	SeqList<Path> edges;
	//int numEdges;

public:
	Map(int num = MAXNUM);
	~Map() {}
	int getNumVertexes()
	{
		return list.Size();
	}
	int getNumEdges()
	{
		return edges.Size();
	}
	bool isStation(Station st);//判断车站是否存在
	bool isEdges(Path pa);//判断路是否存在
	void addStation();
	void deleteStation(int i);
	void addPath();
	void deletePath(int start,int end);
	friend istream& operator>>(istream &is, Station &station);
	friend istream& operator>>(istream &is, Path &path);
};
Map::Map(int num = MAXNUM)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i == j)
			{
				Edges[i][j] = 0;
			}
			else {
				Edges[i][j] = IPOSSIBLE_NUM;
			}
		}
	}
}

bool Map::isStation(Station st)
{
	for (int i = 0; i < list.Size(); i++)
	{
		if (st.getName == list[i].getName||st.getId==list[i].getId)
		{
			return false;
		}
	}
	return true;
}

bool Map::isEdges(Path pa)
{
	
	for (int i = 0; i < edges.Size(); i++)
	{
		if (pa.getStart_station== edges[i].getStart_station&&pa.getEnd_station == edges[i].getEnd_station)
		{
			return false;
		}
	}
	return true;
}

void Map::addStation()
{
	Station st;
	cout << "请输入车站的站名，车站的序号" << endl;
	cin >> st;
	if (isStation(st))
	{
		list.Insert(st, list.Size());
	}
	else {
		cout<< "该车站已存在，增加失败" << endl;
	}
}

void Map::deleteStation(int i)
{
	list.Delete(i);
}

void Map::addPath()
{
	Path pa;
	cout << "请输入该路线的起点站，终点站，该路线上的路途与时间" << endl;
	cin >> pa;
	if (isEdges(pa)){
		edges.Insert(pa,edges.Size());
	}
	else {
		cout << "该路线已存在，增加失败" << endl;
	}
}

void Map::deletePath(int start, int end)
{
	int temp;
	for(int i = 0; i < edges.Size(); i++) {
		if (edges[i].getStart_station&&edges[i].getEnd_station) {
			temp = i;
			break;
		}
	}
	if (isEdges(edges.GetData(temp))) {
		edges.Delete(temp);
	}
	else {
		cout << "该路线不存在！！" << endl;
	}
}
 istream& operator>>(istream &is, Station &station)
{
	 string name;
	 int id;
	 is >> name >> id;
	 station.setId(id);
	 station.setName(name);
	 return is;
}

istream& operator>>(istream& is, Path &path)
{
	 int start, end;
	 double length, time;
	 is >> start >> end >> length >> time;
	 path.setStart_station(start);
	 path.setEnd_station(end);
	 path.setLength(length);
	 path.setTime(time);
	 return is;
}