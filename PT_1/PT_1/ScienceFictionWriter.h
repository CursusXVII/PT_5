#pragma once
#include "PrintedEdition.h"
class ScienceFictionWriter : public PrintedEdition {
	string films;
public:
	ScienceFictionWriter();
	ScienceFictionWriter(const ScienceFictionWriter& other);
	~ScienceFictionWriter();
	void setFIO(string Fullname) override { 
		this->Fullname = Fullname; 
	}
	string getFIO() override { 
		return Fullname; 
	}
	friend ofstream& operator << (ofstream& fout, ScienceFictionWriter& obj);
	friend ifstream& operator >> (ifstream& fin, ScienceFictionWriter& obj);
	friend ostream& operator << (ostream& out, ScienceFictionWriter& obj);
	friend istream& operator >> (istream& in, ScienceFictionWriter& obj);
	ScienceFictionWriter& operator =(const ScienceFictionWriter& other);
};