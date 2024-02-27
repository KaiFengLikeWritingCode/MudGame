#include "Store.h"


void Store::store_show()
{
	cout << "商店列表： " << endl;
	cout << "#武器：" << endl;
	for (int i = 0; i < store_weapon_size && store_weapon[i].get_name() != "NULL"; i++)
	{
		cout << i + 1 << ":";
		store_weapon[i].show_weapon();
	}
	cout << "#防具：" << endl;
	for (int i = 0; i < store_armor_size && store_armor[i].get_name() != "NULL"; i++)
	{
		cout << i + 1 << ":";
		store_armor[i].show_armor();
	}
	cout << "#消耗品：" << endl;
	for (int i = 0; i < store_consume_size && store_consume_items[i].get_name() != "NULL"; i++)
	{
		cout << i + 1 << ":";
		store_consume_items[i].show_consume_items();
	}
}
// choose1  1: weapon 2: armor 3: consume_items
// 0 购买失败  1 购买成功
int Store::buy(Leader& player, int choose1, int choose2) // choose1 买的道具类型， choose2 买的第几个
{
	switch (choose1)
	{
	case 1:
	{
		if (choose2 > store_weapon_size)
		{
			cout << "无该物品， 请检查ID号！" << endl;
			break;
		}

		if (player.add_equipment_other(&store_weapon[choose2 - 1], -store_weapon[choose2 - 1].get_value()))
		{
			cout << "711员工: 欢迎下次光临！" << endl;
			return 1;
		}
		break;
	}
	case 2:
	{
		if (choose2 > store_armor_size)
		{
			cout << "无该物品， 请检查ID号！" << endl;
			break;
		}
		if (player.add_equipment_other(&store_armor[choose2 - 1], -store_armor[choose2 - 1].get_value()))
		{
			cout << "711员工: 欢迎下次光临！" << endl;
			return 1;
		}

		break;
	}
	case 3:
	{
		if (choose2 > store_consume_size)
		{
			cout << "无该物品， 请检查ID号！" << endl;
			break;
		}
		if (player.add_equipment_other(&store_consume_items[choose2 - 1], -store_consume_items[choose2 - 1].get_value()))
		{
			cout << "711员工: 欢迎下次光临！" << endl;
			return 1;
		}

		break;
	}
	default:
	{
		cout << "error" << endl;
		exit(0);
		break;
	}
	}
	return 0;
}



int Store::sell(Leader& player) // 
{
	cout << "你的仓库列表：" << endl;
	int bag_statue = player.show_equip();
	int choose1, choose2;  // 卖的道具类型，  卖的第几个
	cout << "请选择要售卖的装备类型：（1.武器 2.防具 [3.退出]）" << endl;
	cout << ">>>>";
	while (cin >> choose1)
	{
		int logout_flag = 0;
		switch (choose1)
		{
		case 1:
		{
			if (bag_statue != 3 && bag_statue != 1)
			{
				cout << "背包里没有武器哦~" << endl;
				break;
			}

			cout << "请输入列表中所卖物品的ID：(输入0退出）" << endl;
			cout << ">>>>";
			while (cin >> choose2)
			{
				if (choose2 == 0) break;
				/*choose2 = choose2 - 1;*/
				if (choose2 <= store_weapon_size)
				{
					break;
				}
				else
				{
					cout << "选项无效，请检查输入！";
					cout << "请输入列表中所卖物品的ID：(输入0退出）" << endl;
					cout << ">>>>";
				}
			}

			if (choose2 != 0)
			{
				player.sell_equipment(choose2 - 1, choose1);
				cout << "711员工: 欢迎下次光临！" << endl;
			}
			break;
		}
		case 2:
		{
			if (bag_statue != 3 && bag_statue != 2)
			{
				cout << "背包里没有防具捏~" << endl;
				break;
			}

			cout << "请输入所卖物品的ID：(输入0退出）" << endl;
			cout << ">>>>";
			while (cin >> choose2)
			{
				if (choose2 == 0) break;
				if (choose2 <= store_armor_size)
				{
					break;
				}
				else
				{
					cout << "选项无效，请检查输入！";
					cout << "请输入所卖物品的ID：(输入0退出）" << endl;
					cout << ">>>>";
				}
			}

			if (choose2 != 0)
			{
				logout_flag = 1;
				player.sell_equipment(choose2 - 1, choose1);
				//cout << "711员工: 欢迎下次光临！" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "711员工: 欢迎下次光临！" << endl;
			logout_flag = 1;
			break;
		}
		default:
		{
			cout << "error" << endl;
			system("pause");
			exit(0);
			break;
		}
		}
		if (logout_flag == 1) break;

		cout << "请选择要售卖的装备类型：（1.武器 2.防具 [3.退出]）" << endl;
		cout << ">>>>";
	}

	return 0;
}