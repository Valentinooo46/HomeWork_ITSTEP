#pragma once
#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;
class Human
{
	string PIB;
	string fax;
public:
	Human():PIB(""),fax("") {}
	friend istream& operator>>(istream& input, Human& h) {
		input >> h.PIB >> h.fax;
		return input;
	}
	friend ostream& operator<<(ostream& output, Human& h) {
		output << "--------------------\n" << h.PIB << endl<<h.fax<<endl<<"--------------------\n";
		return output;
	}
};

