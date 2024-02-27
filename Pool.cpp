#include "Pool.h"

int Pool::fishing(int randomValue, Leader& player)
{

	if (randomValue >= 50 && randomValue <= 60 || randomValue <= 80 && randomValue >= 70 || randomValue < 100 && randomValue >= 90 || randomValue < 120 && randomValue >= 110 || randomValue <= 140 && randomValue > 130)      //成功概率50%
	{
		cout << "钓鱼成功！" << endl << "获得" << fish[0].getName() << "一条，价值" << fish[0].getPrice() << endl << "已自动兑换为金币" << endl;
		player.change_money(fish[0].getPrice());
		return 0;
	}
	else if (randomValue >= 178 && randomValue < 188 || randomValue <= 50 && randomValue > 40 || randomValue <= 150 && randomValue > 140)//成功概率15%
	{
		cout << "钓鱼成功！" << endl << "获得" << fish[1].getName() << "一条，价值" << fish[1].getPrice() << endl << "已自动兑换为金币" << endl;
		player.change_money(fish[1].getPrice());
		return 0;
	}
	else if (randomValue >= 8 && randomValue < 18 || randomValue <= 125 && randomValue > 120)//成功概率5%
	{
		cout << "钓鱼成功！" << endl << "获得" << fish[2].getName() << "一条，价值" << fish[2].getPrice() << endl << "已自动兑换为金币" << endl;
		player.change_money(fish[2].getPrice());
		return 0;
	}
	else if (randomValue >= 80 && randomValue < 84 || randomValue < 129 && randomValue > 125)//成功概率4%
	{
		cout << "钓鱼成功！" << endl << "获得" << fish[3].getName() << "一条，价值" << fish[3].getPrice() << endl << "已自动兑换为金币" << endl;
		player.change_money(fish[3].getPrice());
		return 0;
	}
	else if (randomValue == 188 || randomValue == 7 || randomValue == 199 || randomValue == 1)//成功概率2%
	{
		cout << "钓鱼成功！" << endl << "获得" << fish[4].getName() << "一条，价值" << fish[4].getPrice() << endl << "已自动兑换为金币" << endl;
		player.change_money(fish[4].getPrice());
		return 0;
	}
	else
	{
		cout << "钓鱼失败！再试一次吧" << endl;
		return 1;
	}
}