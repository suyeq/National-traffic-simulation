#pragma once
#include<iostream>
#include<string>
using namespace std;
class Station
{
private:
string name;
int id;

public:
	Station(){}
	Station(string name,int id):name(name),id(id){}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}
	void setId(int id)
	{
		this->id = id;
	}
	int getId()
	{
		return id;
	}

};
