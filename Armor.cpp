#include "Armor.h"

int Armor:: get_defensive_power() { return defensive_power; }
int Armor::get_evasion() { return defensive_power; }
void Armor::show_armor()
{
	cout << left << setw(16) << get_name() << setw(7) << "��������" << setw(6) << defensive_power << setw(7) << "����:" << setw(6) << evasion << setw(4) << "���:" << setw(6) << get_value() << endl
		<< /*"���ܣ�" << getIntroduce() << */endl;
}