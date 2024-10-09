#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.141592
#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
#include<math.h>
#include"automobile.h"
using namespace std;




class circle {
protected:
	float radius;
	int x_center;
	int y_center;
public:
	circle() :radius(0), x_center(0), y_center(0) {};
	circle(float radius, int x, int y) :radius(radius), x_center(x), y_center(y) {};
	double Square() {
		return (M_PI * pow(radius, 2));
	}
};
class square {
protected:
	float size;
	int x, y;
public:
	square() :size(0), x(0), y(0) {}
	square(float size, int x, int y) :size(size), x(x), y(y) {}
	double Square() {
		return pow(size, 2);
	}
};
class circle_in_square :public circle, public square {
public:
	circle_in_square() :square(), circle() {}
	circle_in_square(float radius, int x_center, int y_center, float size, int x, int y) :square(size, x, y), circle(radius, x_center, y_center) {}
	bool IsCorrect() {
		return ((radius == size / 2) && (x_center == radius + x && y_center == y + radius)) ? (true) : (false);
	}
	void ReInit(float radius, int x_center, int y_center, float size, int x, int y) {
		this->radius = radius;
		this->x_center = x_center;
		this->y_center = y_center;
		this->size = size;
		this->x = x;
		this->y = y;
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*circle_in_square cq1(10, 5, 5, 20, -5, -4);
	float radius, size;
	int x, y, x_c, y_c;
	do
	{
		if (cq1.IsCorrect())
		{
			cout << "correct!" << endl;
		}
		else {
			cout << "incorrect!" << endl;
			cin >> radius >> x_c >> y_c >> size >> x >> y;
			cq1.ReInit(radius, x_c, y_c, size, x, y);
		}
	} while (!cq1.IsCorrect());
	cout << "correct!" << endl;*/

	automobile a1(10.5, 2, "white", 8, 100, 16, "white", "Hatch-back", 1200, 260, 25.4);
	a1.print();

}