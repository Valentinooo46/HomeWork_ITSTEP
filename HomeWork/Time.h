#pragma once
#include<string>
#include<iostream>
using namespace std;
class Time
{
public:
	int day, month, year;

	Time(int _day, int _month, int _year) {
		try
		{
			if (_year < 0 || _day > daysInMonth(_month, _year) || _day < 1 || _month < 1 || _month > 12)
			{
				throw (string)"Invalid Input Data!";
			}
			else {
				day = _day, month = _month, year = _year;
				cout << "Correct Input!\n";
			}
		}
		catch (string str)
		{

			do
			{
				cout << str << endl;
				cin >> _day >> _month >> _year;
			} while (_year < 0 || _day > daysInMonth(_month, _year) || _month < 1 || _month > 12);
			day = _day, month = _month, year = _year;
			cout << "Correct Input!\n";
		}

	}
	Time(tm* timeinfo) :day(timeinfo->tm_mday), month(timeinfo->tm_mon + 1), year(timeinfo->tm_year + 1900) {}
	int operator-(Time temp) {
		try
		{
			if (year < temp.year || (year == temp.year && month < temp.month) || (year == temp.year && month == temp.month && day <= temp.day))
			{
				int days = 0;
				if (year < temp.year)
				{
					for (int i = year + 1; i < temp.year; i++)
					{
						if (isLeapYear(i))
						{
							days += 366;
						}
						else {
							days += 365;
						}
					}
					for (int i = month + 1; i < 13; i++)
					{
						days += daysInMonth(i, year);
					}
					for (int i = 1; i < temp.month + 1; i++)
					{
						days += daysInMonth(i, temp.year);
					}
					days += daysInMonth(month, year) - day;
					days += temp.day;
				}
				else if (year > temp.year)
				{
					for (int i = temp.year + 1; i < year; i++)
					{
						if (isLeapYear(i))
						{
							days += 366;
						}
						else {
							days += 365;
						}
					}
					for (int i = temp.month + 1; i < 13; i++)
					{
						days += daysInMonth(i, temp.year);
					}
					for (int i = 1; i < month + 1; i++)
					{
						days += daysInMonth(i, year);
					}
					days += daysInMonth(temp.month, temp.year) - temp.day;
					days += day;
				}
				else {
					if (temp.month > month)
					{
						for (int i = month + 1; i < temp.month; i++)
						{
							days += daysInMonth(i, year);
						}
						days += daysInMonth(month, year) - day;
						days += temp.day;
					}
					else if (temp.month < month)
					{
						for (int i = temp.month + 1; i < month; i++)
						{
							days += daysInMonth(i, temp.year);
						}
						days += daysInMonth(temp.month, temp.year) - temp.day;
						days += day;
					}
					else {
						if (day > temp.day)
						{
							days += day - temp.day;
						}
						else {
							days += temp.day - day;
						}
					}
				}
				return days;
			}
			else {
				throw - 1;
			}
		}
		catch (int val)
		{

			return val;
		}

	}

	bool operator==(Time temp) {
		return (day == temp.day && month == temp.month && year == temp.year) ? true : false;
	}
protected:
	int daysInMonth(int month, int year) {
		switch (month) {
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return isLeapYear(year) ? 29 : 28;
		default:
			return 31;
		}
	}
	bool isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
};

