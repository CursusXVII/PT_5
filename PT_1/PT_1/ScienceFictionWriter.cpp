#include "ScienceFictionWriter.h"
ScienceFictionWriter::ScienceFictionWriter() {
	cout << "The Poet constructor is called\n";
	Fullname = "Not found";
	films = "Not found";
	head = NULL;
	countÑompositions = 0;
}
ScienceFictionWriter::ScienceFictionWriter(const ScienceFictionWriter& other) {
	cout << "The Poet copy constructor is called\n";
	this->countÑompositions = 0;
	*this = other;
}
ScienceFictionWriter::~ScienceFictionWriter() {
	cout << "The Poet destructor is called\n";
	Ñompositions* current = head;
	for (int i = 0; i < countÑompositions; ++i) {
		head = head->nextÑompositions;
		delete current;
		current = head;
	}
}
ofstream& operator<<(ofstream& fout, ScienceFictionWriter& obj) {							//ïåğåãğóçêà îïåğàòîğà çàïèñè â ôàéë
	fout << obj.Fullname << " " << obj.films << " " << obj.countÑompositions << endl;
	Ñompositions* current = obj.head;
	for (int i = 0; i < obj.countÑompositions; ++i) {
		fout << current->name << " ";
		current = current->nextÑompositions;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, ScienceFictionWriter& obj) {							//ïåğåãğóçêà îïåğàòîğà ÷òåíèÿ èç ôàéëà
	int count;
	fin >> obj.Fullname >> obj.films >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;
		obj.addÑompositions(name);
	}
	return fin;
}
ostream& operator<<(ostream& out, ScienceFictionWriter& obj) {								//ïåğåãğóçêà îïåğàòîğà âûâîäà íà êîíñîëü
	out << "Full_name: " << obj.Fullname << endl;
	out << "Movies based on books: " << obj.films << endl;
	out << "Number of compositions: " << obj.countÑompositions << endl;
	Ñompositions* current = obj.head;
	for (int i = 0; i < obj.countÑompositions; ++i) {
		out << "Composition " << i + 1 << " : " << current->name << endl;
		current = current->nextÑompositions;
	}
	return out;
}
istream& operator >> (istream& in, ScienceFictionWriter& obj) {							//ïåğåãğóçêà îïåğàòîğà ÷òåíèÿ ñ êëàâèàòóğû
	cout << "Enter the data\n";
	cout << "Full_name: ";
	cin >> obj.Fullname;
	cout << "Are there films based on books: ";
	cin >> obj.films;
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
ScienceFictionWriter& ScienceFictionWriter::operator=(const ScienceFictionWriter& other) {						//ïåğåãğóçêà îïåğàòîğà ïğèñâàèâàíèÿ
	this->Fullname = other.Fullname;
	this->films = other.films;
	Ñompositions* current = this->head;											//óêàçàòåëü íà ñïèñîê ïğîèçâåäåíèé îáúåêòà
	for (int i = 0; i < this->countÑompositions; ++i) {
		head = head->nextÑompositions;
		delete current;
		current = head;
	}
	this->countÑompositions = 0;												//îáíóëåíèå ñïèñêà
	current = other.head;
	for (int i = 0; i < other.countÑompositions; ++i) {
		this->addÑompositions(current->name);
		current = current->nextÑompositions;
	}
	return *this;
}