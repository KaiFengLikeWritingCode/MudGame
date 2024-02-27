#pragma once

#include "Leader.h"
#include "Antagonist.h"
#include "Map.h"

class Fight {

public:

	int leader_attack(Leader& player, Antagonist& enemy);
	int enemy_attack(Leader& player, Antagonist& enemy);
	void FightRound(Leader& player, Antagonist& enemy, Map& game_map);

private:
	//Leader player;//战斗的角色
	//Antagonist enemy;//战斗的怪物
	int end_flag = 0;
	int round = 0;//回合数
	//double hurt;//战斗产生的伤害值
};
