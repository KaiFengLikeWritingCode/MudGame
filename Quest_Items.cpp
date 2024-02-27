#include "Quest_Items.h"

void Quest_Items::show_quest_items()
{
	cout << left << setw(15) << get_name() << setw(4) << "¼ÛÖµ:" << setw(6) << get_value() << endl;
}