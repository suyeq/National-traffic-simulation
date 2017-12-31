#include<iostream>
#include<fstream>
#include"SeqList.h"
#include"Station.h"
#include"Path.h"
#define MAXNUM 100
#define IPOSSIBLE_NUM -1
class Map
{
private:
	Map() {};
	Map(int num);
	~Map();
	SeqList<Station> list;
	double Edges[MAXNUM][MAXNUM];
	SeqList<Path> edges;
	static Map *map;

public:
	int getNumVertexes()
	{
		return list.Size();
	}
	int getNumEdges()
	{
		return edges.Size();
	}
	static Map* getInstance();
	bool isStation(Station st);//判断车站是否存在
	bool isEdges(Path pa);//判断路是否存在
	void addStation();
	void deleteStation(int i);
	void addPath();
	void deletePath(int start,int end);
	void station_Show();
	void path_Show();
	void fromfileStation();
	void infileStation();
	void fromfilePath();
	void infilePath();
	void voluation_Length();//路程，权值,赋值
	void voluation_Time();//时间，权值
	friend istream& operator>>(istream &is, Station &station);
	friend istream& operator>>(istream &is, Path &path);
	friend istream& operator>>(istream &is, PathNode &pathnode);
};
Map* Map::getInstance() {
	if (map == NULL) {
		map = new Map(100);
	}
	return map;
}
Map::~Map() {
	if (map != NULL) {
		delete map;
	}
}
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
      if (st.getName() == list[i].getName() || st.getId() == list[i].getId())
      {
		  cout << "wer";
	    return false;
       }
	}
	return true;
}

bool Map::isEdges(Path pa)
{
	for (int i = 0; i < edges.Size(); i++)
	{
		if (pa.getStart_station() == edges[i].getStart_station() && pa.getEnd_station() == edges[i].getEnd_station())
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
		//infileStation();
	}
	else {
		cout << "该车站已存在，增加失败!!!" << endl;
	}
}

void Map::deleteStation(int i)
{
	if (i<0 || i>list.Size() - 1) {
		cout << "该车站不存在!!!" << endl;
	}
	else {
		list.Delete(i);
		infilePath();
	}
	infileStation();
}

void Map::addPath()
{
	Path pa;
	cout << "请输入该路线的起点站，终点站，距离,火车数目" << endl;
	cin >> pa;
	if (isEdges(pa)) {
	edges.Insert(pa, edges.Size());
		//infilePath();
	}
	else {
		cout << "该路线已存在，增加失败!!!" << endl;
	}
}

