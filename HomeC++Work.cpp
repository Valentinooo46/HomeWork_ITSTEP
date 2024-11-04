#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include <vector>
#include <algorithm>
#include<fstream>
#include <cmath>
using namespace std;




class Equation {
public:
	virtual void findRoots() = 0;
};


class LinearEquation : public Equation {
private:
	double a, b;
public:
	LinearEquation(double a, double b) : a(a), b(b) {}
	void findRoots() override {
		if (a != 0) {
			double root = -b / a;
			std::cout << "Корінь лінійного рівняння: " << root << std::endl;
		}
		else {
			std::cout << "Це не є лінійним рівнянням." << std::endl;
		}
	}
};


class QuadraticEquation : public Equation {
private:
	double a, b, c;
public:
	QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}
	void findRoots() override {
		double discriminant = b * b - 4 * a * c;
		if (discriminant > 0) {
			double root1 = (-b + sqrt(discriminant)) / (2 * a);
			double root2 = (-b - sqrt(discriminant)) / (2 * a);
			std::cout << "Корені квадратного рівняння: " << root1 << " та " << root2 << std::endl;
		}
		else if (discriminant == 0) {
			double root = -b / (2 * a);
			std::cout << "Корінь квадратного рівняння: " << root << std::endl;
		}
		else {
			std::cout << "Рівняння не має дійсних коренів." << std::endl;
		}
	}
};
class Figure {
public:
	virtual void Show() = 0;
	virtual void Save(ofstream& ofs) = 0;
	virtual void Load(ifstream& ifs) = 0;
	virtual ~Figure() {};
};
class Circle : public Figure {
	float x, y, radius;
public:
	Circle(float x, float y, float radius) :x(x), y(y), radius(radius) {}
	void Show() override {
		cout << "Circle(" << x << "," << y << "," << radius << ")" << endl;
	}
	void Save(ofstream& ofs) override {
		ofs << "Circle " << x << " " << y << " " << radius<<endl;
	}
	void Load(ifstream& ifs) override {
		ifs >> x >> y >> radius;
	}
};
class ellipse : public Figure {
	float x, y, a, b;
public:
	ellipse(float x, float y, float a, float b) :x(x), y(y), a(a), b(b) {}
	void Show() override {
		cout << "Ellipse(" << x << "," << y << "," << a << "," << b << ")" << endl;
	}
	void Save(ofstream& ofs) override {
		ofs << "Ellipse " << x << " " << y << " " << a << " " << b << endl;
	}
	void Load(ifstream& ifs) override {
		ifs >> x >> y >> a >> b;
	}
};
class rectangle : public Figure {
	int x, y; int width, height;
public:
	rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
	void Show() override {
		cout << "Rectangle(" << x << "," << y << "," << width << "," << height << ")" << endl;
	}
	void Save(ofstream& ofs) override {
		ofs << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
	}
	void Load(ifstream& ifs) override {
		ifs >> x >> y >> width >> height;
	}
};
class Square : public Figure {
	int x, y, side;
public:
	Square(int x, int y, int side) : x(x), y(y), side(side) {}
	void Show() override
	{
		cout << "Square(" << x << "," << y << "," << side << ")" << endl;
	}
	void Save(ofstream& ofs) override
	{
		ofs << "Square " << x << " " << y << " " << side << endl;
	}
	void Load(ifstream& ifs) override
	{
		ifs >> x >> y >> side;
	}
};
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	LinearEquation le(2, -4);
	le.findRoots();

	QuadraticEquation qe(1, -3, 2);
	qe.findRoots();
	vector<Figure*> vec;
	vec.push_back(new rectangle(4, 4, 5, 8));
	vec.push_back(new Circle(10, 10, 50));
	vec.push_back(new ellipse(6, 8, 7, 9));
	vec.push_back(new Square(12, 15, 8));
	ofstream ofs("figures.txt");
	for (Figure* shape : vec) { 
		shape->Save(ofs); 
	} 
	ofs.close(); 
	for (Figure* shape : vec) 
	{ 
		delete shape; 
	} 
	vec.clear(); 
	ifstream ifs("figures.txt");
	string type; 
	while (ifs >> type) 
	{ 
		Figure* figure = nullptr; 
		if (type == "Square") 
		{ 
			figure = new Square(0,0,0); 
		} 
		else if (type == "Rectangle") 
		{ 
			figure = new rectangle(0,0,0,0); 
		} 
		else if (type == "Circle") 
		{ 
			figure = new Circle(0,0,0); 
		} 
		else if (type == "Ellipse") 
		{ 
			figure = new ellipse(0,0,0,0); 
		} 
		if (figure) 
		{ 
			figure->Load(ifs); 
			vec.push_back(figure); 
		} 
	} 
	ifs.close(); 
	for (Figure* figure : vec) {
		figure->Show(); 
		delete figure;
	}

	return 0;
}
