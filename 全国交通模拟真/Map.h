#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<fstream>
#include <cstdlib>
#include<algorithm>
#include"SeqList.h"
#include"Station.h"
#include"Stack.h"
#include"VisitorMessage.h"
#include"Path.h"
#define MAXNUM 100
#define IPOSSIBLE_NUM 9999
class Map
{
private:
	Map() {};
	Map(int num);
	~Map();
	SeqList<Station> list;
	SeqList<Path> edges;
	SeqList<Visitor> visitors;
	double Edges[MAXNUM][MAXNUM];
	bool visited[MAXNUM];
	Stack<Station> stack;
	int ShortPath[MAXNUM][MAXNUM];
	double ShortPathnum[MAXNUM][MAXNUM];
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
	SeqList<Visitor> getList();
	bool isStation(Station st);//判断车站是否存在
	bool isEdges(Path pa);//判断路是否存在
	void addStation();
	void deleteStation(int i);
	void addPath();
	void deletePath(int start,int end);
	void addMessage();
	void Message_Show();
	void station_Show();
	void path_Show();
	void fromfileStation();
	void infileStation();
	void fromfilePath();
	void infilePath();
	void fromfileMessage();
	void infileMessage();
	void voluation_Length();//路程，权值,赋值
	void voluation_Time();//时间，权值
	void voluation_visited();
	void DFS(int start,int end);
	void  Short_Floyd();
	void show_ShortPath(string name1,string name2);
	void OptimumPath();//多个城市最优路径
	double weightSum(int weight[],int num);
	int toId(string name);//将名字转换为对应的城市id
	void toShowTrainLength(int id1,int id2);
	void DirecInsert(int *array, int size);//插排
//	void toShowTrainTime(int id);
	friend istream& operator>>(istream &is, Station &station);
	friend istream& operator>>(istream &is, Visitor &visitor);
	friend istream& operator>>(istream &is, PathTrain &pathnode);
};
Map* Map::getInstance() {
	if (map == NULL) {
		map = new Map(100);
	}
	map->fromfileStation();
	map->fromfilePath();
	map->fromfileMessage();
	map->voluation_visited();
	return map;
}
Map::~Map() {
	if (map != NULL) {
		delete map;
	}
}
Map::Map(int num)
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
	for (int i = 0; i < MAXNUM; i++) {
		for (int j = 0; j < MAXNUM; j++) {
			ShortPathnum[i][j] = 0;
		}
	}
	for (int i = 0; i < MAXNUM; i++) {
		for (int j = 0; j < MAXNUM; j++) {
			ShortPath[i][j] = 0;
		}
	}
}

