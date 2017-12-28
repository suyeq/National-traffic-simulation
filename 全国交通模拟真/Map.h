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
	Map(int num );
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
	void station_Show();
	void path_Show();
	friend istream& operator>>(istream &is, Station &station);
	friend istream& operator>>(istream &is, Path &path);
};
Map::Map(int num )
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
		if (st.getName()== list[i].getName()||st.getId()==list[i].getId())
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
		if (pa.getStart_station()== edges[i].getStart_station() && pa.getEnd_station() == edges[i].getEnd_station())
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
		cout<< "该车站已存在，增加失败!!!" << endl;
	}
}

void Map::deleteStation(int i)
{
	list.Delete(i);
}

void Map::addPath()
{
	Path pa;
	cout << "请输入该路线的起点站，终点站，距离，起始时间，到站时间" << endl;
	cin >> pa;
	if (isEdges(pa)){
		edges.Insert(pa,edges.Size());
	}
	else {
		cout << "该路线已存在，增加失败!!!" << endl;
	}
}

void Map::deletePath(int start, int end)
{
	int temp;
	for(int i = 0; i < edges.Size(); i++) {
		if (edges[i].getStart_station()==start && edges[i].getEnd_station()==end) {
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
	 double length;
	 string start_time, end_time;
	 PathTime pathtime;
	 is >> start >> end >> length >> start_time>>end_time;
	 pathtime.setStart_time(start_time);
	 pathtime.setStart_time(end_time);
	 cout << "123";
	 system("pause");
	 pathtime.setSum_time(pathtime.sum());
	 cout << "234";
	 system("pause");
	 path.setStart_station(start);
	 path.setEnd_station(end);
	 path.setLength(length);
	 path.setTime(pathtime);
	 return is;
}

void Map::station_Show() {
	for (int i = 0; i < list.Size(); i++) {
		cout << list[i].getId() << " ";
	}
}

void Map::path_Show() {
	for (int i = 0; i < edges.Size(); i++) {
		cout << edges[i].getTime().getSum_time() << " ";
	}
}