#include "Novelist.h"
Novelist::Novelist() {
	cout << "The Novelist constructor is called\n";
	Fullname = "Not found";
	biography = "Not found";
	years_of_life = "Not found";
	head = NULL;
	countÑompositions = 0;
}
Novelist::Novelist(const Novelist& other) {
	cout << "The Novelist copy constructor is calledt\n";
	this->countÑompositions = 0;
	*this = other;
}
Novelist::~Novelist() {
	cout << "The Novelist destructor is called\n";
	Ñompositions* current = head;
	for (int i = 0; i < countÑompositions; ++i) {
		head = head->nextÑompositions;
		delete current;
		current = head;
	}
}
ofstream& operator<<(ofstream& fout, Novelist& obj) {					//ïåğåãğóçêà îïåğàòîğà çàïèñè â ôàéë
	fout << obj.Fullname << " " << obj.years_of_life << " " << obj.biography << " " << obj.countÑompositions << endl;
	Ñompositions* current = obj.head;
	for (int i = 0; i < obj.countÑompositions; ++i) {
		fout << current->name << " ";
		current = current->nextÑompositions;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Novelist& obj) {					//ïåğåãğóçêà îïåğàòîğà ÷òåíèÿ èç ôàéëà
	int count;
	fin >> obj.Fullname >> obj.years_of_life >> obj.biography >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;
		obj.addÑompositions(name);
	}
	return fin;
}
ostream& operator<<(ostream& out, Novelist& obj) {						//ïåğåãğóçêà îïåğàòîğà âûâîäà íà êîíñîëü
	out << "Full_name: " << obj.Fullname << endl;
	out << "Years of life: " << obj.years_of_life << endl;
	out << "Brief biography: " << obj.biography << endl;
	out << "Number of compositions: " << obj.countÑompositions << endl;
	Ñompositions* current = obj.head;
	for (int i = 0; i < obj.countÑompositions; ++i) {
		out << "Composition " << i + 1 << " : " << current->name << endl;
		current = current->nextÑompositions;
	}
	return out;
}
istream& operator >> (istream& in, Novelist& obj) {						//ïåğåãğóçêà îïåğàòîğà ÷òåíèÿ ñ êëàâèàòóğû
	cout << "Enter the data\n";
	cout << "Full_name: ";
	cin >> obj.Fullname;
	cout << "Years of life: ";
	cin >> obj.years_of_life;
	cout << "Brief biography: ";
	cin >> obj.biography;
	Ñompositions* current = obj.head;
	for (int i = 0; i < obj.countÑompositions; ++i) {
		obj.head = obj.head->nextÑompositions;
		delete current;
		current = obj.head;
	}
	obj.countÑompositions = 0;
	string name;
	int count;
	cout << "Number of compositions: ";
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cout << "Enter " << i + 1 << " composition: ";
		cin >> name;
		obj.addÑompositions(name);
	}
	return in;
}
Novelist& Novelist::operator=(const Novelist& other) {					//ïåğåãğóçêà îïåğàòîğà ïğèñâàèâàíèÿ
	this->Fullname = other.Fullname;
	this->years_of_life = other.years_of_life;
	this->biography = other.biography;
	Ñompositions* current = this->head;									//óêàçàòåëü íà ñïèñîê ïğîèçâåäåíèé îáúåêòà
	for (int i = 0; i < this->countÑompositions; ++i) {
		head = head->nextÑompositions;
		delete current;
		current = head;
	}
	this->countÑompositions = 0;										//îáíóëåíèå ñïèñêà
	current = other.head;
	for (int i = 0; i < other.countÑompositions; ++i) {
		this->addÑompositions(current->name);
		current = current->nextÑompositions;
	}
	return *this;
}