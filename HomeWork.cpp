#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include <vector>
#include <algorithm>
#include<fstream>
using namespace std;







// Базовий клас «Домашня тварина»
class Pet {
protected:
	string name;
	string type;
	float weight, max_speed;
public:
	Pet(string name, string type, float weight, float max_speed) : name(name), type(type), weight(weight), max_speed(max_speed) {}
	virtual void Sound() {
		cout << "Hello!" << endl;
	}
	virtual void Show() {
		cout << "Name:" << name << endl;
	};
	virtual void Type() {
		cout << "type:" << type << endl;
	};

};

class Dog : public Pet {
public:
	Dog(string name, string type, float weight, float max_speed) : Pet(name, type, weight, max_speed) {}
	void Sound() override {
		cout << "Woof!" << endl;
	}
	void Type() override {
		cout << "Dog type:" << type << endl;
	}
	void Show() override {
		cout << "Dog Name:" << name << endl;
	}
};

class Cat : public Pet {
public:
	Cat(string name, string type, float weight, float max_speed) : Pet(name, type, weight, max_speed) {}
	void Sound() override {
		cout << "Meow!" << endl;
	}
	void Type()override {
		cout << "Cat type:" << type << endl;
	}
	void Show() override {
		cout << "Cat Name:" << name << endl;
	}
};


class Parrot : public Pet {
public:
	Parrot(string name, string type, float weight, float max_speed) : Pet(name, type, weight, max_speed) {}
	void Sound() override {
		cout << "Arrr!" << endl;
	}
	void Type() override {
		cout << "Parrot type: " << type << endl;
	}
	void Show() override {
		cout << "Parrot Name:" << name << endl;
	}
};

class Hamster : public Pet {
public:
	Hamster(string name, string type, float weight, float max_speed) : Pet(name, type, weight, max_speed) {}
	void Sound() override {
		cout << "Squeak!" << endl;
	}
	void Type() override {
		cout << "hamster type:" << type << endl;
	}
	void Show() override {
		cout << "Hamster Name:" << name << endl;
	}
};

int main() {
	Pet* arr[5] = { new Pet("Alfa","snake",10,60),new Dog("Beta","British Spaniel",45,40),new Cat("Dzeta","British metys",20,50),new Parrot("Omega","wawe blue",5,70),new Hamster("Epsilon","Ukranian wild",7,55) };
	for (int i = 0; i < 5; i++)
	{
		cout << "---------------" << endl;
		arr[i]->Show();
		arr[i]->Sound();
		arr[i]->Type();
		cout << "---------------" << endl;
		delete arr[i];
	}


	return 0;
}
