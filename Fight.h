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
	//Leader player;//ս���Ľ�ɫ
	//Antagonist enemy;//ս���Ĺ���
	int end_flag = 0;
	int round = 0;//�غ���
	//double hurt;//ս���������˺�ֵ
};
