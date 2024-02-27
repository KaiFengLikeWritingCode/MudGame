#pragma once


// 地图
#include <iostream>
#include<graphics.h>
#include<stdio.h>
#include<Gdiplus.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include <tchar.h>
#include <map>
#include "Leader.h"

using namespace std;
/*"0宿舍", "1猪山", "2食堂", "3、711 ",
"4高裕路", "5信息楼", "6综合体", "7海边", "8学生活动中心", */
class Map
{
private:
	int now_pos = 0; //当前位置
	int x = 2, y = 1;
	string position[5][5]; // 控制当前位置
	string mapName[10] = { "宿舍","猪山","食堂","711","高裕路","信息楼","综合体","海边","学生活动中心" };
	map<pair<int, int>, int> now_position_mp;
	map<pair<int, int>, string> move_mp;
	int flag_end_map = 0;
public:
	int get_x() { return x; }
	int get_y() { return y; }
	void setX(int _x)
	{
		x = _x;
	}
	void setY(int _y)
	{
		y = _y;
	}

	Map()
	{
		now_pos = 0;
		x = 2, y = 1;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				position[i][j] = "NULL";
		position[2][0] = "猪山";
		move_mp[{2, 0}] = " n";
		now_position_mp[{2, 0}] = 1;
		position[2][1] = "宿舍";
		move_mp[{2, 1}] = " ns";
		now_position_mp[{2, 1}] = 0;
		position[2][2] = "食堂";
		move_mp[{2, 2}] = " swe";
		now_position_mp[{2, 2}] = 2;
		position[0][1] = "海边";
		move_mp[{0, 1}] = " ne";
		now_position_mp[{0, 1}] = 7;
		position[0][2] = "学生活动中心";
		move_mp[{0, 2}] = " se";
		now_position_mp[{0, 2}] = 8;
		position[1][1] = "综合体";
		move_mp[{1, 1}] = " wn";
		now_position_mp[{1, 1}] = 6;
		position[1][2] = "高裕路";
		move_mp[{1, 2}] = " wnse";
		now_position_mp[{1, 2}] = 4;
		position[1][3] = "信息楼";
		move_mp[{1, 3}] = " s";
		now_position_mp[{1, 3}] = 5;
		position[3][2] = "711";
		move_mp[{3, 2}] = " w";
		now_position_mp[{3, 2}] = 3;
	}

	void show_map();
	void Position_show();
	void change_flag_end();

	void move();
	int get_now_pos();
	void setNowPos(int pos);
	string get_now_map_name();
	void init_map();
	void map_judge(Leader& player);


};