#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class Object:virtual public Entity
{
private:
	int value = -1;
	int style = -1; // 1���� 2���� 3���ĵ��� 4�������
	string introduce; // ���߽���
public:
	Object() { }
	Object(string name, int id, int value, string introduce) : Entity(name, id), value(value),introduce(introduce) { }
	Object(const Object& p)
	{
		value = p.value;
		style = p.style;
		introduce = p.introduce;
	}
	Object& operator=(const Object& p)
	{
		if (this != &p)
		{
			value = p.value;
			style = p.style;
			Entity::operator=(p);
		}
		return *this;
	}
	
	void setValue(int _value) { value = _value; }
	void setStyle(int _style) { style = _style; }
	void setIntroduce(string _introduce) { introduce = _introduce; }
	void init_style(int new_style); // ��ʼ��װ������
	int get_value();
	int get_style();
	string getIntroduce();
};