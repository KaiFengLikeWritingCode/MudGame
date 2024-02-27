#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class Object:virtual public Entity
{
private:
	int value = -1;
	int style = -1; // 1武器 2防具 3消耗道具 4任务道具
	string introduce; // 道具介绍
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
	void init_style(int new_style); // 初始化装备类型
	int get_value();
	int get_style();
	string getIntroduce();
};