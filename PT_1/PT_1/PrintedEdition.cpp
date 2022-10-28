#include "PrintedEdition.h"

void PrintedEdition::add—ompositions(string name) {		//ƒÓ·‡‚ÎÂÌËÂ ÔÓËÒıÓ‰ËÚ ‚ Ì‡˜‡ÎÓ
	—ompositions* tmp = new —ompositions;
	tmp->name = name;
	if (head == NULL)
		head = tmp;
	else {
		tmp->next—ompositions = head;
		head = tmp;
	}
	++count—ompositions;
}