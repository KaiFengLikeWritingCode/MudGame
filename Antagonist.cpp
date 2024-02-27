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
	switch (style) // ����award���͸�leader_goods  new
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
void Antagonist::defeated(Leader& major_role) // defeated ������
{

	cout << get_name() << ": Լ����������" << endl;
	Sleep(50);
	cout << "Լ���� ��Ӯ��" << endl;
	cout << get_name() << "�Ѿ�����, ��ϲ���ã�" << endl;
	cout << "װ����" << award->get_name() << endl;
	cout << "��ң�" << money << endl;
	cout << "exp:" << exp << endl;
	major_role.add_equipment_other(award, money, exp);
	string name = "���ֹ���";
	if (name == get_name())
	{
		cout << "End!" << endl;
		system("pause");
		system("cls");
		string end_words[11] = {
			"Լ�����ڳɹ��ؽ����������Ȼ������û��Ԥ�ϵ����ǣ�����������ڻ�����Ȼ�����˱�ը����Ȼ��ը�Ĺ�ģ�����󣬵��Ѿ������ԭ���Ѿ��᧿�Σ�Ľ�����������ص��𺦡�ǽ�ڲ������������𣬱����������ڿ����л��죬�·�Ԥʾ�����ѵĽ��١�",
			"�����ɲ�������Ѿ��޷��ٳ��ܸ����ˣ����Ǳ��뾡���뿪��",
			"����Ľ��������£�Լ����æ���뿪�˼���������ѧ������ġ����ĽŲ���һ̤�밲ȫ�ش��������ĺƽٱ㽫ѧ������ĳ������ɡ������볾��һͬ���ڣ�������һ�������ľ��Ļ��档",
			"�Ǻ�Ȼ�ı����������ʣ��������������Ѿ�������Ϊ���档����ͻ�������ľ���Ҳ������������У���ڼ��������˵ĺ���;��������ͬ������һ�㣬�������������ķ�����ͼһ��������",
			"Լ�����ⳡج������Ҫ�����ˡ�",
			"����ǵģ����ڿ��Խ����ˡ�����������������Ҫ��֮�����ˡ�",
			"Լ�����������ˡ�",
			"�����������ʲô��",
			"Լ�����Ҿ�����ѧ���������ѧ�������׹��Ρ��ҵ������Ѿ������ֹ�������������",
			"��������׹��ε�����ļ��롣",
			"Լ���뿪�˷��棬�������µ���;��"
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
	if (now_HP - attack_HP > 0)	cout << "����" << attack_HP << "���˺��� " << get_name() << " �е��������������ػ���\t" << get_name() << "��ʣ��HP�� " << now_HP - attack_HP << endl;
	now_HP -= attack_HP;
	if (now_HP <= 0)
	{
		now_HP = 0;
		defeated(major_role);
		return 1;  // 1 ������ �غϽ���
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
		cout << get_name() << "�ܵ�" << -effect << "�����˺�" << "\tʣ��HP�� " << now_HP << endl;
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