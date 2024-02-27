#pragma once

// 敌人
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consume_items.h"
#include "Quest_Items.h"
#include "Leader.h"



using namespace std;

class Antagonist : public Character
{
private:
	string introduction; // 人物简介
	//string common_words[15]; // 正常谈话-》 接受任务后开启有关任务内容的谈话
	string common_words; 
	int now_HP = 0, now_MP = 0, now_strength = 0, now_agility = 0, now_intelligence = 0; // 当前状态 ！！计算的话应该按当前状态好一点
	Object* award; // 敌人掉落道具
	int money,  exp; // 掉落钱、 经验
public:

	Antagonist(string name, int id, int HP, int MP, int strength, int agility, int intelligence, string common, int common_len, int money, int exp, string introduce) : Entity(name, id), Character(name, id, HP, MP, strength, agility, intelligence), money(money), exp(exp), introduction(introduce)
	{
		now_HP = HP, now_MP = MP, now_strength = strength, now_agility = agility, now_intelligence = intelligence;
		common_words = common;
		award = NULL;
	}
	void show_introduce();  // 展示介绍
	string get_introduce();

	Antagonist();
	Antagonist(const Antagonist& p);

	~Antagonist() { delete award; }


	void init_Antagonist_award(Object* new_award);

	void common_talk();
	void defeated(Leader& major_role); // defeated 被击败
	int attacked(Leader& major_role, int attack_HP) ; // 收到攻击
	int enemy_attack();  // 攻击

	int enemy_evasion();    // 获取敏捷

	void enemy_skilled(int skill_style, int effect);  // 收到技能伤害
};