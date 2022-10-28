#pragma once
#include "PrintedEdition.h"
class Poet : public PrintedEdition {
	string years;
public:
	Poet();
	Poet(const Poet& other);
	~Poet();
	void setFIO(string Fullname) override {
		this->Fullname = Fullname; 
	}
	string getFIO() override { 
		return Fullname; 
	}
	friend ofstream& operator << (ofstream& fout, Poet& obj);
	friend ifstream& operator >> (ifstream& fin, Poet& obj);
	friend ostream& operator << (ostream& out, Poet& obj);
	friend istream& operator >> (istream& in, Poet& obj);
	Poet& operator =(const Poet& other);
};