#include "Weapon.h"

int Weapon::get_attack_power() { return attack_power; }
void Weapon::show_weapon()
{
	cout << left << setw(40) << get_name() << setw(7) << "¹¥»÷Á¦:" << setw(6) << attack_power << setw(4) << "½ð¶î:" << setw(6) << get_value()
		<< endl;//<< "½éÉÜ£º" << setw(30) << getIntroduce() << endl;
}