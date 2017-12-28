#include"PathTime.h"
class Path
{
private:
	int start_station;
	int end_station;
	double length;
	PathTime time;

public:
	Path(){}
	void setStart_station(int start_station)
	{
		this->start_station;
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
	void setTime(PathTime& time)
	{
		this->time = time;
	}
	PathTime& getTime()
	{
		return time;
	}
    PathTime& operator=(PathTime& pathtime) {
		PathTime a;
		a.setStart_time(pathtime.getStart_time());
		a.setEnd_time(pathtime.getEnd_time());
		a.setSum_time(pathtime.sum());
		return a;
	}
};
