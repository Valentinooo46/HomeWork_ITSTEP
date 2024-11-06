#pragma once
using namespace std;
#include"Time.h"
#include"Producer.h"
#include<Windows.h>
class Commodity
{
protected:
	unsigned long ID;  //рівносильно штрих-коду
	string Name;
	string Type;  //група товарів
	int Price;  //ціна
	Time implementation_time;  //дата до якої треба реалізувати
	int deadline;
	Producer producer;

public:
	Commodity(unsigned long ID, string Name, string Type, float Price, Time _implementation_time, Producer temp_producer) :ID(ID), Name(Name), Type(Type), Price(Price), implementation_time(_implementation_time), producer(temp_producer) {
		time_t rawtime;
		time(&rawtime);
		tm* timeinfo;
		timeinfo = localtime(&rawtime);
		Time temp(timeinfo);
		deadline = temp - implementation_time;
	}
	bool operator==(Commodity temp) {
		return (ID == temp.ID && Type == temp.Type && implementation_time == temp.implementation_time) ? true : false;
	}
	unsigned long GetID() {
		return ID;
	}
	string GetType() {
		return Type;
	}
	string GetName() {
		return Name;
	}
	int Getdeadline() {
		return deadline;
	}
	int GetPrice() {
		return Price;
	}
	Time GetImplementation_Time() {
		return implementation_time;
	}
	void Update() {
		time_t rawtime;
		time(&rawtime);
		tm* timeinfo;
		timeinfo = localtime(&rawtime);
		Time temp(timeinfo);
		deadline = temp - implementation_time;
	}
	const Producer GetProducer() {
		return producer;
	}

};

