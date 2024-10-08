#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
#include"index.h"
#include"Human.h"
using namespace std;




int main() {
	srand(time(0));
	
	Queue<Human> list;

	Human h;
	for (size_t i = 0; i < 2; i++)
	{
		cin >> h;
		list.push(h);
	}
	
	list.Print();
}