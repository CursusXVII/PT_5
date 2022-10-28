#include "Poet.h"

Poet::Poet() {
	cout << "The Poet constructor is called\n";
	Fullname = "Not found";
	years = "Not found";
	head = NULL;
	count�ompositions = 0;
}
Poet::Poet(const Poet& other) {
	cout << "The Poet copy constructor is called\n";
	this->count�ompositions = 0;
	*this = other;
}
Poet::~Poet() {
	cout << "The Poet destructor is called\n";
	�ompositions* current = head;
	for (int i = 0; i < count�ompositions; ++i) {			//������� ��������, ������� � ������ ������
		head = head->next�ompositions;
		delete current;
		current = head;
	}
}

ofstream& operator<<(ofstream& fout, Poet& obj) {			//������ ������ � ����
	fout << obj.Fullname << " " << obj.years << " " << obj.count�ompositions << endl;
	�ompositions* current = obj.head;
	for (int i = 0; i < obj.count�ompositions; ++i) {
		fout << current->name << " ";
		current = current->next�ompositions;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Poet& obj) {			//����� ������ �� �����
	int count;												//���-�� ������������
	fin >> obj.Fullname >> obj.years >> count;

	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;										//��������� �������� ������������
		obj.add�ompositions(name);							//��������� ������������
	}
	return fin;
}
ostream& operator<<(ostream& out, Poet& obj) {				//����� ������ � �������
	out << "Full_name: " << obj.Fullname << endl;

	out << "Years of life: " << obj.years << endl;
	out << "Number of compositions: " << obj.count�ompositions << endl;
	�ompositions* current = obj.head;
	for (int i = 0; i < obj.count�ompositions; ++i) {
		out << "�omposition " << i + 1 << " : " << current->name << endl;
		current = current->next�ompositions;
	}
	return out;
}
istream& operator >> (istream& in, Poet& obj) {
	cout << "Enter the data\n";
	cout << "Full_name: ";
	cin >> obj.Fullname;
	cout << "Years of life: ";
	cin >> obj.years;
	obj.count�ompositions = 0;	//�������� ���-�� ������������
								
	string name;				//��������� ����� ������������
	int count;
	cout << "Number of compositions: ";
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cout << "Enter " << i + 1 << " �omposition: ";
		cin >> name;
		obj.add�ompositions(name);
	}
	return in;
}
Poet& Poet::operator=(const Poet& other) {
	this->Fullname = other.Fullname;
	this->years = other.years;
									
	�ompositions* current = this->head;						//������� ������ ������������ � ������� ����� �� �����
	for (int i = 0; i < this->count�ompositions; ++i) {
		head = head->next�ompositions;
		delete current;
		current = head;
	}
	this->count�ompositions = 0;

	current = other.head;								//�������� ������ ���-�� ������������ �� ������� ������ �� �����
	for (int i = 0; i < other.count�ompositions; ++i) {
		this->add�ompositions(current->name);
		current = current->next�ompositions;
	}

	return *this;
}