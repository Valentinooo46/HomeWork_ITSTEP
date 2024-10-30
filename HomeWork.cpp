#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include <vector>
#include <algorithm>
#include<fstream>
using namespace std;




struct Noda
{
	string word, translate;
	Noda* left, * right, * parent;
	int count;
};

class Tree
{
	Noda* root;
	Noda* Min(Noda* y)
	{
		if (y != 0)
			while (y->left != NULL)
			{
				y = y->left;
			}
		return y;
	}

	Noda* Max(Noda* y)
	{
		if (y != 0)
			while (y->right != NULL)
			{
				y = y->right;
			}
		return y;
	}
	void TreeToVector(Noda* y, vector<Noda*>& nodes) {
		if (y != NULL) {
			TreeToVector(y->left, nodes);
			nodes.push_back(y);
			TreeToVector(y->right, nodes);
		}
		return;
	}

public:
	Tree()
	{
		root = NULL;
	}

	void Add(string word, string translate)
	{
		if (root == NULL) {
			root = new Noda;
			root->left = NULL;
			root->parent = NULL;
			root->right = NULL;
			root->word = word;
			root->translate = translate;
			root->count = 0;
		}
		else
		{
			Noda* temp = NULL;
			Noda* y = root;

			while (y != NULL)
			{
				temp = y;
				if (y->word > word)
					y = y->left;
				else
					y = y->right;
			}
			Noda* temp1 = new Noda;
			temp1->word = word;
			temp1->translate = translate;
			temp1->left = NULL;
			temp1->right = NULL;
			temp1->count = 0;

			if (temp->word > word)
				temp->left = temp1;
			else
				temp->right = temp1;
			temp1->parent = temp;
		}
	}


	Noda* GetRoot()
	{
		return root;
	}
	void Print(Noda* y)
	{
		if (y != NULL)
		{
			Print(y->left);
			cout << y->word << "-" << y->translate << endl;
			Print(y->right);
		}
	}


	Noda* Search(Noda* y, string word)
	{

		while (y != 0 && word != y->word)
		{
			if (word < y->word)
				y = y->left;
			else
				y = y->right;
		}
		return y;
	}


	Noda* Next(Noda* y)
	{
		Noda* temp = 0;
		if (y != 0)
		{

			if (y->right != 0)
				return Min(y->right);

			temp = y->parent;

			while (temp != 0 && y == temp->right)
			{
				y = temp;
				temp = temp->parent;
			}
		}
		return temp;
	}



	Noda* Previous(Noda* y)
	{
		Noda* temp = 0;
		if (y != 0)
		{

			if (y->left != 0)
				return Max(y->left);

			temp = y->parent;

			while (temp != 0 && y == temp->left)
			{
				y = temp;
				temp = temp->parent;
			}
		}
		return temp;
	}


	void Del(Noda* z = NULL)
	{

		if (z != 0)
		{
			Noda* temp, * y;

			if (z->left == 0 || z->right == 0)
				y = z;
			else
				y = Next(z);
			if (y->left != 0)
				temp = y->left;
			else
				temp = y->right;
			if (temp != 0)
				temp->parent = y->parent;

			if (y->parent == 0)
				root = temp;
			else if (y == y->parent->left)
				y->parent->left = temp;
			else
				y->parent->right = temp;

			if (y != z)
			{

				z->word = y->word;

			}
			delete y;
		}
		else
			while (root != 0)
				Del(root);
	}
	void Translate(string word) {
		Noda* node = Search(root, word);
		if (node) {
			node->count++;
			cout << "Translation: " << node->translate << " (Count: " << node->count << ")" << endl;

		}
		else { cout << "Word not found." << endl; }
	}
	void Update(string word, string new_translation) {
		Noda* node = Search(root, word);
		if (node)
		{
			node->translate = new_translation;
			cout << "Translation updated." << endl;
		}
		else {
			cout << "Word not found." << endl;
		}
	}
	void PrintTop3() {
		vector<Noda*> nodes;
		TreeToVector(root, nodes);
		sort(nodes.begin(), nodes.end(), [](Noda* a, Noda* b) { return a->count > b->count; });
		for (int i = 0; i < 3 && i < nodes.size(); i++)
		{
			cout << nodes[i]->word << " (Count: " << nodes[i]->count << ")" << endl;
		}
	}
	void PrintAntiTop3() {
		vector<Noda*> nodes; TreeToVector(root, nodes);
		sort(nodes.begin(), nodes.end(), [](Noda* a, Noda* b) { return a->count < b->count; });
		for (int i = 0; i < 3 && i < nodes.size(); i++)
		{
			cout << nodes[i]->word << " (Count: " << nodes[i]->count << ")" << endl;
		}
	}

