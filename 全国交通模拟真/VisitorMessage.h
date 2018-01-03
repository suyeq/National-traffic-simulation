#pragma once
#include"SeqList.h"
#include<iostream>
using namespace std;
class Visitor
{
private:
	string name;
	string station_name;
	string message;
public:
	Visitor() {};
	Visitor(string name,string station_name,string message){
		this->name = name;
		this->station_name = station_name;
		this->message = message;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setStationName(string station_name) {
		this->station_name = station_name;
	}
	string getStationName() {
		return station_name;
	}
	void setMessage(string message) {
		this->message = message;
	}
	string getMessage() {
		return message;
	}
};