#pragma once
#include "Entity.h"

using namespace std;

class Character: virtual public Entity
{
private:
	int HP = 0, MP = 0, strength = 0, agility = 0, intelligence = 0; 
	//  血		蓝条	    力			敏捷			智慧
 
public:
	int get_HP();
	int get_Mp();
	int get_strength();
	int get_agilty();
	int get_intelligence();
	Character(string name, int id, int HP,int MP,int strength,int agility,int intelligence) : Entity(name, id), HP(HP), MP(MP), strength(strength), agility(agility), intelligence(intelligence) { } // ?	
	Character() { }
	Character(const Character& p)
	{
		HP = p.HP;
		MP = p.MP;
		strength = p.strength;
		agility = p.agility;
		intelligence = p.intelligence;
	}
	Character& operator=(const Character& p)
	{
		if (this != &p)
		{
			HP = p.HP;
			MP = p.MP;
			strength = p.MP;
			agility = p.agility;
			intelligence = p.intelligence;
			Entity::operator=(p);
		}
		return *this;
	}

	void change_attribute(int add_HP, int add_MP, int add_strength, int add_agilty, int add_intelligence); // 改变角色属性--主角用（也可以放在Leader.h里）
	void change_hp_mp(int hp, int mp);  // 改变hp,mp
	int getHP() { return HP; };		
	int getMP() { return MP; };
	int getStrength() { return strength; };
	int getAgility() { return agility; };
	int getIntelligence() { return intelligence; };
	void setHP(int _HP) { HP = _HP; }; // 重置血
	void setMP(int _MP) { MP = _MP; }; // 重置血
	void setStrength(int _strength) { strength = _strength; };
	void setAgility(int _agility) { agility = _agility; };
	void setIntelligence(int _intelligence) { intelligence = _intelligence; };
};