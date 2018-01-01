#include"PathNode.h"
class Path
{
private:
	int start_station;
	int end_station;
	double length;
	int trainNumber;
	SeqList<PathNode> pathnode;
public:
	Path() {}
	void setStart_station(int start_station)
	{
		this->start_station = start_station;
	}
	int getStart_station()
	{
		return start_station;
	}
	void setEnd_station(int end_station)
	{
		this->end_station = end_station;
	}
	int getEnd_station()
	{
		return end_station;
	}
	void setLength(double length)
	{
		this->length = length;
	}
	double getLength()
	{
		return length;
	}
	void setTrain(SeqList<PathNode> &node)
	{
		pathnode = node;
	}
	SeqList<PathNode>& getTrain()
	{
		return pathnode;
	}
	void setTrainNumber(int number) {
		trainNumber = number;
	}
	int getTrainNumber() {
		return trainNumber;
	}
	/*Path& operator=(Path &path) {
		start_station = path.getStart_station();
		end_station = path.getEnd_station();
		length = path.getLength();
		trainNumber = path.getTrainNumber();
		pathnode = path.getTrain();
		return *this;
	}*/
};
