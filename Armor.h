#pragma once
// 防具
#include <iostream>
#include "Object.h"

using namespace std;

class Armor : public Object 
{
private:
	int defensive_power = 0;  // 防御力
	int evasion = 0; // 闪避
public:
	int get_defensive_power(); // 获得防御属性
	int get_evasion();  // 获取闪避
	Armor(string name, int id, int value, string introduce, int defensive_power,int evasion) : Entity(name, id), Object(name, id, value, introduce), defensive_power(defensive_power), evasion(evasion){ init_style(2); } // 
	Armor(){ init_style(2); }
	Armor(const Object& p) :Object(p) { } // ??
	Armor& operator=(const Armor& p)
	{
		if (this != &p)
		{	
			defensive_power = p.defensive_power;
			evasion = p.evasion;
			Object::operator=(p);
		}

		return *this;
	}
	void show_armor();  // 展示防具信息
	void setPower(int power) { defensive_power = power;  /*cout << defensive_power << endl; system("pause"); */}
};