void Map::deletePath(int start, int end)
{
	int temp;
	for (int i = 0; i < edges.Size(); i++) {
		if (edges[i].getStart_station() == start && edges[i].getEnd_station() == end) {
			temp = i;
			break;
		}
	}
	if (isEdges(edges.GetData(temp))) {
		edges.Delete(temp);
		//infilePath();
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
istream& operator>>(istream &is, Path &path)
{
	int start, end, trainnum;
	double length;
	SeqList<PathNode> pathtrain;
	PathNode pathnode;
	is >> start >> end >> length >> trainnum;
	for (int i = 0; i < trainnum; i++) {
		cin >> pathnode;
		pathtrain.Insert(pathnode, pathtrain.Size());
	}
	path.setStart_station(start);
	path.setEnd_station(end);
	path.setLength(length);
	path.setTrainNumber(trainnum);
	path.setTrain(pathtrain);
	return is;
}

istream& operator>>(istream &is, PathNode& pathnode) {
	string start_time, end_time, trainname;
	cout << "请输入火车名，起始时间，到站时间" << endl;
	is >> trainname >> start_time >> end_time;
	pathnode.setStart_time(start_time);
	pathnode.setEnd_time(end_time);
	pathnode.setTrain_name(trainname);
	return is;
}

void Map::station_Show() {
	fromfileStation();
	for (int i = 0; i < list.Size(); i++) {
		cout << list[i].getId() << " ";
	}
}

void Map::path_Show() {
	fromfilePath();
	for (int i = 0; i < edges.Size(); i++) {
		for (int j = 0; j < edges[i].getTrainNumber(); j++) {
			cout << edges[i].getTrain()[j].getStart_time() << " ";
		}
		
	}
}

void Map::fromfileStation() {
	fstream ifile;
	ifile.open("Station.txt");
	if (!ifile)  cout << "源文件丢失！" << endl;
	else {
		if (ifile.eof())
			ifile.get();
		Station temp;
		string name;
		int id;
		while (!ifile.eof()) {
			ifile >> name >>id;
			temp.setId(id);
			temp.setName(name);
			list.Insert(temp, list.Size());
		}
		ifile.close();
	}
}

void  Map::infileStation() {
	fstream ifile;
	ifile.open("Station.txt");
	if (!ifile)  cout << "源文件丢失！" << endl;
	else {
	   int i = 0;
	   while (i<list.Size()) {
		   if (i == list.Size() - 1) {
			   ifile << list[i].getName() << " " << list[i].getId();
			   break;
		   }
		   ifile << list[i].getName() << " " << list[i].getId() << endl;
		   i++;
		}
		ifile.close();
	}
}

void Map::fromfilePath() {
	fstream ofile;
	ofile.open("Path.txt");
	if (!ofile)  cout << "源文件丢失！" << endl;
	else {
		if (ofile.eof())
			ofile.get();
		Path path;
		PathNode pathnode;
		SeqList<PathNode> seqlist;
		int start, end,trainnum;
		double length;
		string start_time, end_time,train_name;
		while (!ofile.eof()) {
			ofile >> start >> end >> length >> trainnum;
			for (int i = 0; i < trainnum; i++) {
				ofile >> train_name >> start_time >> end_time;
				pathnode.setStart_time(start_time);
				pathnode.setEnd_time(end_time);
				pathnode.setTrain_name(train_name);
				pathnode.setSum_time(pathnode.sum());
				seqlist.Insert(pathnode, seqlist.Size());
			}
			path.setStart_station(start);
			path.setEnd_station(end);
			path.setLength(length);
			path.setTrainNumber(trainnum);
			path.setTrain(seqlist);
			edges.Insert(path, edges.Size());
		}
		ofile.close();
	}
}

void  Map::infilePath() {
	fstream ofile;
	ofile.open("Path.txt");
	if (!ofile)  cout << "源文件丢失！" << endl;
	else {
		int i = 0;
		while (i<edges.Size()) {
			if (i == edges.Size() - 1) {
				ofile << edges[i].getStart_station() << " " << edges[i].getEnd_station()<<" "
					<<edges[i].getLength()<<" "<<edges[i].getTrainNumber()<<" ";
				for (int j= 0; j < edges[i].getTrainNumber(); j++) {
					ofile << edges[i].getTrain()[j].getTrain_name() << " "
						<< edges[i].getTrain()[j].getStart_time() << " "
						<< edges[i].getTrain()[j].getEnd_time();
				}
				break;
			}
			ofile << edges[i].getStart_station() << " " << edges[i].getEnd_station() << " "
				<< edges[i].getLength() << " " << edges[i].getTrainNumber() << " ";
			for (int j = 0; j < edges[i].getTrainNumber(); j++) {
				ofile << edges[i].getTrain()[j].getTrain_name() << " "
					<< edges[i].getTrain()[j].getStart_time() << " "
					<< edges[i].getTrain()[j].getEnd_time() << endl;
			}
			i++;
		}
		ofile.close();
	}
}

void Map::voluation_Length() {
	//for (int i = 0; i < edges.Size(); i++) {
	//	Edges[edges[i].getStart_station()][edges[i].getEnd_station()] = edges[i].getLength();
	//}
}

void Map::voluation_Time() {
	//for (int i = 0; i < edges.Size(); i++) {
	//	Edges[edges[i].getStart_station()][edges[i].getEnd_station()] = edges[i].getTime().getSum_time();
	//}
}