#include<iostream>
#include<string>
using namespace std;
class PathTime
{
private:
	string start_time;
	string end_time;
	double sum_time;

public:
	PathTime(){}
	string getStart_time() {
		return start_time;
	}
	void setStart_time(string start_time) {
		this->start_time = start_time;
	}
	string getEnd_time() { 
		return end_time; 
	}
	void setEnd_time(string end_time) {
		this->end_time = end_time;
	}
	double getSum_time() {
		return sum_time;
	}
	void setSum_time(double sum_time) {
		this->sum_time = sum_time;
	}
	double sum();
	//PathTime& operator=(PathTime& pathtime);
};
double PathTime::sum() {
	double sum_hours, sum_minute;
	double hours_start = (start_time[0] - 48) * 10 + start_time[1] - 48;
	double minute_start = (start_time[3] - 48) * 10 + start_time[4] - 48;
	double hours_end = (end_time[0] - 48) * 10 + end_time[1] - 48;
	double minute_end = (end_time[3] - 48) * 10 + end_time[4] - 48;
	if (minute_end >= minute_start) {
		sum_minute = minute_end - minute_start;
		sum_hours = hours_end - hours_start;
	}
	else {
		sum_minute = minute_end - minute_start+60;
		sum_hours = hours_end - hours_start-1;
	}
	double sum = sum_hours + sum_minute / 60;
	return sum;
}
/*PathTime& PathTime::operator=(PathTime& pathtime) {
	setStart_time(pathtime.getStart_time());
	setEnd_time(pathtime.getEnd_time());
	setSum_time(pathtime.sum());
	return *this;
}*/
