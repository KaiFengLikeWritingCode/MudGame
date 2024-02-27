#include "Fight.h"

int Fight::leader_attack(Leader& player, Antagonist& enemy)
{
	/*round++;*/
	int attack_HP = player.leader_attack();
	return enemy.attacked(player, attack_HP);
}
int Fight::enemy_attack(Leader& player, Antagonist& enemy)
{
	int attack_HP = enemy.enemy_attack();
	return player.status_supplement(-attack_HP);
}
void Fight::FightRound(Leader& player, Antagonist& enemy, Map& game_map)
{
	int option_consume;
	int consume_flag = 0; // �ж��Ƿ�ʹ�ù�����Ʒ(��HP/MP)
	int consume_round = 0; // ����Ʒ�����Ļغ���
	int option;
	end_flag = 0;
	round = 0;
	while (end_flag != 1)
	{
		if (consume_flag)
		{
			consume_round++;
			if (consume_round == 4) // ����Ʒ���������غ�
			{
				consume_flag = 0;
				consume_round = 0;
				cout << "���������" << endl;
				player.status_supplement_end();  // ��bug �� ��������
			}
		}
		cout << "Round: " << round + 1 << endl;
		round++;
		cout << "��ѡ��1����ͨ���� 2��ʹ�ü��� 3��ʹ��ҩƷ 4������" << endl;
		cout << ">>>>";
		cin >> option;
		int consume_flag_have = 0;
		switch (option)
		{
		case 1:
		{
			end_flag = leader_attack(player, enemy);
			if (end_flag)
			{
				break;
			}
			break;
		}
		case 2: // ��ʱ��д
		{
			int skill_size = player.get_skill_size();
			player.show_skill();
			cout << "���������ѡ��";
			cout << ">>>>";
			int option_skill;
			int end_flag_2 = 0;
			while (cin >> option_skill)
			{
				if (option_skill <= skill_size)
				{
					switch (option_skill)
					{
					case 1:
					{
						int skill_idx = option_skill - 1;
						player.use_skill(skill_idx);
						enemy.enemy_skilled(player.get_skill_style(skill_idx), player.get_skill_effect(skill_idx));
						end_flag_2 = 1;
						break;
					}
					case 2:
					{

						break;
					}
					case 3:
					{

						break;
					}
					case 4:
					{
						break;
					}
					case 5:
					{
						break;
					}
					case 6:
					{


						break;
					}
					case 7:
					{

						break;
					}
					case 8:
					{

						break;
					}
					case 9:
					{
						break;
					}
					default:
					{
						cout << "ѡ����Ч�����飡" << endl;
						break;
					}
					}
				}
				else
				{
					cout << "ѡ����Ч�����飡" << endl;
				}

				if (end_flag_2) break;
				cout << "���������ѡ��";
				cout << ">>>>";
			}
			break;
		}
		case 3:
		{
			int judge_empty = player.judge_consume_if_empty();
			if (judge_empty)
			{
				/*consume_flag = 1;*/
				cout << "�����ʹ�õ�";
				if (player.show_equip(1))
				{
					cout << "����������ѡ��" << endl;
					cout << ">>>>";
					cin >> option_consume;
					consume_flag = player.use_consume_items(option_consume - 1);
				}
			}
			else
			{
				cout << "û�п���ʹ�õ�ҩƷ��" << endl;
				consume_flag_have = 1;
				round--;
			}
			break;
		}
		case 4:
		{
			int escape = 60;
			int random = rand() % 100;
			if (random < escape)
			{
				cout << "���ܳɹ���" << endl;
				return;
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
			break;
		}
		}
		if (!end_flag && consume_flag_have == 0)
		{
			end_flag = enemy_attack(player, enemy);
		}
		if (end_flag == 4) break;
	}
	if (end_flag == 4)
	{

		game_map.init_map();
		player.leader_died();
	}
	else cout << "ս�������� " << endl;
}