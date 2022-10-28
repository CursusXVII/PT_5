#pragma once
#include "PrintedEdition.h"
class Novelist : public PrintedEdition {
	string years_of_life;
	string biography;
public:
	Novelist();
	Novelist(const Novelist& other);
	~Novelist();
	void setFIO(string Fullname) override { 
		this->Fullname = Fullname; 
	}
	string getFIO() override { 
		return Fullname; 
	}
	friend ofstream& operator << (ofstream& fout, Novelist& obj);
	friend ifstream& operator >> (ifstream& fin, Novelist& obj);
	friend ostream& operator << (ostream& out, Novelist& obj);
	friend istream& operator >> (istream& in, Novelist& obj);
	Novelist& operator =(const Novelist& other);
};