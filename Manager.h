#pragma once
#include"libr.h"
#include"Date.h"
#include"MyString.h"

struct Manager {
	MyString name_m;
	Date date;
	int phonenumber;
	int workexp;
	
	

	void fillManagerInfo() {
		char tmp[150];
		cout << "Enter name of manager: " << endl;
		cin.getline(tmp, 150);
		name_m.setMyString(tmp);
		cout << "Enter date of manager: " << endl;
		date.fillDate();
		cout << "Enter phone number of manager: " << endl;
		cin>>phonenumber;
		cout << "Enter work experince of manager: " << endl;
		cin>>workexp;
	}

	void printManagerInfo() {
		cout << "------------------------------" << endl;
		cout << "|Name: " << name_m.str << "     |" << endl;
		cout << "|Date: " << date.toString()<<"|" << endl;
		cout << "|Phone numbber: "<<phonenumber<<"|" << endl;
		cout << "|Work experience:"<<workexp<<"|" << endl;
		cout << "------------------------------" << endl;
	}

	void saveBin(FILE* fp) {
		fwrite(&name_m.length, sizeof(int), 1, fp);
		fwrite(name_m.str, sizeof(char), name_m.length, fp);

		fwrite(&date, sizeof(Date), 1, fp);

		fwrite(&phonenumber, sizeof(int), 1, fp);
	
		fwrite(&workexp, sizeof(int), 1, fp);
		

	}

	void loadBin(FILE* fp) {
		fread(&name_m.length, sizeof(int), 1, fp);
		name_m.str = new char[name_m.length];
		fread(name_m.str, sizeof(char), name_m.length, fp);

		fread(&date, sizeof(Date), 1, fp);

		fread(&phonenumber, sizeof(int), 1, fp);
		
		fread(&workexp, sizeof(int), 1, fp);
		
	}

	
};