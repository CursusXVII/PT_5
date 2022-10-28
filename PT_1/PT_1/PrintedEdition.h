#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

struct Ñompositions {							//ñïèñîê ïğîèçâåäåíèé
	string name;
	Ñompositions* nextÑompositions;
};
class PrintedEdition {
protected:				
	string Fullname;
	Ñompositions* head;					
	int countÑompositions;						//êîëè÷åñòâî 
	void addÑompositions(string name);			//äîáàâëåíèå 
public:
	PrintedEdition() { 
		cout << "The Printed Edition constructor is called\n"; 
	}
	virtual ~PrintedEdition() { 
		cout << "PrintedEdition destructor called\n";
	}
	virtual void setFIO(string) = 0;			//×èñòûå âèğòóàëüíûå ôóíêöèè
	virtual string getFIO() = 0;
};