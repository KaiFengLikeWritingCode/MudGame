#include"Task.h"

double Task::judge_flag() { return flag; }
void Task::change_flag() { flag += 0.5; }
void Task::setFlag(double tmpFlag)
{
	flag = tmpFlag;
}