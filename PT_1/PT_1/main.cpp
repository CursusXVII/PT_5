#include "ObjectMenu.h"

int main() {

	Keeper<Poet> poet;										//создание экземпл€ров класса типа данных poet, novelist, sfwriter
	Keeper<Novelist> novelist;	
	Keeper<ScienceFictionWriter> science_fiction_writer;		

	bool exit = 1;
	int choice;

	while (exit) {
		system("cls");
		cout << "Writers.\n1) Poet\n2) Novelist\n3) Science Fiction Writer\n4)Exit\nEnter the command: ";

		cin >> choice;
		if (cin.fail()) {
			choice = -1;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		if (choice == 1)
			PrintedEditionMenu(poet, "Poet.txt");
		else if(choice == 2)
			PrintedEditionMenu(novelist, "Novelist.txt");
		else if (choice == 3)
			PrintedEditionMenu(science_fiction_writer, "ScienceFictionWriter.txt");
		else if (choice == 4)
			exit = 0;
		else {
			cout << "\nError. Try again.\n";
			system("pause");
		}
	}
	return 0;
}