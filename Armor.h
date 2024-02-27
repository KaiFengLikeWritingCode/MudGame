#pragma once
// ����
#include <iostream>
#include "Object.h"

using namespace std;

class Armor : public Object 
{
private:
	int defensive_power = 0;  // ������
	int evasion = 0; // ����
public:
	int get_defensive_power(); // ��÷�������
	int get_evasion();  // ��ȡ����
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
	void show_armor();  // չʾ������Ϣ
	void setPower(int power) { defensive_power = power;  /*cout << defensive_power << endl; system("pause"); */}
};