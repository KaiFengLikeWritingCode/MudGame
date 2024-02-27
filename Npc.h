#pragma once

// NPC
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consume_items.h"
#include "Quest_Items.h"
#include "Leader.h"



using namespace std;

class Npc : public Character
{
private:
	string introduction; // 人物简介
	string common_words[22]; // 正常谈话-》 接受任务后开启有关任务内容的谈话  common_words[0]作为 middle_words
	string task_words[22]; // 任务谈话
	//string middle_words;
	Object* goods_need;
	Object* award;
	double money, exp;
	double flag = 0; // 0 未接收任务， 0.5  接受任务但未完成 ， 1 完成任务
public:
	//double get_flag() { return flag; }

	Npc(string name, int id, int HP, int MP, int strength, int agility, int intelligence, string *common,int common_len, string *task, int task_len/*, string middle_words*/, string introduce, double money, double exp) : Entity(name, id), Character(name, id, HP, MP, strength, agility, intelligence), introduction(introduce), money(money), exp(exp)/*, middle_words(middle_words)*/
	{
		for (int i = 0; i < 22; i++)
		{
			common_words[i] = "NULL";
			task_words[i] = "NULL";
		}	

		for (int i = 0; i < common_len; i++)
		{
			common_words[i] = *(common + i);
		}
		for (int i = 0; i < task_len; i++)
		{
			task_words[i] = *(task + i);
		}
		goods_need = NULL;
		award = NULL;
	}
	~Npc()
	{
		delete goods_need;
		delete award;
	}
	Npc()
	{ 
		introduction = "NULL";
		for (int i = 0; i < 22; i++) 
		{ 
			common_words[i] = "NULL"; 
			task_words[i] = "NULL";
		}
		goods_need = NULL;
		award = NULL;
		money = 0;
		exp = 0;
	}
	Npc(const Npc& p)
	{
		introduction = p.introduction;
		for (int i = 0; i < 22; i++)
		{
			common_words[i] = p.common_words[i];
			task_words[i] = p.task_words[i];
		}
		goods_need = new Object(*goods_need);
		award = new Object(*award);
	}

	void init_npc_goods_award(Object* new_goods_need, Object* new_award);
	double common_talk(Leader& player/*, Task* game_task, int task_idx*/);
	int task_words_talk(Leader& major_role);
	void change_common_words(string* new_common_words, int common_len);
	void change_task_words(string* new_task_words, int task_len);

	int judge_task(Leader& major_role);
	double get_flag(); // 判断是否完成任务
	void setFlag(double tmpFlag);
	string get_introduce();
	void show_task();
};