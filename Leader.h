#pragma once


// ����
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consume_items.h"
#include "Quest_Items.h"
#include "Skill.h"
//#include "Antagonist.h"


using namespace std;

class Leader: public Character
{
private:
	int exp, money, level; 
	int now_HP = 0, now_MP = 0, now_strength = 0, now_agility = 0, now_intelligence = 0; // ��ǰ״̬ ��������Ļ�Ӧ�ð���ǰ״̬��һ��
	int temp_strength = 0, temp_agility = 0, temp_intelligence = 0; // ��ʱ����Ĵ�С��������ʱ�����֮���ȥ�����¼���
	int upgrade_exp[99]; // 1 �� 99 �������辭��

public:
	//vector<Weapon> leader_weapon;
	Weapon leader_weapon[15];
	int leader_weapon_size = 0;
	//vector<Armor> leader_armor;
	Armor leader_armor[15];
	int leader_armor_size = 0;
	//vector<Consume_items> leader_consume_items;
	Consume_items leader_consume_items[15];
	int leader_consume_size = 0;
	//vector<Quest_Items> leader_quest_items;
	Quest_Items leader_quest_items[15];
	int leader_quest_size = 0;
	// ���ֲ������Ϳ��ܺ����ļ���ȡʱ����� ���еĻ��͸ĳ�����ģ�������
	//Object* leader_goods[30];  // ������Ĭ�����װ������15�� ����30ֻ��Ϊ�˷�ֹ����
	int equipment_count; // װ������
	map<string, int> have_goods;
	map<string, int> consume_map;

	Skill leader_skill[9] =
   {		// name  id    ����           ���� Ч�� mp �����غ�
		Skill("����",0 , "ûɶ�ɽ��ܵģ�" ,1, -20, 20,1),
		Skill(),
		Skill(),
		Skill(),
		Skill(),
		Skill(),
		Skill(),
		Skill(),
		Skill()
   };



public:
	Leader() = default;
	//Leader(string name, int id, int HP, int MP, int strength, int agility, int intelligence) : Entity(name, id), Character(name, id, HP, MP, strength, agility, intelligence);
	Leader(string name, int id, int HP, int MP, int strength, int agility, int intelligence) : Entity(name, id), Character(name, id, HP, MP, strength, agility, intelligence)
	{
		now_HP = HP, now_MP = MP, now_strength = strength, now_agility = agility, now_intelligence = intelligence;
		/*for (int i = 0; i < 15; i++) leader_goods[i] = NULL;*/
		//
		//leader_weapon.resize(15);
		//leader_armor.resize(15);
		//leader_consume_items.resize(15);
		//leader_quest_items.resize(15);

		//
		consume_map["HP"] = 1;
		consume_map["MP"] = 2;
		consume_map["strength"] = 3;
		consume_map["agility"] = 4;
		consume_map["intelligence"] = 5;

		money = 120;
		exp = 0;
		level = 1;
		for (int i = 0; i < 99; i++) { upgrade_exp[i] = pow(2, i - 1) * 10; }
		equipment_count = 0;
	}
	Leader(const Leader& p)
	{
		exp = p.exp;
		now_HP = p.now_HP;
		level = p.level;
		now_HP = p.now_HP;
		now_MP = p.now_MP;
		now_strength = p.now_strength;
		now_agility = p.now_agility;
		now_intelligence = p.now_intelligence;
		temp_strength = p.temp_strength;
		temp_agility = p.temp_agility;
		temp_intelligence = p.temp_intelligence;
		leader_weapon_size = p.leader_weapon_size;
		leader_armor_size = p.leader_armor_size;
		leader_consume_size = p.leader_consume_size;
		leader_quest_size = p.leader_quest_size;
		equipment_count = p.equipment_count;
		have_goods = p.have_goods;
		consume_map = p.consume_map;
		for (int i = 0; i < leader_weapon_size; i++)
		{
			leader_weapon[i] = p.leader_weapon[i];
		}
		for (int i = 0; i < leader_armor_size; i++)
		{
			leader_armor[i] = p.leader_armor[i];
		}
		for (int i = 0; i < leader_consume_size; i++)
		{
			leader_consume_size = p.leader_consume_size;
		}
		for (int i = 0; i < leader_quest_size; i++)
		{
			leader_quest_items[i] = p.leader_quest_items[i];
		}
		for (int i = 0; i < 9; i++)
		{
			leader_skill[i] = p.leader_skill[i];
		}
	}
	Leader& operator=(const Leader& p)
	{
		if (this != &p)
		{
			exp = p.exp;
			now_HP = p.now_HP;
			level = p.level;
			now_HP = p.now_HP;
			now_MP = p.now_MP;
			now_strength = p.now_strength;
			now_agility = p.now_agility;
			now_intelligence = p.now_intelligence;
			temp_strength = p.temp_strength;
			temp_agility = p.temp_agility;
			temp_intelligence = p.temp_intelligence;
			leader_weapon_size = p.leader_weapon_size;
			leader_armor_size = p.leader_armor_size;
			leader_consume_size = p.leader_consume_size;
			leader_quest_size = p.leader_quest_size;
			equipment_count = p.equipment_count;
			have_goods = p.have_goods;
			consume_map = p.consume_map;
			for (int i = 0; i < leader_weapon_size; i++)
			{
				leader_weapon[i] = p.leader_weapon[i];
			}
			for (int i = 0; i < leader_armor_size; i++)
			{
				leader_armor[i] = p.leader_armor[i];
			}
			for (int i = 0; i < leader_consume_size; i++)
			{
				leader_consume_size = p.leader_consume_size;
			}
			for (int i = 0; i < leader_quest_size; i++)
			{
				leader_quest_items[i] = p.leader_quest_items[i];
			}
			for (int i = 0; i < 9; i++)
			{
				leader_skill[i] = p.leader_skill[i];
			}
			Character::operator=(p);
		}
		return *this;
	}