	~Tree()
	{
		Del();
	}
};
struct Bus_place {
	unsigned long number_bus;
	string driver_name;
	string driver_surname;
	string route;
	size_t count_places;
	Bus_place* left, * right, * parent;
	Bus_place() :number_bus(0), driver_name(""), driver_surname(""), route(""), count_places(0), left(nullptr), right(nullptr), parent(nullptr) {}

};
class Bus_Station {
	Bus_place* root;
	void TreeToVector(Bus_place* y, vector<Bus_place*>& vec) {
		if (y != nullptr)
		{
			TreeToVector(y->left, vec);
			vec.push_back(y);
			TreeToVector(y->right, vec);
		}

		return;
	}
	Bus_place* Next(Bus_place* y)
	{
		Bus_place* temp = 0;
		if (y != 0)
		{

			if (y->right != 0)
				return Min(y->right);

			temp = y->parent;

			while (temp != 0 && y == temp->right)
			{
				y = temp;
				temp = temp->parent;
			}
		}
		return temp;
	}
	Bus_place* Min(Bus_place* y)
	{
		if (y != 0)
			while (y->left != NULL)
			{
				y = y->left;
			}
		return y;
	}
public:
	Bus_Station() :root(nullptr) {}
	void Add(unsigned long number_bus, string driver_name, string driver_surname, string route, size_t count_places) {
		if (root == nullptr)
		{
			root = new Bus_place;
			root->number_bus = number_bus;
			root->driver_name = driver_name;
			root->driver_surname = driver_surname;
			root->route = route;
			root->count_places = count_places;
			root->left = nullptr;
			root->right = nullptr;
			root->parent = nullptr;
		}
		else {
			if (!NB_Search(GetRoot(), number_bus))
			{


				Bus_place* temp = nullptr, * y;
				y = root;
				while (y != nullptr) {
					if (y->number_bus > number_bus)
					{
						temp = y;
						y = y->left;
					}
					else {
						temp = y;
						y = y->right;
					}
				}
				if (temp->number_bus > number_bus)
				{
					temp->left = new Bus_place;
					temp->left->parent = temp;
					temp->left->number_bus = number_bus;
					temp->left->driver_name = driver_name;
					temp->left->driver_surname = driver_surname;
					temp->left->count_places = count_places;
					temp->left->route = route;
					temp->left->left = nullptr;
					temp->left->right = nullptr;
				}
				else {
					temp->right = new Bus_place;
					temp->right->parent = temp;
					temp->right->number_bus = number_bus;
					temp->right->driver_name = driver_name;
					temp->right->driver_surname = driver_surname;
					temp->right->count_places = count_places;
					temp->right->route = route;
					temp->right->left = nullptr;
					temp->right->right = nullptr;
				}
			}
			else {
				cout << "Already have this bus!" << endl;
				return;
			}
		}
	}
	Bus_place* NB_Search(Bus_place* y, unsigned long number_bus)
	{

		while (y != nullptr && number_bus != y->number_bus)
		{
			if (number_bus < y->number_bus)
				y = y->left;
			else
				y = y->right;
		}
		return y;
	}
	Bus_place* GetRoot() {
		return root;
	}
	void route_Search(string route) {
		vector<Bus_place*> vec;
		TreeToVector(GetRoot(), vec);
		if (vec.empty())
		{
			cout << "Станція порожня...." << endl;
			return;
		}
		else {
			int count = 0;

			for (Bus_place* i : vec)
			{
				if (i->route == route)
				{
					cout << "-------------------------------------\n" << i->driver_name << endl << i->driver_surname << endl << i->number_bus << endl << i->route << endl << i->count_places << endl << "--------------------------------\n";
					count++;
				}
			}
			if (count == 0)
			{
				cout << "Автобусів з таким маршрутом не знайдено...." << endl;

			}
		}

	}
	void  Write_To_File() {
		ofstream file("Bus_Station.txt", 2);
		if (!file)
		{
			cout << "Помилка відкриття файлу!" << endl;
			return;
		}
		vector<Bus_place*> vec;
		TreeToVector(GetRoot(), vec);
		if (vec.empty())
		{
			cout << "Станція порожня!" << endl;
		}
		else {
			for (Bus_place* i : vec)
			{

				file << "-------------------------------------\n" << i->driver_name << endl << i->driver_surname << endl << i->number_bus << endl << i->route << endl << i->count_places << endl << "--------------------------------\n";

			}
			cout << "Дані у файл успішно записано!" << endl;
		}
		file.close();

	}
	void Del(Bus_place* z = NULL)
	{

		if (z != 0)
		{
			Bus_place* temp, * y;

			if (z->left == 0 || z->right == 0)
				y = z;
			else
				y = Next(z);
			if (y->left != 0)
				temp = y->left;
			else
				temp = y->right;
			if (temp != 0)
				temp->parent = y->parent;

			if (y->parent == 0)
				root = temp;
			else if (y == y->parent->left)
				y->parent->left = temp;
			else
				y->parent->right = temp;

			if (y != z)
			{

				z->number_bus = y->number_bus;

			}
			delete y;
		}
		else {
			char select;
			cout << "Автобуса з таким номером не знайдено.Можливо ви хочете видалити всі автобуси?\nТак - Y/Ні - N" << endl;
			cin >> select;
			if (select == 'Y')
			{
				while (root != 0)
					Del(root);
				cout << "Усі автобуси успішно видалено!" << endl;
			}


		}
	}
	~Bus_Station() {
		while (root != nullptr) {
			Del(root);
		}


	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*Tree dictionary;
	dictionary.Add("apple", "яблуко");
	dictionary.Add("train", "потяг");
	dictionary.Add("car", "машина");
	dictionary.Add("shoes", "взуття");
	dictionary.Add("key", "Ключ");
	dictionary.Add("paper", "папір");
	dictionary.Print(dictionary.GetRoot());
	dictionary.Translate("apple");
	dictionary.Translate("apple");
	dictionary.Update("apple", "груша");
	dictionary.Translate("apple");
	dictionary.Translate("shoes");
	dictionary.Translate("shoes");
	dictionary.Translate("train");
	dictionary.PrintTop3();
	dictionary.PrintAntiTop3();*/

	Bus_Station bs1;
	bool exit = false;
	int select;
	size_t count_places;
	unsigned long bus_number;
	string driver_name, driver_surname, route;
	Bus_place* temp;

	cout << "1 - Add\n" << "2 - Delete\n" << "3 - Write To File\n" << "4 - search for route\n" << "5 - search for bus number\n" << "6 - exit\n";
	do
	{
		cin >> select;
		switch (select)
		{
		case 1:
			cin >> bus_number >> driver_name >> driver_surname >> route >> count_places;
			bs1.Add(bus_number, driver_name, driver_surname, route, count_places);
			break;
		case 2:
			cin >> bus_number;
			bs1.Del(bs1.NB_Search(bs1.GetRoot(), bus_number));
			break;
		case 3:
			bs1.Write_To_File();
			break;
		case 4:
			cin >> route;
			bs1.route_Search(route);
			break;
		case 5:
			cin >> bus_number;
			temp = bs1.NB_Search(bs1.GetRoot(), bus_number);
			if (!temp)
			{
				cout << "автобуса не знайдено" << endl;
			}
			else {
				cout << "-------------------------------------\n" << temp->driver_name << endl << temp->driver_surname << endl << temp->number_bus << endl << temp->route << endl << temp->count_places << endl << "--------------------------------\n";
			}
			break;
		case 6:
			exit = true;
			break;

		default:
			exit = true;
			break;
		}
	} while (!exit);
}