#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

template <class T> 
class Keeper {
	T* array;						//Указатель на элементы массива
	int consize;					//Размер контейнера
public:
	Keeper();
	Keeper(const Keeper&);
	~Keeper();
	void add(int index);			//Добавление 
	void deleteE(int index);		//Удаление 
	void writeToFile(string);		//Запись в файл
	void authorsLink(string);			//восстановление файла
	void readFromFile(string);		//Чтение из файла
	void display();					//Вывод 
	void dataChange(int index);		//Изменение
};
template<class T>
Keeper<T>::Keeper() {
	cout << "The default Keeper constructor is called\n";
	array = nullptr;
	consize = 0;
}
template<class T>
Keeper<T>::Keeper(const Keeper& other) {
	this->array = new T[other.consize];		//Создаем массив
	this->consize = other.consize;				//Копируем размер
	for (int i = 0; i < consize; ++i)			//Копируем каждый элемент в новый объект
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
		T* tmp = new T[consize + 1];				//Создаем новый массив на один элемент больше контейнера
		int j = 0;
		for (int i = 0; i < consize; ++i) {		//Копируем все элементы в новый массив
			if (index == i)						//Если индекс равен введенному значению, то пропускаем 
				j++;
			tmp[j++] = array[i];				//помещается элемент, затем индекс возрастает
		}
		delete[] array;						//Удаляем старый массив
		array = tmp;							//указатель на новый массив
		cin >> array[index];					//Вводим данные добавленного элемента, который находится под индексом index
		++consize;									//Увеличиваем размер контейнера
		cout << "\nNew item successfully added\n";
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::deleteE(int index) {
	try {
		if (consize == 0) {							//проверка на пустоту в контейнере
			exception ex("Nothing to delete");
			throw ex;
		}
		if (index < 0 || index >= consize) {		//проверка на корректность индекса
			exception ex("Invalid index");
			throw ex;
		}
		T* tmp = new T[consize - 1];				//Создаем новый массив на один элемент меньше контейнера
		int j = 0;
		for (int i = 0; i < consize; ++i) {			//Копируем все элементы, кроме того, который нужно удалить
			if (index != i)
				tmp[j++] = array[i];
		}
		delete[] array;							//Удаляем старый массив
		array = tmp;								//ptr указывает на новый массив
		--consize;									//Размер контейнера уменьшился
		cout << "\nItem removed\n";
	}
	catch (exception& ex) {
		cout << ex.what() << endl;					//Вывод ошибки на экран
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
		fout << consize << endl;					//Запись размера контейнера
		for (int i = 0; i < consize; ++i) {			//Запись всех элементов контейнера
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
		delete[] array;							//Очищаем массив, так как будут записаны данные из файла
		fin >> consize;							//Считываем размер контейнера в файле
		array = new T[consize];					//Создаем массив размером контейнера в файле
		for (int i = 0; i < consize; ++i) {		//Считываем все элементы из файла
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
	if (consize == 0) {							//Если контейнер пуст
		cout << "No data available\n";
	}
	else {
		for (int i = 0; i < consize; ++i) {		//Выводим все элементы контейнера на экран
			cout << array[i] << endl;
		}
	}
}
template<class T>
void Keeper<T>::dataChange(int id) {
	try {
		if (consize == 0) {						//Если контейнер пуст
			exception ex("No data available");
			throw ex;
		}
		if (id < 0 || id >= consize) {				//Некорректный индекс
			exception ex("Invalid index");
			throw ex;
		}
		cin >> array[id];						//Вводим новые данные выбранного элемента
	}
	catch (exception& ex) {
		cout << ex.what() << endl;		//Вывод ошибки на экран
	}
}