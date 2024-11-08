#include "Math.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
namespace third_m_point {
	Point::Point() :x(0), y(0), z(0) {}
	Point::Point(float x, float y, float z) :x(x), y(y), z(z) {}
	void Point::Show() {
		cout << x << " " << y << " " << z << endl;
	}
	float* Point::Array() {
		return new float[3] {x, y, z};
	}
}
namespace second_m_point {
	Point::Point() :x(0), y(0) {}
	Point::Point(float x, float y) :x(x), y(y) {}
	void Point::Show() {
		cout << x << " " << y << endl;
	}
	float* Point::Array() {
		return new float[2] {x, y};
	}
}
namespace fraction {
	fraction::fraction() :numerator(0), denominator(0) {}
	fraction::fraction(int x, int y) :numerator(x), denominator(y) {}
	void fraction::Show() {
		cout << numerator << "/" << denominator <<" = " << fraction::result() << endl;
	}
	float fraction::result() {
		if (numerator == 0 && denominator == 0)
		{
			return 0;
		}
		else if (denominator == 0) {
			cout << "Error: denominator is null" << endl;
			while (denominator == 0)
				cin >> fraction::getsetDenom();
			return (float)numerator / denominator;
		}
		else {
			return (float)numerator/denominator;
		}
	}
	int& fraction::getsetDenom() {
		return denominator;
	}
	int* fraction::Array() {
		return new int[2] {numerator, denominator};
	}
}
namespace equation {
	LinearEquation::LinearEquation(double a,double b):a(a),b(b) {}
	void LinearEquation::findRoots() {
		if (a != 0) {
			double root = -b / a;
			cout << "Корінь цього рівняння: " << root << endl;
		}
		else {
			cout << "Коренів цього рівняння не існує." << endl;
		}
	}
	QuadraticEquation::QuadraticEquation(double a,double b,double c):a(a),b(b),c(c){}
	void QuadraticEquation::findRoots() {
		double discriminant = b * b - 4 * a * c;
		if (discriminant > 0) {
			double root1 = (-b + sqrt(discriminant)) / (2 * a);
			double root2 = (-b - sqrt(discriminant)) / (2 * a);
			cout << "Корені цього рівняння: " << root1 << " та " << root2 << endl;
		}
		else if (discriminant == 0) {
			double root = -b / (2 * a);
			cout << "Корінь цього рівняння: " << root << endl;
		}
		else {
			cout << "Дане рівняння не має коренів." << endl;
		}
	}
}