#pragma once
#include"libr.h"
#include"Date.h"
#include"MyString.h"

struct Costumers {
	MyString name;
	Date date;
	int phonenumber;
	



	void fillCostumersInfo() {
		char tmp[150];
		cout << "Enter name of manager: " << endl;
		cin.getline(tmp, 150);
		name.setMyString(tmp);
		cout << "Enter date of manager: " << endl;
		date.fillDate();
		cout << "Enter phone number of manager: " << endl;
		cin >> phonenumber;
	
	}

	void printCostumersInfo() {
		cout << "------------------------------" << endl;
		cout << "|Name: " << name.str << "     |" << endl;
		cout << "|Date: " << date.toString() << "|" << endl;
		cout << "|Phone numbber: " << phonenumber << "|" << endl;
		
		cout << "------------------------------" << endl;
	}

	void saveToBin2(FILE* fp) {
		fwrite(&name.length, sizeof(int), 1, fp);
		fwrite(name.str, sizeof(char), name.length, fp);

		fwrite(&date, sizeof(Date), 1, fp);

		fwrite(&phonenumber, sizeof(int), 1, fp);


	}

	void loadFromBin2(FILE* fp) {
		fread(&name.length, sizeof(int), 1, fp);
		name.str = new char[name.length];
		fread(name.str, sizeof(char), name.length, fp);

		fread(&date, sizeof(Date), 1, fp);

		fread(&phonenumber, sizeof(int), 1, fp);

	}




};
