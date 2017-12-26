#include"SeqList.h"
#include"Station.h"
#define MAXNUM 100
#define IPOSSIBLE_NUM 999999
class Map
{
private:
	SeqList<Station> List;
	double Edges[MAXNUM][MAXNUM];
	int numEdges;

public:
	Map(int num = MAXNUM);
	~Map(){}
	int getNumVertexes()
	{
		return List.Size();
	}
	int getNumEdges()
	{
		return numEdges;
	}
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
			Edges[i][j] = IPOSSIBLE_NUM;
		}
	}
}

