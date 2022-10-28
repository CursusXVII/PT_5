#include "Novelist.h"
Novelist::Novelist() {
	cout << "The Novelist constructor is called\n";
	Fullname = "Not found";
	biography = "Not found";
	years_of_life = "Not found";
	head = NULL;
	count�ompositions = 0;
}
Novelist::Novelist(const Novelist& other) {
	cout << "The Novelist copy constructor is calledt\n";
	this->count�ompositions = 0;
	*this = other;
}
Novelist::~Novelist() {
	cout << "The Novelist destructor is called\n";
	�ompositions* current = head;
	for (int i = 0; i < count�ompositions; ++i) {
		head = head->next�ompositions;
		delete current;
		current = head;
	}
}
ofstream& operator<<(ofstream& fout, Novelist& obj) {					//���������� ��������� ������ � ����
	fout << obj.Fullname << " " << obj.years_of_life << " " << obj.biography << " " << obj.count�ompositions << endl;
	�ompositions* current = obj.head;
	for (int i = 0; i < obj.count�ompositions; ++i) {
		fout << current->name << " ";
		current = current->next�ompositions;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Novelist& obj) {					//���������� ��������� ������ �� �����
	int count;
	fin >> obj.Fullname >> obj.years_of_life >> obj.biography >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;
		obj.add�ompositions(name);
	}
	return fin;
}
ostream& operator<<(ostream& out, Novelist& obj) {						//���������� ��������� ������ �� �������
	out << "Full_name: " << obj.Fullname << endl;
	out << "Years of life: " << obj.years_of_life << endl;
	out << "Brief biography: " << obj.biography << endl;
	out << "Number of compositions: " << obj.count�ompositions << endl;
	�ompositions* current = obj.head;
	for (int i = 0; i < obj.count�ompositions; ++i) {
		out << "Composition " << i + 1 << " : " << current->name << endl;
		current = current->next�ompositions;
	}
	return out;
}
istream& operator >> (istream& in, Novelist& obj) {						//���������� ��������� ������ � ����������
	cout << "Enter the data\n";
	cout << "Full_name: ";
	cin >> obj.Fullname;
	cout << "Years of life: ";
	cin >> obj.years_of_life;
	cout << "Brief biography: ";
	cin >> obj.biography;
	�ompositions* current = obj.head;
	for (int i = 0; i < obj.count�ompositions; ++i) {
		obj.head = obj.head->next�ompositions;
		delete current;
		current = obj.head;
	}
	obj.count�ompositions = 0;
	string name;
	int count;
	cout << "Number of compositions: ";
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cout << "Enter " << i + 1 << " composition: ";
		cin >> name;
		obj.add�ompositions(name);
	}
	return in;
}
Novelist& Novelist::operator=(const Novelist& other) {					//���������� ��������� ������������
	this->Fullname = other.Fullname;
	this->years_of_life = other.years_of_life;
	this->biography = other.biography;
	�ompositions* current = this->head;									//��������� �� ������ ������������ �������
	for (int i = 0; i < this->count�ompositions; ++i) {
		head = head->next�ompositions;
		delete current;
		current = head;
	}
	this->count�ompositions = 0;										//��������� ������
	current = other.head;
	for (int i = 0; i < other.count�ompositions; ++i) {
		this->add�ompositions(current->name);
		current = current->next�ompositions;
	}
	return *this;
}