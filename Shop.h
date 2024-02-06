#pragma once
#include"libr.h"
#include"Cars.h"
#include"Date.h"
#include"MyString.h"
#include"Manager.h"


struct Shop {

	int size = 0,size1=0;
	
	Car* arr = nullptr;
	Manager* arr1 = nullptr;
	
	void addCars() {
		size++;
		Car* tmp = new Car[size];
		for (int i = 0; i < size - 1; i++)
		{
			tmp[i] = arr[i];
		}
		if (arr != NULL) {
			delete[]arr;
		}
		cout << "Enter info about new car: " << endl;
		tmp[size - 1].fillCarsInfo();
		arr = tmp;
		saveCars();
	}
	
	int findCarsbyMark(const char* mark) {
		for (int i = 0; i < size; i++) {
			if (strcmp(arr[i].mark.str, mark) == 0) {
				//return i;
				arr[i].printCarsInfo();
			}
		}
		return -1;
	}

	int findCars(const char* mark) {
		for (int i = 0; i < size; i++) {
			if (strcmp(arr[i].mark.str, mark) == 0) {
				return i;
			}
		}
		return -1;
	}

	void delCars(const char* mark) {
		int index = findCars(mark);
		if (index == -1) {
			cout << "Not find" << endl;
		}
		else {
			size--;
			Car* tmp = new Car[size];
			for (int i = 0, j = 0; i < size + 1; i++) {
				if (i != index) {
					tmp[j++] = arr[i];
				}
			}
			if (arr != NULL) {
				delete[]arr;
			}
			arr = tmp;
			saveCars();
		}
	}

	void findCarsByMark(MyString mark) {
		for (int i = 0; i < size; i++) {
			if (strcmp(arr[i].mark.str, mark.str) == 0) {
				cout << arr[i].mark.str << endl;
			}
		}

	}

	void printCarsInfo() {
		for (int i = 0; i < size; i++) {
			cout << "\t #" << i + 1 << endl;
			arr[i].printCarsInfo();
			cout << endl;
		}
	}

	void saveCars() {
		FILE* fp;
		fopen_s(&fp, "Shop.bin", "wb");
		if (fp == NULL)
		{
			cout << "ERROR" << endl;
		}
		else {
			fwrite(&size, sizeof(int), 1, fp);
			for (int i = 0; i < size; i++) {
				arr[i].saveToBin(fp);
			}
			fclose(fp);
		}
	}

	void loadCars() {
		FILE* fp;
		fopen_s(&fp, "Shop.bin", "rb");
		if (fp == NULL)
		{
			cout << "ERROR" << endl;
		}
		else {
			fread(&size, sizeof(int), 1, fp);
			arr = new Car[size];
			for (int i = 0; i < size; i++) {
				arr[i].loadFromBin(fp);
			}
			fclose(fp);
			cout << " Loaded " << endl;
		}
	}

	int findTheHighestPrice() {
		int a = 0, b = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i].price > a) {
				a = arr[i].price;
				b = i;
			}
		}
		return b;
	}

	void findcountryByYear() {
		sortByYear();
		int c = 1;
		int max_y = arr[0].year;
		int y = arr[0].year;
		int max_c = 1;
		for (size_t i = 0; i < size; i++)
		{
			if (y == arr[i].year)
			{
				c++;
			}
			else {
				y = arr[i].year;
				if (c > max_c)
				{
					max_y == arr[i].year;
					max_c == c;
				}
				c = 1;
			}
		}
		cout << " The country from which received animals at the most a large amount: " << max_y << " \n";
	}

	void sortByPrice() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (arr[j].price < arr[j + 1].price)
				{
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	void sortByYear() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (arr[j].year < arr[j + 1].year)
				{
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	void findByYearstartOpen() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (arr[j].year > arr[j + 1].year)
				{
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		cout << "Carshop started function in  " << arr[0].year << endl;
	}




	void addManager() {
		size1++;
		Manager* tmp1 = new Manager[size1];
		for (int i = 0; i < size1 - 1; i++)
		{
			tmp1[i] = arr1[i];
		}
		if (arr1 != NULL) {
			delete[]arr1;
		}
		cout << "Enter info about new manager: " << endl;
		tmp1[size1 - 1].fillManagerInfo();
		arr1 = tmp1;
		saveManager();
	}

	void delManager(const char* name) {
		int index1 = findManagerByname(name);
		if (index1 == -1) {
			cout << "Not find" << endl;
		}
		else {
			size1--;
			Manager* tmp1 = new Manager[size1];
			for (int i = 0, j = 0; i < size1 + 1; i++) {
				if (i != index1) {
					tmp1[j++] = arr1[i];
				}
			}
			if (arr1 != NULL) {
				delete[]arr1;
			}
			arr1 = tmp1;
			saveManager();
		}
	}

	void printManager1Info() {
		for (int i = 0; i < size1; i++) {
			cout << "\t #" << i + 1 << endl;
			arr1[i].printManagerInfo();
			cout << endl;
		}
	}

	void saveManager() {
		FILE* fp1;
		fopen_s(&fp1, "Manager.bin", "wb");
		if (fp1 == NULL)
		{
			cout << "ERROR" << endl;
		}
		else {
			fwrite(&size1, sizeof(int), 1, fp1);
			for (int i = 0; i < size1; i++) {
				arr1[i].saveBin(fp1);
			}
			fclose(fp1);
		}
	}

	void loadManager() {
		FILE* fp1;
		fopen_s(&fp1, "Manager.bin", "rb");
		if (fp1 == NULL)
		{
			cout << "ERROR" << endl;
		}
		else {
			fread(&size1, sizeof(int), 1, fp1);
			arr1 = new Manager[size1];
			for (int i = 0; i < size1; i++) {
				arr1[i].loadBin(fp1);
			}
			fclose(fp1);
			cout << " Loaded " << endl;
		}
	}

	int findManagerByname(const char* name_m) {
		for (int i = 0; i < size1; i++) {
			if (strcmp(arr1[i].name_m.str, name_m) == 0) {
				cout << arr1[i].name_m.str << endl;
			}
		}
		return 1;
	}

	void sortByEXP() {
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size1 - 1 - i; j++)
			{
				if (arr1[j].workexp < arr1[j + 1].workexp)
				{
					swap(arr1[j], arr1[j + 1]);
				}
			}
		}
	}



    



};
