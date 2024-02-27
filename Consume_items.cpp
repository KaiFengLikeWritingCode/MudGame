#include "Consume_items.h"

int Consume_items::get_effect() { return effect; }
string Consume_items::get_consume_style() { return consume_style; }

void Consume_items::show_consume_items()
{
	cout << left << setw(10) << get_name() << setw(4) << "Ð§¹û:" << setw(5) << consume_style << "+" << setw(6) << effect << setw(4) << "½ð¶î: " << setw(6) << get_value() << endl;
}