class Path
{
private:
	int start_station;
	int end_station;
	double length;
	double time;

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
	int getLength()
	{
		return length;
	}
	void setTime(double time)
	{
		this->time = time;
	}
	int getTime()
	{
		return time;
	}

};
