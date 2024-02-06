#pragma once
#include"libr.h"
#include"Date.h"
#include"MyString.h"

struct Car {
	MyString name;
	MyString mark;
	int year;
	float engine_capacity;
	MyString car_body;
	float price;

	void fillCarsInfo() {
		char tmp[50];
		cout << "Enter name of car: " << endl;
		cin.getline(tmp, 50);
		name.setMyString(tmp);
		cout << "Enter mark of car: " << endl;
		cin.getline(tmp, 50);
		mark.setMyString(tmp);
		cout << "Enter date of car: " << endl;
		cin>>year;
		cout << "Enter car body: " << endl;
		cin.ignore();
		cin.getline(tmp, 50);
		car_body.setMyString(tmp);
		cout << "Enter engine capacity: " << endl;
		cin >> engine_capacity;
		cout << "Enter price of the car: " << endl;
		cin >> price;
	}

	void printCarsInfo() {
		cout << "------------------------------" << endl;
		cout << "|Name: " << name.str <<"     |"<< endl;
		cout << "|Mark: " << mark.str <<"     |" << endl;
		cout << "|Engine capacity: " << engine_capacity <<"|" << endl;
		cout << "|Car body: " << car_body.str <<"|" << endl;
		cout << "|Date: " << year <<"|" << endl;
		cout << "|Price: " << price << "      |" << endl;
		cout << "------------------------------" << endl;
	}

	/*void saveCarsInfoToTXT(FILE* a) {
		fprintf_s(a, "\n%s %d", name.str);
		fprintf_s(a, "\n%s %d", mark.str);
		fprintf_s(a, "\n%s %d", engine_capacity);
	    fprintf_s(a, "\n%s %d", car_body.str);
		fprintf_s(a, "\n%s %d", date.toString());
		fprintf_s(a, "\n%s %d", city.str);
		fprintf_s(a, "\n%s %d", price);
	}

	void loadCarsInfoFromTXT(FILE* a) {
		char tmp[100];
		fscanf_s(a, "\n%s %d", tmp, 100);
		name.setMyString(tmp);
		fscanf_s(a, "\n%s %d", tmp, 100);
		mark.setMyString(tmp);
		fscanf_s(a, "\n%s %d", engine_capacity);
		fscanf_s(a, "\n%s %d", tmp, 100);
		car_body.setMyString(tmp);
		fscanf_s(a, "\n%s %d",date.toString());
		fscanf_s(a, "\n%s %d", tmp, 100);
		city.setMyString(tmp);
		fscanf_s(a, "\n%s %d", price);
	}*/

	void saveToBin(FILE* fp) {
		fwrite(&name.length, sizeof(int), 1, fp);
		fwrite(name.str, sizeof(char), name.length, fp);

		fwrite(&mark.length, sizeof(int), 1, fp);
		fwrite(mark.str, sizeof(char), mark.length, fp);

		fwrite(&engine_capacity, sizeof(int), 1, fp);

		fwrite(&car_body.length, sizeof(int), 1, fp);
		fwrite(car_body.str, sizeof(char), car_body.length, fp);

		fwrite(&year, sizeof(int), 1, fp);

		fwrite(&price, sizeof(float), 1, fp);

	}

	void loadFromBin(FILE* fp) {
		fread(&name.length, sizeof(int), 1, fp);
		name.str = new char[name.length];
		fread(name.str, sizeof(char), name.length, fp);

		fread(&mark.length, sizeof(int), 1, fp);
		mark.str = new char[mark.length];
		fread(mark.str, sizeof(char), mark.length, fp);

		fread(&engine_capacity, sizeof(int), 1, fp);

		fread(&car_body.length, sizeof(int), 1, fp);
		car_body.str = new char[car_body.length];
		fread(car_body.str, sizeof(char), car_body.length, fp);

		fread(&year, sizeof(int), 1, fp);

		fread(&price, sizeof(float), 1, fp);
	}

};