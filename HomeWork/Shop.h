#pragma once
#include"Commodity.h"
using namespace std;
class Shop
{
protected:
	vector<Commodity>shelves;
	vector<Commodity>write_off;
	void rearrange() {
		for (vector<Commodity>::iterator i = shelves.begin(); i != shelves.end();)
		{
			if (i->Getdeadline() == -1)
			{
				write_off.push_back(*i);
				i = shelves.erase(i);
			}
			else {
				i++;
			}
		}
	}
public:
	Shop() {};
	void Add(Commodity temp) {
		/*if (temp.Getdeadline() == -1)
		{
			write_off.push_back(temp);
		}
		else {
			shelves.push_back(temp);
		}*/
		shelves.push_back(temp);
	}
	void Update() {
		vector<Commodity> checked_commodity;
		for (Commodity& i : shelves)
		{
			i.Update();
			if (i.Getdeadline() == -1)
			{


				if (Find(i, checked_commodity) == 0)
				{
					checked_commodity.push_back(i);
					cout << "на полицях є товари в кількості " << Find(i, shelves) << "x з простроченим терміном реалізації/\nОсновні дані про товар:ID:" << i.GetID() << "\nНайменування:" << i.GetName() << "\nГрупа товару:" << i.GetType() << "\nВиробник:" << i.GetProducer().Name << " " << i.GetProducer().Country << endl;

				}
			}




		}
		rearrange();
		cout << "Прострочені товари було списано" << endl;
	}
	size_t Find(Commodity temp, const vector<Commodity>& vec) {
		if (vec.empty())
		{
			return 0;
		}
		else {
			size_t count = 0;
			for (Commodity i : vec)
			{
				if (i == temp)
				{
					count++;
				}
			}
			return count;
		}
	}
	void List_WriteOff() {
		vector<Commodity> checked_commodity;
		for (Commodity& i : write_off)
		{
			if (Find(i, checked_commodity) == 0)
			{
				checked_commodity.push_back(i);
				cout << "========================" << endl;
				cout << Find(i, write_off) << "x" << endl;
				cout << "ID:" << i.GetID() << " Name:" << i.GetName() << " Type:" << i.GetType() << " Deadline:" << i.GetImplementation_Time().day << "." << i.GetImplementation_Time().month << "." << i.GetImplementation_Time().year << endl;

			}
		}
	}
	void Sale(unsigned long ID, size_t count, string Cashier) {
		int county = 0;
		for (Commodity& i : shelves) {
			if (i.GetID() == ID)
			{
				county++;
			}
		}

		if (county >= count)
		{
			county = 0;
			int suma = 0;
			time_t rawtime;
			time(&rawtime);
			tm* timeinfo;
			timeinfo = localtime(&rawtime);
			ofstream ofs("sales.txt");
			ofs << "==========" << timeinfo->tm_mday << "." << timeinfo->tm_mon + 1 << "." << timeinfo->tm_year << "==========" << endl;
			for (vector<Commodity>::iterator i = shelves.begin(); i != shelves.end();) {
				if (county == count)
				{
					break;
				}
				if (i->GetID() == ID)
				{
					ofs << i->GetID() << " " << i->GetName() << " " << i->GetPrice() << " " << i->GetImplementation_Time().day << "." << i->GetImplementation_Time().month << "." << i->GetImplementation_Time().year << endl;
					suma += i->GetPrice();
					i = shelves.erase(i);
					county++;
				}
				else {
					i++;
				}
			}
			cout << "продано!" << endl;
			ofs << "Сума продажу:" << suma << " Касир:" << Cashier << endl;
			ofs << "================================" << endl;


		}
		else {
			if (county == 0)
			{
				cout << "таких товарів немає в наявності" << endl;
			}
			else {
				cout << "Заданої кількості немає в наявності" << endl;
			}
		}
	}


};

