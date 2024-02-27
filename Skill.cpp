#include "Skill.h"


int Skill::get_style() { return skill_style; }
int Skill::get_effect() { return effect; }
int Skill::get_consume_mp() { return consume_mp; }
int Skill::get_last_round() { return last_round; }

void Skill::init_skill(string _name, int _id, string _introduce, int _skill_style, int _effect, int _consume_mp, int _last_round)
{
	change_name(_name);
	change_id(_id);
	introduce = _introduce;
	skill_style = _skill_style;
	effect = _effect;
	consume_mp = _consume_mp;
	last_round = _last_round;
}
void Skill::show_skill()
{
	cout << get_name() << endl;
}