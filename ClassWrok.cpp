#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
using namespace std;
#define count_of_apartment 2





class Human {

	char PIB[100];
	char* fax = new char[50];
public:
	Human() {
		strcpy(PIB, "");
		strcpy(fax, "");
	}
	~Human() {
		delete[] fax;
	}
	Human(Human& object) {
		strcpy(PIB, object.PIB);
		strcpy(fax, object.fax);
	}
	void InitHuman(const char  _PIB[],const char _fax[]) {
		strcpy(PIB, _PIB);
		strcpy(fax, _fax);
		
	}
	void operator =(Human& object) {
		strcpy(PIB, object.PIB);
		strcpy(fax, object.fax);
	}
	void SeeHuman() {
		cout << PIB << " " << fax << endl;
	}
};
class apartment {
	Human* list;
	int number,count_of_room,length;
	double square;

public:
	apartment() {
		list = nullptr;
		length = 0;
		number = 0;
		count_of_room = 0;
		
		square = 0.0;
	}
	~apartment() {
		if (list != nullptr)
		{
			delete[] list;
		}
		
	}
	/*void InitApartment() {
		list = new Human[1];
		this->length++;
		char PIB[100];
		char fax[50];
		
		cin >> this->number >> this->count_of_room >> this->square;
		cin.ignore();
		cin.getline(PIB, 100);
		
		cin.getline(fax, 50);
		list[0].InitHuman(PIB, fax);


	}*/
	void InitApartmentOwner() {
		if (list == nullptr)
		{
			list = new Human[1];
			this->length++;
		}
		cin.ignore();
		char PIB[100];
		char fax[50];
		cin.getline(PIB, 100);
		cin.getline(fax, 50);
		list[0].InitHuman(PIB, fax);
	}
	void DeleteOwner() {
		if (list == nullptr)
		{
			cout << "Не існує власника будинку!" << endl;
		}
		else {
			list[0].InitHuman(" ", " ");
		}
	}
	void InitApartment_WithoutOwner() {
		cin >> this->number >> this->count_of_room >> this->square;
	}
	void AddHuman() {
		Human* new_list = new Human[length + 1];
		for (int i = 0; i < length; i++)
		{
			new_list[i] = list[i];
		}
		cin.ignore();
		char PIB[100];
		char fax[50];
		
		cin.getline(PIB, 100);
		
		cin.getline(fax, 50);
		new_list[length].InitHuman(PIB, fax);
		delete[] list;
		list = new_list;
		length++;
	}
	void SeeInfo() {
		cout << "--------------------------" << endl;
		for (int i = 0; i < length; i++)
		{
			list[i].SeeHuman();
		}
		cout << number << " " << square << " " << count_of_room << endl <<"----------------------------------------" << endl;
	}
	int GetNumber() {
		return number;
	}

};
class Build {
	apartment list[count_of_apartment];
	char name[50];
public:
	Build() {
		strcpy(name, "");
	}
	void InitBuild() {
		cin.getline(name, 50);
		for (int i = 0; i < count_of_apartment; i++)
		{
			list[i].InitApartment_WithoutOwner();
		}
	}
	void SetOwnerApartment() {
		int y;
		cin >> y;
		for (int i = 0; i < count_of_apartment; i++)
		{
			if (list[i].GetNumber() == y)
			{
				list[i].InitApartmentOwner();
				break;
			}
		}

	}
	void AddHumantoApartment() {
		int y;
		cin >> y;
		for (int i = 0; i < count_of_apartment; i++)
		{
			if (list[i].GetNumber() == y)
			{
				list[i].AddHuman();
				break;
			}
		}

	}
	void SeeBuild() {
		for (int i = 0; i < count_of_apartment; i++)
		{
			list[i].SeeInfo();
		}
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Build b1;
	b1.InitBuild();
	b1.SetOwnerApartment();
	b1.SeeBuild();

	

	
}