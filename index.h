#pragma once
#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;
template<typename T> class Queue {
	T* data;
	int length;


public:
	Queue():data(nullptr),length(0) {}
	~Queue() {
		if (data != nullptr)
		{
			delete[] data;
		}
		
	}
	void push(T value) {
		if (data == nullptr)
		{
			data = new T[1];
			data[0] = value;
			length++;
		}
		else {
			T* new_data = new T[length + 1];
			for (size_t i = 0; i < length; i++)
			{
				new_data[i] = data[i];
			}
			new_data[length] = value;
			delete[] data;
			data = new_data;
			length++;
		}
	}
	T* pop() {
		if (length == 0)
		{
			return nullptr;
		}
		else {
			T* new_data;
			T x = *data;
			(length > 1)?(new_data = new T[length - 1]):(new_data = nullptr);
			for (size_t i = 1; i < length; i++)
			{
				new_data[i - 1] = data[i];
			}
			delete[] data;
			data = new_data;
			length--;
			return &x;
			
		}
	}
	void Print() {
		for (size_t i = 0; i < length; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	const T& front() {
		if (data != nullptr)
		{
			return data[0];
		}
		else {
			T c = NULL;
			return c;
		}
		
	}
	friend ostream& operator<<(ostream& output, Queue& que) {
		for (size_t i = 0; i < que.length; i++)
		{
			cout << que.data[i];
		}
		return output;
	}
};