bool Map::isStation(Station st)
{
	for (int i = 0; i < list.Size(); i++)
	{
      if (st.getName() == list[i].getName() || st.getId() == list[i].getId())
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
	cout << "请输入车站的站名，车站的序号,车站的介绍" << endl;
	cin >> st;
	if (isStation(st))
	{
		list.Insert(st, list.Size());
		cout << "增加成功！！" << endl;
		infileStation();
	}
	else {
		cout << "该车站已存在，增加失败!!!" << endl;
	}
}

void Map::deleteStation(int i)
{
	if (i<0 || i>list.Size()) {
		cout << "该车站不存在!!!" << endl;
	}
	else {
		list.Delete(i);
		cout << "删除成功！！" << endl;
		infileStation();
	}
	
}

void Map::addPath()
{
	Path path;
	cout << "请输入该路线的起点站名字，终点站名字，距离,火车数目" << endl;
	//cin >> pa;
	string start, end;
	int trainnum;
	double length;
	SeqList<PathTrain> pathtrain;
	PathTrain pathnode;
	cin >> start >> end >> length >> trainnum;
for (int i = 0; i < trainnum; i++) {
	cin >> pathnode;
	pathtrain.Insert(pathnode, pathtrain.Size());
}
 path.setStart_station(toId(start) + 1);
 path.setEnd_station(toId(end) + 1);
 path.setLength(length);
 path.setTrainNumber(trainnum);
 path.setTrain(pathtrain);
if (isEdges(path)) {
	edges.Insert(path, edges.Size());
	cout << "增加成功！！！" << endl;
	infilePath();
}
else {
	cout << "该路线已存在，增加失败!!!" << endl;
}
}

void Map::deletePath(int start, int end)
{
	int temp;
	for (int i = 0; i < edges.Size(); i++) {
		if (edges[i].getStart_station() == (start + 1) && edges[i].getEnd_station() == (end + 1)) {
			temp = i;
			break;
		}
	}
	if (!isEdges(edges.GetData(temp))) {
		edges.Delete(temp);
		cout << "删除成功！！！" << endl;
		infilePath();
	}
	else {
		cout << "该路线不存在！！" << endl;
	}
}

void Map::addMessage()
{
	Visitor visitor;
	cout << "请输入游客id，要留言的城市，游客的留言：";
	cin >> visitor;
	visitors.Insert(visitor, visitors.Size());
	infileMessage();
	cout << "增加成功！！！"<<endl;
}

istream& operator>>(istream &is, Station &station)
{
	string name, introduce;
	int id;
	is >> name >> id >> introduce;
	station.setId(id);
	station.setName(name);
	station.setIntroduce(introduce);
	return is;
}
istream& operator>>(istream &is, Visitor &visitor)
{
	string name, stationName, message;
	is >> name >> stationName >> message;
	visitor.setName(name);
	visitor.setStationName(stationName);
	visitor.setMessage(message);
	return is;
}

istream& operator>>(istream &is, PathTrain& pathnode) {
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
	cout << "城市名字" << " " << "城市代号" << " " << "城市介绍" << endl;
	for (int i = 0; i < list.Size(); i++) {
		cout << list[i].getName() << " " << list[i].getId() << " " << list[i].getIntroduce();
		cout << endl;
	}

}

void Map::path_Show() {
	fromfilePath();
	cout << "列车号  " << "出发站   " << "终点站  " << "出发时间  " << "到站时间   " << endl;
	for (int i = 0; i < edges.Size(); i++) {
		int start = edges[i].getStart_station();
		int end = edges[i].getEnd_station();
		for (int j = 0; j < edges[i].getTrainNumber(); j++) {
			cout << edges[i].getTrain()[j].getTrain_name() << "  " << list[start - 1].getName() << "  " << list[end - 1].getName() << "  ";
			cout << edges[i].getTrain()[j].getStart_time() << " " << edges[i].getTrain()[j].getEnd_time() << endl;
		}
	}
}
void Map::Message_Show()
{
	fromfileMessage();
	cout << "游客名  " << "城市   " << "留言  " << endl;
	for (int i = 0; i < visitors.Size(); i++)
	{
		cout << visitors[i].getName() << " " << visitors[i].getStationName() << " " << visitors[i].getMessage()<<endl;
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
		string name,introduce;
		int id;
		while (!ifile.eof()) {
			ifile >> name >>id>>introduce;
			temp.setId(id);
			temp.setName(name);
			temp.setIntroduce(introduce);
			list.Insert(temp, list.Size());
		}
		ifile.close();
	}
}

void  Map::infileStation() {
	fclose(fopen("Station.txt", "w"));
	fstream ifile;
	ifile.open("Station.txt");
	if (!ifile)  cout << "源文件丢失！" << endl;
	else {
	   int i = 0;
	   while (i<list.Size()) {
		   if (i == list.Size() - 1) {
			   ifile << list[i].getName() << " " << list[i].getId()<<" "<<list[i].getIntroduce();
			   break;
		   }
		   ifile << list[i].getName() << " " << list[i].getId() << " " << list[i].getIntroduce() << endl;
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
		PathTrain pathnode;
		int start, end,trainnum;
		double length;
		string start_time, end_time,train_name;
		while (!ofile.eof()) {
			ofile >> start >> end >> length >> trainnum;
			SeqList<PathTrain> seqlist;
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
			//seqlist.Cleardate();
		}
		ofile.close();
	}
}

void  Map::infilePath() {
	fclose(fopen("Path.txt", "w"));
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
				if (j == edges[i].getTrainNumber() - 1) {
					ofile << edges[i].getTrain()[j].getTrain_name() << " "
						<< edges[i].getTrain()[j].getStart_time() << " "
						<< edges[i].getTrain()[j].getEnd_time() << endl;
					break;
				}
				ofile << edges[i].getTrain()[j].getTrain_name() << " "
					<< edges[i].getTrain()[j].getStart_time() << " "
					<< edges[i].getTrain()[j].getEnd_time()<<" ";
			}
			i++;
		}
		ofile.close();
	}
}

void Map::fromfileMessage() {
	fstream ifile;
	ifile.open("Message.txt");
	if (!ifile)  cout << "源文件丢失！" << endl;
	else {
		if (ifile.eof())
			ifile.get();
		Visitor visitor;
		string name, stationName,message;
		while (!ifile.eof()) {
			ifile >> name >> stationName >> message;
			visitor.setName(name);
			visitor.setStationName(stationName);
			visitor.setMessage(message);
			visitors.Insert(visitor, visitors.Size());
		}
		}
		ifile.close();
}
void  Map::infileMessage() {
	fclose(fopen("Message.txt", "w"));
	fstream ifile;
	ifile.open("Message.txt");
	if (!ifile)  cout << "源文件丢失！" << endl;
	else {
		int i = 0;
		while (i<visitors.Size()) {
			if (i == visitors.Size() - 1) {
				ifile << visitors[i].getName() << " " << visitors[i].getStationName() << " " << visitors[i].getMessage();
				break;
			}
			ifile << visitors[i].getName() << " " << visitors[i].getStationName() << " " << visitors[i].getMessage() << endl;
			i++;
		}
		ifile.close();
	}
}
void Map::voluation_Length() {
	for (int i = 0; i < edges.Size(); i++) {
		Edges[edges[i].getStart_station()-1][edges[i].getEnd_station()-1] = edges[i].getLength();
	}
}

