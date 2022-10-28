#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

template <class T> 
class Keeper {
	T* array;						//��������� �� �������� �������
	int consize;					//������ ����������
public:
	Keeper();
	Keeper(const Keeper&);
	~Keeper();
	void add(int index);			//���������� 
	void deleteE(int index);		//�������� 
	void writeToFile(string);		//������ � ����
	void authorsLink(string);			//�������������� �����
	void readFromFile(string);		//������ �� �����
	void display();					//����� 
	void dataChange(int index);		//���������
};
template<class T>
Keeper<T>::Keeper() {
	cout << "The default Keeper constructor is called\n";
	array = nullptr;
	consize = 0;
}
template<class T>
Keeper<T>::Keeper(const Keeper& other) {
	this->array = new T[other.consize];		//������� ������
	this->consize = other.consize;				//�������� ������
	for (int i = 0; i < consize; ++i)			//�������� ������ ������� � ����� ������
		this->array[i] = other.array[i];
}
template<class T>
Keeper<T>::~Keeper() {
	cout << "The Keeper destructor is called\n";
	delete[] array;
}
template<class T>
void Keeper<T>::add(int index) {
	try {
		if (index < 0 || index > consize)
			throw exception("Invalid index");
		T* tmp = new T[consize + 1];				//������� ����� ������ �� ���� ������� ������ ����������
		int j = 0;
		for (int i = 0; i < consize; ++i) {		//�������� ��� �������� � ����� ������
			if (index == i)						//���� ������ ����� ���������� ��������, �� ���������� 
				j++;
			tmp[j++] = array[i];				//���������� �������, ����� ������ ����������
		}
		delete[] array;						//������� ������ ������
		array = tmp;							//��������� �� ����� ������
		cin >> array[index];					//������ ������ ������������ ��������, ������� ��������� ��� �������� index
		++consize;									//����������� ������ ����������
		cout << "\nNew item successfully added\n";
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::deleteE(int index) {
	try {
		if (consize == 0) {							//�������� �� ������� � ����������
			exception ex("Nothing to delete");
			throw ex;
		}
		if (index < 0 || index >= consize) {		//�������� �� ������������ �������
			exception ex("Invalid index");
			throw ex;
		}
		T* tmp = new T[consize - 1];				//������� ����� ������ �� ���� ������� ������ ����������
		int j = 0;
		for (int i = 0; i < consize; ++i) {			//�������� ��� ��������, ����� ����, ������� ����� �������
			if (index != i)
				tmp[j++] = array[i];
		}
		delete[] array;							//������� ������ ������
		array = tmp;								//ptr ��������� �� ����� ������
		--consize;									//������ ���������� ����������
		cout << "\nItem removed\n";
	}
	catch (exception& ex) {
		cout << ex.what() << endl;					//����� ������ �� �����
	}
}
template<class T>
void Keeper<T>::writeToFile(string s) {
	try {
		ofstream fout(s, ios::out);
		if (!fout) {
			exception ex("Could not open the file");
			throw ex;
		}
		if (consize == 0) {
			exception ex("There is no data to record");
			throw ex;
		}
		fout << consize << endl;					//������ ������� ����������
		for (int i = 0; i < consize; ++i) {			//������ ���� ��������� ����������
			fout << array[i] << endl;
		}
		fout.close();
		//copy poet
		cout << "Writing to the file was successful\n";
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::authorsLink(string s) {
	try {;
			string link;
			cout << "Enter the name of the author or work:";
			cin >> link;

			cout << "\nLink to Wikipedia:\n";
			cout << "https://ru.wikipedia.org/wiki/" << link << endl << endl;

			cout << "Link to Livelib:\n";
			cout << "https://www.livelib.ru/find/" << link << endl << endl;

			cout << "Link to Culture:\n";
			cout << "https://www.culture.ru/persons/8195/" << link << endl << endl;

			cout << "Link to Biographe:\n";
			cout << "https://biographe.ru/znamenitosti/" << link << endl << endl;

			cout << "Link to alexandr-pushkin\n:";
			cout << "https://aleksandr-pushkin.su/" << link << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::readFromFile(string s) {
	try {
		ifstream fin(s, ios::in);
		if (!fin) {
			exception ex("Could not open the file");
			throw ex;
		}
		delete[] array;							//������� ������, ��� ��� ����� �������� ������ �� �����
		fin >> consize;							//��������� ������ ���������� � �����
		array = new T[consize];					//������� ������ �������� ���������� � �����
		for (int i = 0; i < consize; ++i) {		//��������� ��� �������� �� �����
			fin >> array[i];
		}
		fin.close();
		cout << "Reading from the file was successful\n";
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::display() {
	if (consize == 0) {							//���� ��������� ����
		cout << "No data available\n";
	}
	else {
		for (int i = 0; i < consize; ++i) {		//������� ��� �������� ���������� �� �����
			cout << array[i] << endl;
		}
	}
}
template<class T>
void Keeper<T>::dataChange(int id) {
	try {
		if (consize == 0) {						//���� ��������� ����
			exception ex("No data available");
			throw ex;
		}
		if (id < 0 || id >= consize) {				//������������ ������
			exception ex("Invalid index");
			throw ex;
		}
		cin >> array[id];						//������ ����� ������ ���������� ��������
	}
	catch (exception& ex) {
		cout << ex.what() << endl;		//����� ������ �� �����
	}
}