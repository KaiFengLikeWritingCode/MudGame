#include"Leader.h"




//Leader::Leader(string name, int id, int HP, int MP, int strength, int agility, int intelligence) : Entity(name, id), Character(name, id, HP, MP, strength, agility, intelligence)
//{
//	now_HP = HP, now_MP = MP, now_strength = strength, now_agility = agility, now_intelligence = intelligence;
//	/*for (int i = 0; i < 15; i++) leader_goods[i] = NULL;*/
//	//
//	//leader_weapon.resize(15);
//	//leader_armor.resize(15);
//	//leader_consume_items.resize(15);
//	//leader_quest_items.resize(15);
//
//	//
//	consume_map["HP"] = 1;
//	consume_map["MP"] = 2;
//	consume_map["strength"] = 3;
//	consume_map["agility"] = 4;
//	consume_map["intelligence"] = 5;
//
//	money = 120;
//	exp = 0;
//	level = 1;
//	for (int i = 0; i < 99; i++) { upgrade_exp[i] = pow(2, i - 1) * 10; }
//	equipment_count = 0;
//}





int Leader::getWeapon_size() { return leader_weapon_size; }
int Leader::getArmor_size() { return leader_armor_size; }
void Leader::change_money(int _money) { money += _money; }
void Leader::change_exp(int _exp) { exp += _exp; }

void Leader::show_skill()
{
	for (int i = 0; i < level; i++)
	{
		cout << i + 1 << ": ";
		leader_skill[i].show_skill();

	}
}
int Leader::get_skill_size()
{
	return level;
}
int Leader::judge_poor_statue()
{
	return now_HP < get_HP() || now_MP < get_Mp();
}
void Leader::reply_statue(int consume_money)
{
	now_HP = get_HP();
	now_MP = get_Mp();
	money -= consume_money;
}


void Leader::use_skill(int skill_idx)
{
	now_MP -= leader_skill[skill_idx].get_consume_mp();
}
int Leader::get_skill_style(int skill_idx)
{
	return leader_skill[skill_idx].get_style();
}
int Leader::get_skill_effect(int skill_idx)
{
	return leader_skill[skill_idx].get_effect();
}



void Leader::display() // 展示角色状态
{

	cout << "\033[32m"<<"当前人物属性：" << endl << "姓名：" << get_name() << "   \t\t  等级：" << getLevel();
	printf("\t  当前经验/升级所需经验：【%d/%d】\n", exp, upgrade_exp[level - 1]);
	printf("HP:%d/%d		  MP:%d/%d", now_HP, get_HP(), now_MP, get_Mp());
	cout << "\t  " << "校园卡余额：" << money << endl;
	/*printf("力量+（[de]buff）：%d(+ %d)		敏捷：%d(+ %d)		智力：%d(+ %d)\n", get_strength(),temp_strength, get_agilty(),temp_agility, get_intelligence(),temp_intelligence);*/
	printf("力量+（[de]buff）：%d(+ %d)\n敏捷：%d(+ %d)\n智力：%d(+ %d)\n", get_strength(), temp_strength, get_agilty(), temp_agility, get_intelligence(), temp_intelligence);
	//cout /*<< setw(15)*/ << "校园卡余额：" << money;
	cout << "装备：" << "*武器：" << leader_weapon[0].get_name() << "  伤害+" << leader_weapon[0].get_attack_power() << endl;
	cout << "      *防具：" << leader_armor[0].get_name() << "  护甲+" << leader_armor[0].get_defensive_power() << "  闪避-" << leader_armor[0].get_evasion() <<"\033[0m"<< endl;


}


int Leader::judge(string task_name) // 判断任务物品主角是否拥有
{
	return have_goods[task_name];
}
void Leader::leader_died()
{
	if (level > 1)
	{
		level--;
		change_hp_mp(-10, -10);
	}
	now_HP = get_HP();
	now_MP = get_Mp();
	money = money / 2;
}

