#include"libr.h"
#include"Cars.h"
#include"Shop.h"
#include"Manager.h"

int main() {
	setlocale(0, "");
	
	Shop i;
	Shop i1;
	Car* arr = nullptr;
	Manager* arr1 = nullptr;
	int size = 0;
	i.loadCars();
	i1.loadManager();
	int menu = 0,N=0;
	char s[100];
	char c[100];
	system("cls");
	do {
		
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "1. Add new car ; " << endl;
		cout << "2. List of car; " << endl;
		cout << "3. Delete car; " << endl;
		cout << "4. Find car by mark; " << endl;
		cout << "5. The highest price of car; " << endl;
		cout << "6. Sort by price;" << endl;
		cout << "7. Sort by year; " << endl;
		cout << "8. See when the shop started function ; " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "9. Add new manager ; " << endl;
		cout << "10. List of manager ; " << endl;
		cout << "11. Delete manager; " << endl;
		cout << "12. Sort by work experience;" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		
		cin >> menu;
		system("cls");
		switch (menu)		
		{
			
		case 1:
			cin.ignore();
			i.addCars();
			break;
		case 2:
			i.printCarsInfo();
			break;
		case 3:
			cout << "Enter mark of car: " << endl;
			cin >> s;
			i.delCars(s);
			break;
		case 4:
			cout << "Enter mark of car: " << endl;
			cin >> s;
			N = i.findCarsbyMark(s);
			if (N == -1) {
				cout << "Not found!" << endl;
			}
			else {
				arr[N].printCarsInfo();
			}
			break;
		case 5:
			cout << "The highest price of car: " << endl;
			cout << i.arr[i.findTheHighestPrice()].name.str;
			cout << endl;
			break;
		case 6:
			i.sortByPrice();
			i.printCarsInfo();
			break;
		case 7:
			i.sortByYear();
			i.printCarsInfo();
			break;
		case 8:
			i.findByYearstartOpen();
			break;
		case 9:
			cin.ignore();
			i1.addManager();
			break;
		case 10:
			i1.printManager1Info();
			break;
		case 11:
			cout << "Enter the name of manager: " << endl;
			cin >> c;
			i1.delManager(c);
			break;
		case 12:
			i1.sortByEXP();
			i1.printManager1Info();
			break;

		default:
			break;
		}
	} while (menu != NULL);
	i.saveCars();
	i1.saveManager();

}