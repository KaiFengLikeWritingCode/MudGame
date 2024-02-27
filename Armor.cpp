#include "Armor.h"

int Armor:: get_defensive_power() { return defensive_power; }
int Armor::get_evasion() { return defensive_power; }
void Armor::show_armor()
{
	cout << left << setw(16) << get_name() << setw(7) << "·ÀÓùÁ¦£º" << setw(6) << defensive_power << setw(7) << "ÉÁ±Ü:" << setw(6) << evasion << setw(4) << "½ð¶î:" << setw(6) << get_value() << endl
		<< /*"½éÉÜ£º" << getIntroduce() << */endl;
}