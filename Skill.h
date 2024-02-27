#pragma once
#include <iostream>
#include "Entity.h"


using namespace std;

class Skill: public Entity
{
private:
	string introduce;
	int skill_style; // 消耗MP-》1 sp技能 2.物理技能 攻击
	int effect;
	int consume_mp;
	int last_round = 0;
public:

	Skill(string name, int id, string introduce, int skill_style, int effect, int comsume_mp, int last_round) : Entity(name, id), introduce(introduce), skill_style(skill_style), effect(effect), consume_mp(consume_mp), last_round(last_round) {}
	Skill()
	{
		introduce = "NULL";
		skill_style = -1;
		effect = -1;
		consume_mp = -1;
		last_round = -1;
	}
	int get_style();
	int get_effect();
	int get_consume_mp();
	int get_last_round();


	void init_skill(string _name, int _id, string _introduce, int _skill_style, int _effect, int _consume_mp, int _last_round);
	void show_skill();
};
