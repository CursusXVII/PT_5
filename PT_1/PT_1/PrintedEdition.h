#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

struct �ompositions {							//������ ������������
	string name;
	�ompositions* next�ompositions;
};
class PrintedEdition {
protected:				
	string Fullname;
	�ompositions* head;					
	int count�ompositions;						//���������� 
	void add�ompositions(string name);			//���������� 
public:
	PrintedEdition() { 
		cout << "The Printed Edition constructor is called\n"; 
	}
	virtual ~PrintedEdition() { 
		cout << "PrintedEdition destructor called\n";
	}
	virtual void setFIO(string) = 0;			//������ ����������� �������
	virtual string getFIO() = 0;
};