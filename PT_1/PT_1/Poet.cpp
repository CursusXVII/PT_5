#include "Poet.h"

Poet::Poet() {
	cout << "The Poet constructor is called\n";
	Fullname = "Not found";
	years = "Not found";
	head = NULL;
	countСompositions = 0;
}
Poet::Poet(const Poet& other) {
	cout << "The Poet copy constructor is called\n";
	this->countСompositions = 0;
	*this = other;
}
Poet::~Poet() {
	cout << "The Poet destructor is called\n";
	Сompositions* current = head;
	for (int i = 0; i < countСompositions; ++i) {			//Удаляем элементы, начиная с начала списка
		head = head->nextСompositions;
		delete current;
		current = head;
	}
}

ofstream& operator<<(ofstream& fout, Poet& obj) {			//запись данных в файл
	fout << obj.Fullname << " " << obj.years << " " << obj.countСompositions << endl;
	Сompositions* current = obj.head;
	for (int i = 0; i < obj.countСompositions; ++i) {
		fout << current->name << " ";
		current = current->nextСompositions;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Poet& obj) {			//вывод данных из файла
	int count;												//кол-во произведений
	fin >> obj.Fullname >> obj.years >> count;

	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;										//Считываем название произведения
		obj.addСompositions(name);							//Добавляем произведение
	}
	return fin;
}
ostream& operator<<(ostream& out, Poet& obj) {				//вывод данных в консоль
	out << "Full_name: " << obj.Fullname << endl;

	out << "Years of life: " << obj.years << endl;
	out << "Number of compositions: " << obj.countСompositions << endl;
	Сompositions* current = obj.head;
	for (int i = 0; i < obj.countСompositions; ++i) {
		out << "Сomposition " << i + 1 << " : " << current->name << endl;
		current = current->nextСompositions;
	}
	return out;
}
istream& operator >> (istream& in, Poet& obj) {
	cout << "Enter the data\n";
	cout << "Full_name: ";
	cin >> obj.Fullname;
	cout << "Years of life: ";
	cin >> obj.years;
	obj.countСompositions = 0;	//Обнуляем кол-во произведений
								
	string name;				//Добавляем новые произведения
	int count;
	cout << "Number of compositions: ";
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cout << "Enter " << i + 1 << " Сomposition: ";
		cin >> name;
		obj.addСompositions(name);
	}
	return in;
}
Poet& Poet::operator=(const Poet& other) {
	this->Fullname = other.Fullname;
	this->years = other.years;
									
	Сompositions* current = this->head;						//Очищаем список произведений у объекта слева от знака
	for (int i = 0; i < this->countСompositions; ++i) {
		head = head->nextСompositions;
		delete current;
		current = head;
	}
	this->countСompositions = 0;

	current = other.head;								//Копируем нужное кол-во произведений из объекта справа от знака
	for (int i = 0; i < other.countСompositions; ++i) {
		this->addСompositions(current->name);
		current = current->nextСompositions;
	}

	return *this;
}