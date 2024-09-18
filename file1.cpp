#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<String.h>
#include<Windows.h>
#include<stdio.h>
using namespace std;





class contact
{
private:
	char* PIB = new char[500];
	char work_fax[250];
	char fax[250];
	char home_fax[250];
	char other_info[250];
public:
	contact()
	{
		strcpy(PIB, "");
		strcpy(work_fax, "");
		strcpy(fax, "");
		strcpy(home_fax, "");
		strcpy(other_info, "");
	}
	
	
	~contact() {
		delete[] this->PIB;
		
	}
	void SeeContact()
	{
		cout << PIB << endl << work_fax << endl << fax << endl << home_fax << endl << other_info << endl;
	}
	void CopyContact(contact& object) {
		strcpy(this->PIB, object.PIB);
		strcpy(this->fax, object.fax);
		strcpy(this->work_fax, object.work_fax);
		strcpy(this->home_fax, object.home_fax);
		strcpy(this->other_info, object.other_info);
	}
	void InitContact() {
		cin.ignore();
		cin.getline(PIB,500);
		cin.getline(work_fax,250);
		cin.getline(fax,250);
		cin.getline(home_fax,250);
		cin.getline(other_info,250);

	}
	bool Verify(char* str) {
		if (strcmp(PIB, str) == 0)
			return true;
		else
			return false;
	}

	void WriteToFile(const char path[]) {
		FILE* outFile = fopen(path, "a");
		fprintf(outFile, "PIB:%s\nwork_fax:%s\nfax:%s\nhome_fax:%s\nother_info:%s\n\n", PIB,work_fax,fax,home_fax,other_info);
		fclose(outFile);
	}
	void ReadFromLine(char* line) {
		
		const char* delimiter = ":";
		char* token = strtok(line, delimiter);
		if (token)
		{
			if (strcmp(token, "PIB") == 0) {
				token = strtok(nullptr, delimiter);
				if (token) {
					PIB = new char[500];
					strcpy(PIB, token);
				}
			}
			else if (strcmp(token, "work_fax") == 0) {
				token = strtok(nullptr, delimiter);
				if (token) {
					
					strcpy(work_fax, token);
				}
			}
			else if (strcmp(token, "fax") == 0) {
				token = strtok(nullptr, delimiter);
				if (token) {
					
					strcpy(fax, token);
				}
			}
			else if (strcmp(token, "home_fax") == 0) {
				token = strtok(nullptr, delimiter);
				if (token) {
					
					strcpy(home_fax, token);
				}
			}
			else if (strcmp(token, "other_info") == 0) {
				token = strtok(nullptr, delimiter);
				if (token) {
					
					strcpy(other_info, token);
				}
			}
			else {
				cout << "error read\n";
				return;
			}
		}
		

		
	}
};
void Add_contact(contact*& list, int& length) {
	if (list == nullptr)
	{
		list = new contact[++length];
		list[length - 1].InitContact();
	}
	else {
		contact* new_list = new contact[length + 1];
		for (int i = 0; i < length; i++)
		{
			new_list[i].CopyContact(list[i]);
		}
		new_list[length].InitContact();
		delete[] list;
		list = new_list;
		length++;
	}
}
void Add_contact(contact*& list, int& length,contact& object) {
	if (list == nullptr)
	{
		list = new contact[++length];
		list[length - 1].CopyContact(object);
	}
	else {
		contact* new_list = new contact[length + 1];
		for (int i = 0; i < length; i++)
		{
			new_list[i].CopyContact(list[i]);
		}
		new_list[length].CopyContact(object);
		delete[] list;
		list = new_list;
		length++;
	}
}

void Delete_contact(contact*& list, int& length) {
	char PIB[500];
	cin.ignore();
	cin.getline(PIB, 500);
	int j = -1;
	for (int i = 0; i < length; i++)
	{
		if (list[i].Verify(PIB))
		{
			j = i;
			break;
		}
	}
	if (j!=-1)
	{
		contact* new_list = new contact[length - 1];
		for (int i = 0; i < length; i++)
		{
			if (i<j)
			{
				new_list[i].CopyContact(list[i]);
			}
			else if(i>j)
			{
				new_list[i-1].CopyContact(list[i]);
			}
		}
		delete[] list;
		list = new_list;
		length--;
	}
	else {
		cout << "Такого контакту не існує!" << endl;
	}
}
void Search_Contact(contact* list, int& length) {
	char PIB[500];
	cin.ignore();
	cin.getline(PIB, 500);
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (list[i].Verify(PIB))
		{
			count++;
			list[i].SeeContact();
		}
	}
	if (count == 0)
	{
		cout << "Такого контакту не існує!" << endl;
	}
}

void LoadContactsFromFile(contact*& list, int& length,const char path[]) {
	FILE* inFile = fopen(path, "r");
	if (!inFile) {
		cout << "Error opening file for reading" << endl;
		return;
	}

	char buffer[1000];
	while (fgets(buffer, sizeof(buffer), inFile)) {
		contact newContact;
		if (strcmp(buffer,"\n" ) != 0)
		{
			// Видаляємо символ нового рядка
			buffer[strcspn(buffer, "\n")] = '\0';
			newContact.ReadFromLine(buffer);
			for (int i = 0; i < 4; i++)
			{
				fgets(buffer, sizeof(buffer), inFile);
				buffer[strcspn(buffer, "\n")] = '\0';
				newContact.ReadFromLine(buffer);
			}
			Add_contact(list, length, newContact); // Додайте об'єкт до списку контактів
		}
		
		
	}

	fclose(inFile);
}
void SeeAllContact(contact*& list, int& length) {
	for (int i = 0; i < length; i++)
	{
		list[i].SeeContact();
	}
}
void ImportToFile(contact*& list, int& length,char path[]) {
	for (int i = 0; i < length; i++)
	{
		list[i].WriteToFile(path);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int length = 0;
	char path[] = "Contact1.txt";
	contact* list = nullptr;
	bool exit = false;
	int select;
	cout << "Вас вітає программа \"Телефонний довідник\" !\nОсь меню керування:\n1 - додати контакт\n2 - видалити контакт\n";
	cout << "3 - шукати контакт за ПІБ\n4 - імпортувати довідник у текстовий файл\n5 - експортувати довідник з текстового файлу\n 6 - подивитися список контактів\n7 - вийти з програми\n";
	do
	{
		
		cin >> select;
		switch (select) {
			case 7:exit = true; break;
			case 1:Add_contact(list, length); break;
			case 2:Delete_contact(list, length); break;
			case 3:Search_Contact(list, length); break;
			case 4:ImportToFile(list, length, path); break;
			case 5:LoadContactsFromFile(list, length, path); break;
			case 6:SeeAllContact(list, length); break;
			default:exit = true; break;

		}
	} while (exit!=true);
	cout << "До побачення!" << endl;
	delete[] list;



}