#pragma once
namespace third_m_point {
	class Point {
		float x, y, z;
	public:
		Point();
		Point(float x, float y, float z);
		void Show();
		float* Array();
	};
}
namespace second_m_point {
	class Point {
		float x, y;
	public:
		Point();
		Point(float x, float y);
		void Show();
		float* Array();
	};
}
namespace fraction {
	class fraction {
		int numerator, denominator;
	public:
		fraction();
		fraction(int x, int y);
		void Show();
		int& getsetDenom();
		float result();
		int* Array();

	};
}
namespace equation {
	class Equation {
	public:
		virtual void findRoots() = 0;
	};
	class LinearEquation : public Equation {
	private:
		double a, b;
	public:
		LinearEquation(double a, double b);
		void findRoots();
		
	};
	class QuadraticEquation : public Equation {
	private:
		double a, b, c;
	public:
		QuadraticEquation(double a, double b, double c);
		void findRoots();
		
	};
}

