#pragma once
#include<iostream>
#include<string>
using namespace std;
class PathTrain
{
private:
	string train_name;
	string start_time;
	string end_time;
	double sum_time;
public:
	PathTrain(){}
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
	void setTrain_name(string train_name) {
		this->train_name = train_name;
	}
	string getTrain_name() {
		return train_name;
	}
	double sum();
};
double PathTrain::sum() {
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