	int getWeapon_size();
	int getArmor_size();
	void change_money(int _money);
	void change_exp(int _exp);

	void show_skill();
	int get_skill_size();
	int judge_poor_statue();
	void reply_statue(int consume_money);


	void use_skill(int skill_idx);
	int get_skill_style(int skill_idx);
	int get_skill_effect(int skill_idx);

	void display(); // չʾ��ɫ״̬

	
	int judge(string task_name); // �ж�������Ʒ�����Ƿ�ӵ��

	void leader_died();

	// ��ȡ��������֣���������̵깺��....) ��ͬ����ע�⴫��
	int add_equipment_other(Object* award, int award_money = 0, int award_exp = 0); // �����������Ĳ��ã� award����������/��ֽ���or�̵���Ʒ�� award_money ����������/��ֽ���or�̵껨�� 

	int judge_consume_if_empty();
	int use_consume_items(int consume_idx);

	int show_equip(int only_consume = 0);

	// ��ʱ���� or ״̬���� or debuff or ս��ʱ����
	int status_supplement(int add_HP = 0, int add_MP = 0, int add_strength = 0, int add_agilty = 0, int add_intelligence = 0);
	void status_supplement_end(); // ��ʱ�������
	
	void change_equipment(int change_idx, int style); // ��װ��
	void sell_equipment(int change_idx, int style);


	// ս��
	int leader_attack();// ����ս��ʱ��������װ���ľ����ϵ�����ٸ� , ����ͬ��;
	int leader_defence();
	int leader_evasion();

	int getExp();
	int getMoney();
	int getLevel();
	int getNowHP();
	int getNowMp();
	int getNowStrength();
	int getNowAgility();
	int getNowIntelligence();
	int getTempStrength();
	int getTempAgility();
	int getTempIntelligence();
	Weapon* getpWeapon();
	Armor* getpArmor();
	Weapon getWeapon(int idx);
	Armor getArmor(int idx);
	Consume_items* getpConsume_items();
	Quest_Items* getpQuest_items();
	Consume_items getConsume_items(int idx);
	Quest_Items getQuest_items(int idx);
	map<string, int> getGoods();
	map<string, int> getConsume_map();

	void setExp(int);
	void setMoney(int);
	void setLevel(int);
	void setNowHp(int);
	void setNowMp(int);
	void setNowStrength(int);
	void setNowAgility(int);
	void setNowIntelligence(int);
	void setTempStrength(int);
	void setTempAgility(int);
	void setTempIntelligence(int);
	void setWeapon(int idx, Weapon tmpWeapon);
	void setArmor(int idx, Armor tmpArmor);
	void setConsumeItems(int idx, Consume_items tmpConsumeItem);
	void setQuestItems(int idx, Quest_Items tmpQuestItems);
	void setHaveGood(map<string, int> tmp);
	void setConsumeMap(map<string, int> tmp);

	int getWeaponSize() { return leader_weapon_size; };
	int getArmorSize() { return leader_armor_size; };
	int getConsumeSize() { return leader_consume_size; };
	int getQuestSize() { return leader_quest_size; };

	void setWeaponSize(int ws) { leader_weapon_size = ws; };
	void setArmorSize(int as) { leader_armor_size = as; };
	void setConsumeSize(int cs) { leader_consume_size; };
	void setQuestSize(int qs) { leader_quest_size; };
};