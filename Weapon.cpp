#include "Weapon.h"

int Weapon::get_attack_power() { return attack_power; }
void Weapon::show_weapon()
{
	cout << left << setw(40) << get_name() << setw(7) << "������:" << setw(6) << attack_power << setw(4) << "���:" << setw(6) << get_value()
		<< endl;//<< "���ܣ�" << setw(30) << getIntroduce() << endl;
}