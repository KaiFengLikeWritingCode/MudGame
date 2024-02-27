#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Weapon: public Object
{
private:
	int attack_power = 0;
public:
	Weapon(string name, int id, int value, string introduce, int attack_power) : Entity(name, id), Object(name, id, value, introduce), attack_power(attack_power) { init_style(1); } // ?
	Weapon() { init_style(1); }
	//Weapon(const Weapon& p)
	//{
	//	attack_power = p.attack_power;
	//}
	Weapon(const Object& p):Object(p){ } // ??
	Weapon& operator=(const Weapon& p)
	{
		if (this != &p)
		{
			Object::operator=(p);
			attack_power = p.attack_power;
		}
		return *this;
	}
	int get_attack_power();
	void show_weapon();
	void setPower(int power) { attack_power = power; }
};