// 获取奖励（打怪，完成任务，商店购买....) 不同场景注意传参
int Leader::add_equipment_other(Object* award, int award_money , int award_exp ) // 这里的名字起的不好， award可以是任务/打怪奖励or商店物品； award_money 可以是任务/打怪奖励or商店花费 
{
	string awards_name = award->get_name(); //传参可能冗余了， 不改了，先姑且这样 -- 已改
	int goods_style = award->get_style();
	/*	have_goods[awards_name] = true;*/
	if (money + award_money < 0 && award_money < 0)
	{
		cout << "711员工：你的校园卡余额不足，买不起这个装备！" << endl;
		return 0;
	}
	if (award_money > 0 && awards_name != "NULL" && award_exp == 0) cout << awards_name << "成功售卖！\t";
	if (award_money > 0) cout << "你的校园卡余额 +" << award_money << "$\t\n";
	if (award_money < 0) cout << "你的校园卡余额 " << award_money << "$" << endl;
	if (award_exp > 0) cout << "你的经验值 +" << award_exp << endl;

	money += award_money; // 商店购买 传个负值
	exp += award_exp; // 商店购买 exp默认不传


	for(; exp >= upgrade_exp[level - 1];) // 判断是否满足升级条件 5 10 20
	    {
		exp -= upgrade_exp[level - 1];
		level++;



		printf("UP!你的等级:%d->%d\n", level - 1, level);
		change_attribute(50, 10, 10, 10, 10);  // 姑且这样， ---》 可以设置一个等级与属性提升的关系， 这里默认每升一级属性加10
		now_HP = this->get_HP();
		now_MP = this->get_Mp();
		
	}


	if (equipment_count >= 15)
	{
		cout << "您的背包已满！" << endl;
		system("pause");               // 这里应该有满了之后的操作！没写！！！！+ sell 操作（以后加上！）
	}
	//switch (goods_style) // 根据award类型给leader_goods  new
	//{
	//case 1:
	//{
	//	leader_goods[equipment_count++] = new Weapon(*award);

	//	break;
	//}

	//case 2:
	//{
	//	leader_goods[equipment_count++] = new Armor(*award);
	//	break;
	//}
	//case 3:
	//{
	//	leader_goods[equipment_count++] = new Consume_items(*award);
	//	break;
	//}
	//case 4:
	//{
	//	leader_goods[equipment_count++] = new Quest_Items(*award);
	//	break;
	//}
	//default:
	//{
	//	cout << "error!" << endl;
	//	break;
	//}
	//}

	if (awards_name != "NULL" && award_money > 0 && exp > 0 || award_money < 0 && awards_name != "NULL" && exp == 0 || award_money == 0 && awards_name != "NULL" && exp == 0) cout << "恭喜你获得：" << awards_name << endl;

	if (!((award_money > 0 && awards_name != "NULL" && award_exp == 0)))
	{
		if (awards_name != "NULL")
		{
			switch (goods_style) // 根据award类型给leader_goods  new
			{
			case 1:
			{
				have_goods[awards_name] = leader_weapon_size + 1;
				/*leader_weapon[leader_weapon_size++] = *new Weapon(*award);*/
				Weapon* temp = static_cast<Weapon*>(award);
				leader_weapon[leader_weapon_size++] = *temp;
				break;
			}

			case 2:
			{
				have_goods[awards_name] = leader_armor_size + 1;
				/*leader_armor[leader_armor_size++] = *new Armor(*award);*/
				Armor* temp = static_cast<Armor*>(award);
				leader_armor[leader_armor_size++] = *temp;
				break;
			}
			case 3:
			{
				/*leader_consume_items[leader_consume_size++] = *new Consume_items(*award);*/
				have_goods[awards_name] = leader_consume_size + 1;
				Consume_items* temp = static_cast<Consume_items*>(award);
				leader_consume_items[leader_consume_size++] = *temp;
				break;
			}
			case 4:
			{
				have_goods[awards_name] = leader_quest_size + 1;
				/*	leader_quest_items[leader_quest_size++] = *new Quest_Items(*award);*/
				Quest_Items* temp = static_cast<Quest_Items*>(award);
				leader_quest_items[leader_quest_size++] = *temp;
				break;
			}
			default:
			{
				cout << "error!" << endl;
				break;
			}
			}
		}
	}

	return 1;
}

int Leader::judge_consume_if_empty()
{
	return leader_consume_size;
}
int Leader::use_consume_items(int consume_idx)
{
	string consume_style = leader_consume_items[consume_idx].get_consume_style();
	int reshape_consume_style = consume_map[consume_style];
	int consume_effect = leader_consume_items[consume_idx].get_effect();
	switch (reshape_consume_style)
	{
	case 1:
	{
		status_supplement(consume_effect);
		return 0;
	}
	case 2:
	{
		status_supplement(0, consume_effect);
		return 0;
	}
	case 3:
	{
		status_supplement(0, 0, consume_effect);
		break;
	}
	case 4:
	{
		status_supplement(0, 0, 0, consume_effect);
		break;
	}
	case 5:
	{
		status_supplement(0, 0, 0, 0, consume_effect);
		break;
	}
	}
	return 1;
}

