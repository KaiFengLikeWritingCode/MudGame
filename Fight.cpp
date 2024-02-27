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
	int consume_flag = 0; // 判断是否使用过消耗品(非HP/MP)
	int consume_round = 0; // 消耗品持续的回合数
	int option;
	end_flag = 0;
	round = 0;
	while (end_flag != 1)
	{
		if (consume_flag)
		{
			consume_round++;
			if (consume_round == 4) // 消耗品持续三个回合
			{
				consume_flag = 0;
				consume_round = 0;
				cout << "增益结束！" << endl;
				player.status_supplement_end();  // 有bug ， 先这样吧
			}
		}
		cout << "Round: " << round + 1 << endl;
		round++;
		cout << "请选择：1，普通攻击 2，使用技能 3，使用药品 4，逃跑" << endl;
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
		case 2: // 暂时不写
		{
			int skill_size = player.get_skill_size();
			player.show_skill();
			cout << "请输入你的选择";
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
						cout << "选项无效！请检查！" << endl;
						break;
					}
					}
				}
				else
				{
					cout << "选项无效！请检查！" << endl;
				}

				if (end_flag_2) break;
				cout << "请输入你的选择";
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
				cout << "你可以使用的";
				if (player.show_equip(1))
				{
					cout << "请输入您的选择：" << endl;
					cout << ">>>>";
					cin >> option_consume;
					consume_flag = player.use_consume_items(option_consume - 1);
				}
			}
			else
			{
				cout << "没有可以使用的药品！" << endl;
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
				cout << "逃跑成功！" << endl;
				return;
			}
			else
			{
				cout << "逃跑失败" << endl;
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
	else cout << "战斗结束！ " << endl;
}