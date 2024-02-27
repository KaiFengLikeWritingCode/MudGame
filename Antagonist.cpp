#include "Antagonist.h"
#include <cstdlib>
#include <cstdio>

void Antagonist::show_introduce()
{
	cout << get_name() << ": " << introduction << endl;
}
string Antagonist::get_introduce() { return introduction; }

Antagonist::Antagonist()
{
	introduction = "NULL";
	common_words = "NULL";
	award = NULL;
}
Antagonist::Antagonist(const Antagonist& p)
{
	introduction = p.introduction;
	for (int i = 0; i < 15; i++)
	{
		common_words[i] = p.common_words[i];
	}
	award = new Object(*award);
}

void Antagonist::init_Antagonist_award(Object* new_award)
{
	int style = new_award->get_style();
	switch (style) // 根据award类型给leader_goods  new
	{
	case 1:
	{
		award = new Weapon(*new_award);
		award = new_award;
		break;
	}
	case 2:
	{
		award = new Armor(*new_award);
		award = new_award;
		break;
	}
	case 3:
	{
		award = new Consume_items(*new_award);
		award = new_award;
		break;
	}
	case 4:
	{
		award = new Quest_Items(*new_award);
		award = new_award;
		break;
	}
	default:
	{
		cout << "error!" << endl;
		break;
	}
	}
}

void Antagonist::common_talk()
{
	/*for (int i = 0; i < 15; i++)
	{
		if (common_words[i] != "NULL")
		{
			cout << common_words[i] << endl;
			system("pause");
		}
		else break;
	}*/
	cout << get_name() << ": " << common_words << endl;
}
void Antagonist::defeated(Leader& major_role) // defeated 被击败
{

	cout << get_name() << ": 约翰！。。。" << endl;
	Sleep(50);
	cout << "约翰： 我赢啦" << endl;
	cout << get_name() << "已经死亡, 恭喜你获得：" << endl;
	cout << "装备：" << award->get_name() << endl;
	cout << "金币：" << money << endl;
	cout << "exp:" << exp << endl;
	major_role.add_equipment_other(award, money, exp);
	string name = "变种怪物";
	if (name == get_name())
	{
		cout << "End!" << endl;
		system("pause");
		system("cls");
		string end_words[11] = {
			"约翰终于成功地将怪物击倒，然而，他没有预料到的是，怪物的身体在击倒后竟然发生了爆炸。虽然爆炸的规模并不大，但已经对这个原本已经岌岌可危的建筑造成了严重的损害。墙壁颤抖，尘土四起，崩塌的声音在空气中回响，仿佛预示着灾难的降临。",
			"李华：这可不妙，建筑已经无法再承受更多了，我们必须尽快离开。",
			"在李华的紧急引导下，约翰匆忙地离开了即将崩塌的学生活动中心。他的脚步刚一踏入安全地带，崩塌的浩劫便将学生活动中心彻底吞噬。废墟与尘烟一同升腾，构成了一幅令人心惊的画面。",
			"那轰然的崩溃声充斥耳际，在宣告着这里已经彻底沦为废墟。而这突如其来的景象也引起了西海岸校区内几乎所有人的好奇和惊诧。他们如同被吸引一般，急急赶往崩塌的方向，试图一窥究竟。",
			"约翰：这场噩梦终于要结束了。",
			"李华：是的，终于可以结束了。西海岸的真相终于要公之于众了。",
			"约翰：我明白了。",
			"李华：你明白了什么？",
			"约翰：我决定退学美国海洋大学，加入米哈游。我的人生已经与这种工作紧密相连。",
			"李华：我在米哈游等着你的加入。",
			"约翰离开了废墟，迈向了新的旅途。"
		};
		for (int i = 0; i < 11; i++)
		{
			cout << end_words[i] << endl;
			Sleep(400);
		}

	}
}
int Antagonist::attacked(Leader& major_role, int attack_HP)
{
	if (now_HP - attack_HP > 0)	cout << "你打出" << attack_HP << "点伤害！ " << get_name() << " 感到生气，打算对你回击。\t" << get_name() << "的剩余HP： " << now_HP - attack_HP << endl;
	now_HP -= attack_HP;
	if (now_HP <= 0)
	{
		now_HP = 0;
		defeated(major_role);
		return 1;  // 1 被击败 回合结束
	}
	return 0;
}
int Antagonist::enemy_attack()
{
	return now_strength;
}
//int enemy_defence()
//{
//	return 10;
//}
int Antagonist::enemy_evasion()
{
	return now_agility;
}

void Antagonist::enemy_skilled(int skill_style, int effect)
{
	switch (skill_style)
	{
	case 1:
	{
		now_HP += effect;
		cout << get_name() << "受到" << -effect << "诅咒伤害" << "\t剩余HP： " << now_HP << endl;
		break;
	}
	case 2:
	{
		break;
	}
	default:
	{
		break;
	}
	}
}