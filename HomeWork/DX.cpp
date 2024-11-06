#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include <vector>
#include <algorithm>
#include<fstream>
#include <cmath>
#include"Shop.h"
using namespace std;





int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Shop shop;
	shop.Add(Commodity(1234,"Сметана\"Молокія\"", "Молочні продукти", 100, Time(29, 2, 2020), Producer("ValikPro", "Netherlands", "Gaaz")));
	shop.Add(Commodity(1234, "Сметана\"Молокія\"", "Молочні продукти", 100, Time(28, 2, 2020), Producer("ValikPro", "Netherlands", "Gaaz")));
	shop.Add(Commodity(1234, "Сметана\"Молокія\"", "Молочні продукти", 100, Time(29, 2, 2020), Producer("ValikPro", "Netherlands", "Gaaz")));
	unsigned long ID;
	string Name, Type, Prod_name, City_Name, Country_Name,Cashier;
	int day, month, year,price;
	
	bool exit = false;
	int select,count;
	cin >> Cashier;
	cout << "1-Add,2-Sale,3-Update,4-SeeWriteOff,5-exit" << endl;
	do
	{
		cin >> select;
		if (select == 1)
		{


			cin >> ID >> Name >> Type >> price >> day >> month >> year >> Prod_name >> City_Name >> Country_Name;
			Time time(day, month, year);
			Commodity goods(ID, Name, Type, price, Time(day, month, year), Producer(Prod_name, Country_Name, City_Name));
			shop.Add(goods);
			
		}
		else if (select == 2) {
			cin >> ID >> count;
			shop.Sale(ID, count, Cashier);
			
		}
		else if (select == 3) {

			shop.Update();
		}
		else if (select == 4) {
			shop.List_WriteOff();
		}
		else {
			exit = true;
		}
		
	} while (!exit);
	cout << "До побачення!" << endl;
	return 0;
}