void Map::voluation_Time() {
	for (int i = 0; i < edges.Size(); i++) {
		double sumtime=edges[i].getTrain()[0].getSum_time();
		for (int j = 0; j < edges[i].getTrainNumber(); j++) {
			if (edges[i].getTrain()[j].getSum_time() < sumtime) {
				sumtime = edges[i].getTrain()[j].getSum_time();
			}
		}
		Edges[edges[i].getStart_station()][edges[i].getEnd_station()] = sumtime;
	}

}

void Map::voluation_visited() {
	for (int i = 0; i < list.Size(); i++) {
		visited[i] = false;
	}
}

int Map::toId(string name) {
	for (int i = 0; i < list.Size(); i++) {
		if (list[i].getName() == name) {
			return i;
		}
	}
	return -1;
}
void Map::toShowTrainLength(int id1,int id2) {
	for (int i = 0; i < list.Size(); i++) {
		if (list[i].getId() == (id1 + 1)) {
			cout << list[i].getName() << "-->";
		}
	}
	for (int i = 0; i < list.Size(); i++) {
		if (list[i].getId() == (id2+1)) {
			cout << list[i].getName() << " ";
		}
	}
	for (int i = 0; i < edges.Size(); i++) {
		if (edges[i].getStart_station() == (id1 + 1) && edges[i].getEnd_station() == (id2 + 1)) {
			cout << edges[i].getTrain()[0].getTrain_name() << " " << edges[i].getLength()<<"km"<<endl;
		}
	}
	
}

SeqList<Visitor> Map::getList()
{
	return visitors;
}



void Map::DFS(int start,int end)//深搜入栈查询所有路径
{
	visited[start] = true;
	stack.Push(list[start]);
	for (int j = 0; j < list.Size(); j++) {
		if (start== end) {
			cout << "path:" << endl;
			for (int i=0; i < stack.Size()-1; i++) {
				toShowTrainLength(stack[i].getId() - 1, stack[i + 1].getId() - 1);
			}
			stack.Pop();
			visited[start] = false;
			break;
		}
		if ((Edges[start][j] > 0 && Edges[start][j]<100) && !visited[j]) {
			DFS(j,end);
		}
		if (j == list.Size() - 1 ) {
		    stack.Pop();
			visited[start] = false;
		}
	}
}

void Map::Short_Floyd()
{
	for (int i = 0; i < list.Size(); i++){
		for (int j = 0; j < list.Size(); j++){
			ShortPathnum[i][j] = Edges[i][j];
			ShortPath[i][j] = j;
		}
	}
	for (int i = 0; i < list.Size(); ++i){
		for (int j = 0; j < list.Size(); ++j){
			for (int k = 0; k < list.Size(); ++k){
				if(ShortPathnum[j][k] > (ShortPathnum[j][i] + ShortPathnum[i][k])) {
					ShortPathnum[j][k] = ShortPathnum[j][i] + ShortPathnum[i][k];
					ShortPath[j][k] = ShortPath[j][i];
				}
			}
		}
	}
}
void Map::show_ShortPath(string name1,string name2) {//找完需重新赋值
	        int i = toId(name1);
			int j = toId(name2);
			cout << name1<< "-->" << name2 << " 用时/距离为：" << ShortPathnum[i][j]<<endl;
			int k = ShortPath[i][j];
			cout << "path:" <<endl;
			while (k!= j) {
				toShowTrainLength(i, k);
				i = k;
				k = ShortPath[k][j];
			}
			toShowTrainLength(i,j);
}

void Map::OptimumPath() {
	voluation_Length();
	int length[20];
	string name[20];
	cout << "请输入几个城市：";
	int number;
	cin >> number;
	cout << "请输入你要到达的城市：";
	for (int i = 0; i < number; i++) {
		cin >> name[i];
	}
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < list.Size(); j++) {
			if (name[i] == list[j].getName()) {
				length[i] = list[j].getId();
			}
		}
	}
	DirecInsert(length, number);
	int count = 0;
	int i = 0;
	double minWeight = weightSum(length, number);
	while (next_permutation(length, length + number)) {
		i++;
		if (minWeight > weightSum(length, number)) {
			minWeight = weightSum(length, number);
			count = i;
		}
	}
    i = 0;
	if (count == 0) {
		for (int i = 0; i < number - 1; i++) {
			toShowTrainLength(length[i] - 1, length[i + 1] - 1);
		}
	}
	else {
		while (next_permutation(length, length + number)) {
			i++;
			if (i == count) {
				cout << "Path:" << endl;
				for (int i = 0; i < number - 1; i++) {
					toShowTrainLength(length[i] - 1, length[i + 1] - 1);
				}
			}
		}
	}
	
}

double Map::weightSum(int weight[],int num) {
	double sum=0;
	for (int i = 0; i < num-1; i++) {
		sum += Edges[weight[i]-1][weight[i+1]-1];
	}
	return sum;
}

void Map::DirecInsert(int *array, int size)
{
	int i, j;
	if (!array) return;
	for ( i = 1; i<size; i++)
	{
		int temp = array[i];
		for (j = i - 1; j >= 0 && array[j]>temp; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}