#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include"Math.h"
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	third_m_point::Point p(1, 1, 1);
	p.Show();
	float* p_ptr = p.Array();
	cout << p_ptr[0] << " " << p_ptr[1] << " " << p_ptr[2] << endl;
	delete[] p_ptr;
	second_m_point::Point p2(2, 3);
	p2.Show();
	p_ptr = p2.Array();
	cout << p_ptr[0] << " " << p_ptr[1] << endl;
	delete[] p_ptr;
	fraction::fraction f(10, 4);
	int* f_ptr = f.Array();
	cout << f_ptr[0]<<" " << f_ptr[1] << endl;
	delete[] f_ptr;
	f.Show();
	cout << f.result() << endl;
	f.getsetDenom() = 3;
	f.Show();
	cout << f.result() << endl;
	equation::LinearEquation LE(15, 46);
	LE.findRoots();
	equation::QuadraticEquation QE(15, 46, -256);
	QE.findRoots();


	return 0;

}