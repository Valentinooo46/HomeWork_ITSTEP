#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
using namespace std;

template<typename T>
class Node {


public:
	T value;
	Node<T>* next;
	Node() :next(nullptr) {}
	Node(T value) :value(value) {}

};
template<typename T>
class List {



public:
	Node<T>* ph, * pt;
	List() :ph(nullptr), pt(nullptr) {}
	~List() {
		DelAll();
	}
	void AddtoHead(T value) {
		Node<T>* temp = new Node<T>(value);
		temp->next = ph;
		if (!ph)
		{
			ph = temp;
			pt = temp;
		}
		else {
			ph = temp;
		}
	}
	void AddtoTail(T value) {
		Node<T>* temp = new Node<T>(value);
		temp->next = nullptr;
		if (!ph)
		{
			ph = temp;
			pt = temp;
		}
		else {
			pt->next = temp;
			pt = temp;
		}
	}
	T* DelfromHead() {
		if (!ph)
		{
			return nullptr;
		}
		else {
			Node<T>* temp = ph;
			T temp_value;
			ph = ph->next;
			temp_value = temp->value;
			delete temp;
			return &temp_value;
		}
	}
	T* DelfromTail() {
		if (!ph)
		{
			return nullptr;
		}
		else {
			Node<T>* temp = ph;
			T temp_value;
			while (temp->next != pt) {
				temp = temp->next;
			}
			temp_value = temp->value;
			delete pt;
			pt = temp;
			return &temp_value;
		}
	}
	void DelAll() {
		while (!ph) {
			DelfromTail();
		}
	}
	void Show() {
		if (!ph)
		{
			cout << "empty" << endl;
		}
		else {
			Node<T>* temp = ph;
			while (temp != nullptr) {
				cout << temp->value << " ";
				temp = temp->next;
			}
			cout << endl;

		}
	}
};
template<typename T>
class Modify_list :public List<T> {
public:
	Modify_list() :List<T>() {}
	size_t length() {
		Node<T>* temp = this->ph;
		size_t count = 0;
		while (temp != nullptr) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	void insert(T value, int number) {
		if (length() > 0)
		{


			if (number > length() || number <= 0)
			{
				cout << "invalid index" << endl;
			}
			else {

				if (number == 1)
				{
					this->AddtoHead(value);
				}
				else if (number == length())
				{
					Node<T>* insert = new Node<T>(value);
					Node<T>* temp = this->ph;
					while (temp->next != this->pt)
					{
						temp = temp->next;
					}
					insert->next = this->pt;
					temp->next = insert;
				}
				else {
					Node<T>* insert = new Node<T>(value);
					Node<T>* temp = this->ph;
					size_t len = length();
					for (size_t i = 2; i < len; i++)
					{
						if (i == number)
						{
							insert->next = temp->next;
							temp->next = insert;
						}
						else {
							temp = temp->next;
						}
					}
				}
			}
		}
		else {
			cout << "empty" << endl;
		}
	}
	void pop(int number) {
		if (length() > 0)
		{


			if (number > length() || number <= 0)
			{
				cout << "invalid index" << endl;
			}
			else {

				if (number == 1)
				{
					this->DelfromHead();
				}
				else if (number == length())
				{
					this->DelfromTail();
				}
				else {

					Node<T>* temp = this->ph;
					size_t len = length();
					for (size_t i = 2; i < len; i++)
					{
						if (i == number)
						{
							Node<T>* poper = temp->next;
							temp->next = poper->next;
							delete poper;
						}
						else {
							temp = temp->next;
						}
					}
				}
			}
		}
		else {
			cout << "empty" << endl;
		}
	}
	int search(T value) {
		if (this->ph != nullptr)
		{
			Node<T>* temp = this->ph;
			size_t len = length();
			for (size_t i = 0; i < len; i++)
			{
				if (temp->value == value)
				{
					return i + 1;
				}
				temp = temp->next;
			}
			return NULL;
		}
		else{
			cout << "empty" << endl;
			return NULL;
		}
		
	}
	int find(T search_value, T new_value) {
		if (this->ph != nullptr)
		{
			int count = 0;
			Node<T>* temp = this->ph;
			size_t len = length();
			for (size_t i = 0; i < len; i++)
			{
				if (temp->value == search_value)
				{
					temp->value = new_value;
					count++;
				}
				temp = temp->next;
			}
			return (count == 0) ? -1 : count;
			
		}
		else {
			cout << "empty" << endl;
			return -1;
		}
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Modify_list<float> l1;
	for (size_t i = 0; i < 2; i++)
	{
		l1.AddtoTail(1.2);
	}
	for (size_t i = 0; i < 2; i++)
	{
		l1.AddtoHead(1.5);
	}
	for (size_t i = 0; i < 5; i++)
	{
		l1.AddtoHead(2);
	}
	l1.Show();
	cout << l1.length() << endl;
	int n;
	cin >> n;
	l1.insert(46.9, n);
	l1.Show();
	cout << l1.find(1.3, 666.6) << endl;
	l1.Show();
};