int Leader::show_equip(int only_consume )
{
	if (only_consume == 0)
	{
		if (leader_weapon_size == 0 && leader_armor_size == 0 && leader_consume_size == 0 && leader_quest_size == 0)
		{
			cout << "你的背包真干净，啥也没有！" << endl;
			return 0;
		}
		cout << "#武器：" << endl;
		for (int i = 0; i < leader_weapon_size; i++)
		{
			cout << i + 1 << ":";
			leader_weapon[i].show_weapon();
		}
		if (leader_weapon_size == 0) cout << "没有捏~" << endl;
		cout << "#防具：" << endl;
		for (int i = 0; i < leader_armor_size; i++)
		{
			cout << i + 1 << ":";
			leader_armor[i].show_armor();
		}
		if (leader_armor_size == 0) cout << "没有捏~" << endl;
		cout << "#消耗品：" << "   *不可装卸，不可出售*" << endl;
		for (int i = 0; i < leader_consume_size; i++)
		{
			cout << i + 1 << ":";
			leader_consume_items[i].show_consume_items();
		}
		if (leader_consume_size == 0) cout << "没有捏~" << endl;
		cout << "#任务道具：" << "   *不可装卸，不可出售*" << endl;
		for (int i = 0; i < leader_quest_size; i++)
		{
			cout << i + 1 << ":";
			leader_quest_items[i].show_quest_items();
		}
		if (leader_quest_size == 0) cout << "没有捏~" << endl;
		cout << endl;
	}
	else
	{
		cout << "消耗品（背包）：";
		for (int i = 0; i < leader_consume_size; i++)
		{
			cout << i + 1 << ":";
			leader_consume_items[i].show_consume_items();

		}
		if (leader_consume_size == 0)
		{
			cout << "没有捏！" << endl;
			return 0; // 没有消耗品
		}
		return 1; // 有消耗品
	}
	if (leader_weapon_size == 0 && leader_armor_size == 0) return 4;
	if (leader_weapon_size > 0 && leader_armor_size > 0) return 3;
	if (leader_weapon_size > 0)  return 1;
	if (leader_armor_size > 0)    return 2;



}

// 临时增益 or 状态补充 or debuff or 战斗时受伤
int Leader::status_supplement(int add_HP , int add_MP , int add_strength , int add_agilty , int add_intelligence )
{
	if (add_HP < 0) cout << "你受到了" << -add_HP << "点伤害！\t\t" << "剩余HP： " << now_HP + add_HP << endl;

	now_HP += add_HP;
	now_MP += add_MP;
	if (now_HP > get_HP()) now_HP = get_HP();
	if (now_MP > get_Mp()) now_MP = get_Mp();
	if (now_HP <= 0)
	{
		cout << "你倒下了！" << endl;
		return 4;
		//system("pause");
		//exit(0); // 先这样， 具体死亡效果以及后续操作后面再说
	}
	now_strength += add_strength;
	now_agility += add_agilty;
	now_intelligence += add_intelligence;
	return 0;
}
void Leader::status_supplement_end() // 临时增益结束
{
	now_strength -= temp_strength;
	now_agility -= temp_agility;
	now_intelligence -= temp_intelligence;
}

void Leader::change_equipment(int change_idx, int style) // 换装备
{
	//int change_idx = have_goods[name];
	switch (style) // 根据award类型给leader_goods  new
	{
	case 1:
	{
		swap(leader_weapon[0], leader_weapon[change_idx]); // 这里以下标为0处作为主角的穿戴装备
		break;
	}

	case 2:
	{
		swap(leader_armor[0], leader_armor[change_idx]);   // 这里以下标为0处作为主角的穿戴装备
		break;
	}
	default:
	{
		cout << "error!" << endl;
		break;
	}
	}
}
void Leader::sell_equipment(int change_idx, int style)
{
	switch (style) // 根据award类型给leader_goods  new
	{
	case 1:
	{
		add_equipment_other(&leader_weapon[change_idx], leader_weapon[change_idx].get_value());
		//for (int i = change_idx; i < leader_weapon_size - 1; i++)
		//{
		//	leader_weapon[i] = leader_weapon[i + 1];
		//}
		if (leader_weapon_size > 1)
		{
			swap(leader_weapon[change_idx], leader_weapon[leader_weapon_size]);
			leader_weapon_size--;
		}

		if (leader_weapon_size == 1)
		{
			swap(leader_weapon[change_idx], leader_weapon[leader_weapon_size]);
			leader_weapon_size--;
		}
		/*if (leader_weapon_size == 0) cout << "没有什么可售卖的！" << endl;*/

		break;
	}

	case 2:
	{
		add_equipment_other(&leader_armor[change_idx], leader_armor[change_idx].get_value());
		//for (int i = change_idx; i < leader_armor_size - 1; i++)
		//{
		//	leader_armor[i] = leader_armor[i + 1];
		//}
		if (leader_armor_size > 1)
		{
			swap(leader_armor[change_idx], leader_armor[leader_armor_size]);
			leader_armor_size--;

		}

		if (leader_armor_size == 1)
		{
			swap(leader_armor[change_idx], leader_armor[leader_armor_size]);
			//swap(leader_armor[change_idx], leader_armor[13]);
			leader_armor_size--;
		}
		//if (leader_armor_size == 0) cout << "没有什么可售卖的！" << endl;


		break;
	}
	default:
	{
		cout << "error!" << endl;
		break;
	}
	}

}


