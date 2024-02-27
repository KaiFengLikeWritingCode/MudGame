#pragma once

// 消耗道具
#include "Object.h"

using namespace std;

class Consume_items : public Object
{
private:
	string consume_style = "NULL"; // HP ， MP， strength， agility， intelligence
	int effect = -1; // 消耗药品的效果
public:
	int get_effect();
	string get_consume_style();
	Consume_items(string name, int id, int value, string introduce, int effect, string consume_style) : Entity(name, id), Object(name, id, value, introduce), effect(effect), consume_style(consume_style) { init_style(3); } // ?
	Consume_items() { init_style(3); }
	Consume_items(const Object& p) :Object(p) { } // ??
	Consume_items& operator=(const Consume_items& p)
	{
		if (this != &p)
		{
			consume_style = p.consume_style;
			effect = p.effect;
			Object::operator=(p);
		}
		return *this;
	}
	void show_consume_items(); // 显示消耗品属性
	string getConsumeStyle() { return consume_style; };
	int getEffect() { return effect; };
	void setConsumeStyle(string cs) { consume_style = cs; };
	void setEffect(int e) { effect = e; };
};