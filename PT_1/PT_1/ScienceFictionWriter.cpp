#include "ScienceFictionWriter.h"
ScienceFictionWriter::ScienceFictionWriter() {
	cout << "The Poet constructor is called\n";
	Fullname = "Not found";
	films = "Not found";
	head = NULL;
	count�ompositions = 0;
}
ScienceFictionWriter::ScienceFictionWriter(const ScienceFictionWriter& other) {
	cout << "The Poet copy constructor is called\n";
	this->count�ompositions = 0;
	*this = other;
}
ScienceFictionWriter::~ScienceFictionWriter() {
	cout << "The Poet destructor is called\n";
	�ompositions* current = head;
	for (int i = 0; i < count�ompositions; ++i) {
		head = head->next�ompositions;
		delete current;
		current = head;
	}
}
ofstream& operator<<(ofstream& fout, ScienceFictionWriter& obj) {							//���������� ��������� ������ � ����
	fout << obj.Fullname << " " << obj.films << " " << obj.count�ompositions << endl;
	�ompositions* current = obj.head;
	for (int i = 0; i < obj.count�ompositions; ++i) {
		fout << current->name << " ";
		current = current->next�ompositions;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, ScienceFictionWriter& obj) {							//���������� ��������� ������ �� �����
	int count;
	fin >> obj.Fullname >> obj.films >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;
		obj.add�ompositions(name);
	}
	return fin;
}
ostream& operator<<(ostream& out, ScienceFictionWriter& obj) {								//���������� ��������� ������ �� �������
	out << "Full_name: " << obj.Fullname << endl;
	out << "Movies based on books: " << obj.films << endl;
	out << "Number of compositions: " << obj.count�ompositions << endl;
	�ompositions* current = obj.head;
	for (int i = 0; i < obj.count�ompositions; ++i) {
		out << "Composition " << i + 1 << " : " << current->name << endl;
		current = current->next�ompositions;
	}
	return out;
}
istream& operator >> (istream& in, ScienceFictionWriter& obj) {							//���������� ��������� ������ � ����������
	cout << "Enter the data\n";
	cout << "Full_name: ";
	cin >> obj.Fullname;
	cout << "Are there films based on books: ";
	cin >> obj.films;
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
ScienceFictionWriter& ScienceFictionWriter::operator=(const ScienceFictionWriter& other) {						//���������� ��������� ������������
	this->Fullname = other.Fullname;
	this->films = other.films;
	�ompositions* current = this->head;											//��������� �� ������ ������������ �������
	for (int i = 0; i < this->count�ompositions; ++i) {
		head = head->next�ompositions;
		delete current;
		current = head;
	}
	this->count�ompositions = 0;												//��������� ������
	current = other.head;
	for (int i = 0; i < other.count�ompositions; ++i) {
		this->add�ompositions(current->name);
		current = current->next�ompositions;
	}
	return *this;
}