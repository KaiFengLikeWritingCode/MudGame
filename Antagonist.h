#pragma once

// ����
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
	string introduction; // ������
	//string common_words[15]; // ����̸��-�� ������������й��������ݵ�̸��
	string common_words; 
	int now_HP = 0, now_MP = 0, now_strength = 0, now_agility = 0, now_intelligence = 0; // ��ǰ״̬ ��������Ļ�Ӧ�ð���ǰ״̬��һ��
	Object* award; // ���˵������
	int money,  exp; // ����Ǯ�� ����
public:

	Antagonist(string name, int id, int HP, int MP, int strength, int agility, int intelligence, string common, int common_len, int money, int exp, string introduce) : Entity(name, id), Character(name, id, HP, MP, strength, agility, intelligence), money(money), exp(exp), introduction(introduce)
	{
		now_HP = HP, now_MP = MP, now_strength = strength, now_agility = agility, now_intelligence = intelligence;
		common_words = common;
		award = NULL;
	}
	void show_introduce();  // չʾ����
	string get_introduce();

	Antagonist();
	Antagonist(const Antagonist& p);

	~Antagonist() { delete award; }


	void init_Antagonist_award(Object* new_award);

	void common_talk();
	void defeated(Leader& major_role); // defeated ������
	int attacked(Leader& major_role, int attack_HP) ; // �յ�����
	int enemy_attack();  // ����

	int enemy_evasion();    // ��ȡ����

	void enemy_skilled(int skill_style, int effect);  // �յ������˺�
};