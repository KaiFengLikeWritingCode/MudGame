#pragma once
#include "Weapon.h"
#include "Armor.h"
#include "Consume_items.h"
#include "Quest_Items.h"
#include "leader.h"

using namespace std;

class Store
{
private:
	int store_weapon_size = 0;
	int store_armor_size = 0;
	int store_consume_size = 0;
	vector<Weapon> store_weapon;
	vector<Armor> store_armor;
	vector<Consume_items> store_consume_items;
public:
	Store()
	{
		store_weapon.resize(15);
		store_armor.resize(15);
		store_consume_items.resize(15);
	}
	Store(Weapon *weapon, Armor *armor, Consume_items *consume_items, int weapon_size, int armor_size, int consume_size):store_weapon_size(weapon_size),store_armor_size(armor_size),store_consume_size(consume_size)
	{
		store_weapon.resize(15);
		store_armor.resize(15);
		store_consume_items.resize(15);
		for (int i = 0; i < weapon_size && weapon[i].get_name() != "NULL"; i++)
		{
			store_weapon[i] = weapon[i];
		}
		for (int i = 0; i < armor_size && armor[i].get_name() != "NULL"; i++)
		{
			store_armor[i] = armor[i];
		}
		for (int i = 0; i < consume_size/* && store_consume_items[i].get_name() != "NULL"*/; i++)
		{
			store_consume_items[i] = consume_items[i];
		}
	}
	void store_show();
	// choose1  1: weapon 2: armor 3: consume_items
	// 0 购买失败  1 购买成功
	int buy(Leader& player, int choose1, int choose2); // choose1 买的道具类型， choose2 买的第几个
	int sell(Leader& player); // 

};