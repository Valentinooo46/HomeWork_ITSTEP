#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
using namespace std;
struct Birthday {
	int day;
	int month;
	int year;
	void fill()
	{
		printf("Введіть день місяць та рік народження:");
		cin >> day >> month >> year;
	}
	void read() {
		printf("%i.%i.%i\n", day, month, year);
	}
};
struct FullName {
	char FirstName[100];
	char SurName[100];
	char SecondName[100];
	void fill() {
		printf("Введіть Ім'я Прізвище По-Батькові:");
		cin >> FirstName >> SurName >> SecondName;
	}
	void read() {
		printf("%s %s %s\n", FirstName,SurName,SecondName);
	}
};
class Student
{
private:
	FullName PIB;
	char fax[50];
	char city[50];
	char country[75];
	char group[3];
	Birthday birth;

public:
	void fillinfo() {
		PIB.fill();
		birth.fill();
		cin >> fax >> city >> country >> group;

	}
	void readinfo() {
		PIB.read();
		birth.read();
		printf("Телефон-%s\nАдреса проживання-%s\nКраїна-%s\nГрупа-%s\n", fax, city, country, group);
	}
	
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Student no1;
	no1.fillinfo();
	no1.readinfo();
	

	
}