// 战斗
int Leader::leader_attack() // 关于战斗时的属性与装备的具体关系后面再改 , 下面同理
{
	return now_strength + leader_weapon[0].get_attack_power(); // 攻击力与智力的关系后面再说
}
int Leader::leader_defence()
{
	return leader_armor[0].get_defensive_power();
}
int Leader::leader_evasion()
{
	return now_agility - leader_armor[0].get_evasion();
}

int Leader::getExp()
{
	return exp;
}
int Leader::getMoney()
{
	return money;
}
int Leader::getLevel()
{
	return level;
}
int Leader::getNowHP()
{
	return now_HP;
}
int Leader::getNowMp()
{
	return now_MP;
}
int Leader::getNowStrength()
{
	return now_strength;
}
int Leader::getNowAgility()
{
	return now_agility;
}
int Leader::getNowIntelligence()
{
	return now_intelligence;
}
int Leader::getTempStrength()
{
	return temp_strength;
}
int Leader::getTempAgility()
{
	return temp_agility;
}
int Leader::getTempIntelligence()
{
	return temp_intelligence;
}
Weapon* Leader::getpWeapon()
{
	return leader_weapon;
}
Armor* Leader::getpArmor()
{
	return leader_armor;
}
Weapon Leader::getWeapon(int idx)
{
	return leader_weapon[idx];
}
Armor Leader::getArmor(int idx)
{
	return leader_armor[idx];
}
Consume_items* Leader::getpConsume_items()
{
	return leader_consume_items;
}
Quest_Items* Leader::getpQuest_items()
{
	return leader_quest_items;
}
Consume_items Leader::getConsume_items(int idx)
{
	return leader_consume_items[idx];
}
Quest_Items Leader::getQuest_items(int idx)
{
	return leader_quest_items[idx];
}
map<string, int> Leader::getGoods()
{
	return have_goods;
}
map<string, int> Leader::getConsume_map()
{
	return consume_map;
}

void Leader::setExp(int _exp)
{
	exp = _exp;
}
void Leader::setMoney(int _money)
{
	money = _money;
}
void Leader::setLevel(int _level)
{
	level = _level;
}
void Leader::setNowHp(int _nowHp)
{
	now_HP = _nowHp;
}
void Leader::setNowMp(int _nowMp)
{
	now_MP = _nowMp;
}
void Leader::setNowStrength(int _nowStrength)
{
	now_strength = _nowStrength;
}
void Leader::setNowAgility(int _nowAgility)
{
	now_agility = _nowAgility;
}
void Leader::setNowIntelligence(int _nowIntelligence)
{
	now_intelligence = _nowIntelligence;
}
void Leader::setTempStrength(int _tmpStrength)
{
	temp_strength = _tmpStrength;
}
void Leader::setTempAgility(int _tmpAgility)
{
	temp_agility = _tmpAgility;
}
void Leader::setTempIntelligence(int _tmpIntelligence)
{
	temp_intelligence = _tmpIntelligence;
}
void Leader::setWeapon(int idx, Weapon tmpWeapon)
{
	leader_weapon[idx] = tmpWeapon;
}
void Leader::setArmor(int idx, Armor tmpArmor)
{
	leader_armor[idx] = tmpArmor;
}
void Leader::setConsumeItems(int idx, Consume_items tmpConsumeItem)
{
	leader_consume_items[idx] = tmpConsumeItem;
}
void Leader::setQuestItems(int idx, Quest_Items tmpQuestItems)
{
	leader_quest_items[idx] = tmpQuestItems;
}
void Leader::setHaveGood(map<string, int> tmp)
{
	have_goods = tmp;
}
void Leader::setConsumeMap(map<string, int> tmp)
{
	consume_map = tmp;
}


