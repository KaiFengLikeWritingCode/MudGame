#include "Character.h"

int Character::get_HP() { return HP; }
int Character::get_Mp() { return MP; }
int Character::get_strength() { return strength; }
int Character::get_agilty() { return agility; }
int Character::get_intelligence() { return intelligence; }



void Character::change_attribute(int add_HP, int add_MP, int add_strength, int add_agilty, int add_intelligence) // 改变角色属性--主角用（也可以放在Leader.h里）
{
	HP += add_HP;
	MP += add_MP;
	strength += add_strength;
	agility += add_agilty;
	intelligence += add_intelligence;
}
void Character::change_hp_mp(int hp, int mp)
{
	HP += hp;
	MP += mp;
}