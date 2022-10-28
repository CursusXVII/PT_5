#pragma once
#include "Keeper.h"
#include "Poet.h"
#include "ScienceFictionWriter.h"
#include "Novelist.h"
#include <iostream>

using namespace std; 

template <class T>
void PrintedEditionMenu(T& obj, string s) { //передаем строчку, которая содержит в себе имя файла
	bool exit = 1;
	int choice, position;
	string sss;
	
	while (exit) {
		system("cls");
		cout << "Actions with objects. \n1) Add\n2) Delete\n3) Conclusion\n4) Change\n5) Saving to a file\n6) Restoring from a file\n7) Link to the author\n8) Exit\nSelect the command: ";

		cin >> choice;
		if (cin.fail()) {
			choice = -1;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		system("cls");

		if (choice == 1)
		{
			obj.display();
			cout << "Specify the position of the input data: ";
			cin >> position;
			obj.add(position);
			system("pause");
		}
		else if (choice == 2)
		{
			obj.display();
			cout << "Specify the position of the data to be deleted: ";
			cin >> position;
			obj.deleteE(position);
			system("pause");
		}
		else if (choice == 3)
		{
			obj.display();
			system("pause");
		}
		else if (choice == 4)
		{
			obj.display();
			cout << "Specify the position of the data to be modified: ";
			cin >> position;
			obj.dataChange(position);
			system("pause");
		}
		else if (choice == 5)
		{
			obj.writeToFile(s);
			system("pause");
		}
		else if (choice == 6)
		{
			obj.readFromFile(s);
			system("pause");
		}
		else if (choice == 7)
		{
			obj.authorsLink(s);
			system("pause");

		}
		else if (choice == 8)
		{
			exit = 0;
		}
		else
		{
			cout << "A non-existent position has been introduced. Try again\n";
			system("pause");
		}
	}
}