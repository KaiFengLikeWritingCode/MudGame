#pragma once
#include "Npc.h"

using namespace std;

class Task
{
private:
	string name[2];
	double flag = 0; // 0 û��ɣ� 0.5 ���� �� 1 ���  1.5 ��ʼ�ڶ�������S
public:
	Task() = default;
	Task(string name1, string name2 = "NULL")
	{
		name[0] = name1;
		name[1] = name2;
		flag = 0;
	}
	/*Task()
	{
		name[0] = "NULL";
		name[1] = "NULL";
		flag = 1;
	}*/
	double judge_flag();
	void change_flag();
	void setFlag(double tmpFlag);
};