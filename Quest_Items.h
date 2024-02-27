#pragma once
// 任务道具
#include "Object.h"

using namespace std;

class Quest_Items :public Object
{
public:
	Quest_Items() { init_style(4); }
	Quest_Items(string name, int id, int value, string introduce): Entity(name, id), Object(name, id, value, introduce){ init_style(4); } // ?
	Quest_Items(const Object& p) : Object(p) { }
	Quest_Items& operator=(const Quest_Items& p)
	{
		if (this != &p)
		{
			Object::operator=(p);
		}
		return *this;
	}
	void show_quest_items();
};