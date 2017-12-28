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
};
double PathTime::sum() {
	int sum_hours, sum_minute;
	int hours_start = (start_time[0] - 48) * 10 + start_time[1] - 48;
	int minute_start = (start_time[3] - 48) * 10 + start_time[4] - 48;
	int hours_end = (end_time[0] - 48) * 10 + end_time[1] - 48;
	int minute_end = (end_time[3] - 48) * 10 + end_time[4] - 48;
	if (minute_end >= minute_start) {
		sum_minute = minute_end - minute_start;
		sum_hours = hours_end - hours_start;
	}
	else {
		sum_minute = minute_start - minute_end;
		sum_hours = hours_end - hours_start-1;
	}
	double sum = sum_hours + sum_minute / 60;
	return sum;
}
