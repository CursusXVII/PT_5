#include "PrintedEdition.h"

void PrintedEdition::add�ompositions(string name) {		//���������� ���������� � ������
	�ompositions* tmp = new �ompositions;
	tmp->name = name;
	if (head == NULL)
		head = tmp;
	else {
		tmp->next�ompositions = head;
		head = tmp;
	}
	++count�ompositions;
}