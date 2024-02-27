#include "Store.h"


void Store::store_show()
{
	cout << "�̵��б� " << endl;
	cout << "#������" << endl;
	for (int i = 0; i < store_weapon_size && store_weapon[i].get_name() != "NULL"; i++)
	{
		cout << i + 1 << ":";
		store_weapon[i].show_weapon();
	}
	cout << "#���ߣ�" << endl;
	for (int i = 0; i < store_armor_size && store_armor[i].get_name() != "NULL"; i++)
	{
		cout << i + 1 << ":";
		store_armor[i].show_armor();
	}
	cout << "#����Ʒ��" << endl;
	for (int i = 0; i < store_consume_size && store_consume_items[i].get_name() != "NULL"; i++)
	{
		cout << i + 1 << ":";
		store_consume_items[i].show_consume_items();
	}
}
// choose1  1: weapon 2: armor 3: consume_items
// 0 ����ʧ��  1 ����ɹ�
int Store::buy(Leader& player, int choose1, int choose2) // choose1 ��ĵ������ͣ� choose2 ��ĵڼ���
{
	switch (choose1)
	{
	case 1:
	{
		if (choose2 > store_weapon_size)
		{
			cout << "�޸���Ʒ�� ����ID�ţ�" << endl;
			break;
		}

		if (player.add_equipment_other(&store_weapon[choose2 - 1], -store_weapon[choose2 - 1].get_value()))
		{
			cout << "711Ա��: ��ӭ�´ι��٣�" << endl;
			return 1;
		}
		break;
	}
	case 2:
	{
		if (choose2 > store_armor_size)
		{
			cout << "�޸���Ʒ�� ����ID�ţ�" << endl;
			break;
		}
		if (player.add_equipment_other(&store_armor[choose2 - 1], -store_armor[choose2 - 1].get_value()))
		{
			cout << "711Ա��: ��ӭ�´ι��٣�" << endl;
			return 1;
		}

		break;
	}
	case 3:
	{
		if (choose2 > store_consume_size)
		{
			cout << "�޸���Ʒ�� ����ID�ţ�" << endl;
			break;
		}
		if (player.add_equipment_other(&store_consume_items[choose2 - 1], -store_consume_items[choose2 - 1].get_value()))
		{
			cout << "711Ա��: ��ӭ�´ι��٣�" << endl;
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
	cout << "��Ĳֿ��б�" << endl;
	int bag_statue = player.show_equip();
	int choose1, choose2;  // ���ĵ������ͣ�  ���ĵڼ���
	cout << "��ѡ��Ҫ������װ�����ͣ���1.���� 2.���� [3.�˳�]��" << endl;
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
				cout << "������û������Ŷ~" << endl;
				break;
			}

			cout << "�������б���������Ʒ��ID��(����0�˳���" << endl;
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
					cout << "ѡ����Ч���������룡";
					cout << "�������б���������Ʒ��ID��(����0�˳���" << endl;
					cout << ">>>>";
				}
			}

			if (choose2 != 0)
			{
				player.sell_equipment(choose2 - 1, choose1);
				cout << "711Ա��: ��ӭ�´ι��٣�" << endl;
			}
			break;
		}
		case 2:
		{
			if (bag_statue != 3 && bag_statue != 2)
			{
				cout << "������û�з�����~" << endl;
				break;
			}

			cout << "������������Ʒ��ID��(����0�˳���" << endl;
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
					cout << "ѡ����Ч���������룡";
					cout << "������������Ʒ��ID��(����0�˳���" << endl;
					cout << ">>>>";
				}
			}

			if (choose2 != 0)
			{
				logout_flag = 1;
				player.sell_equipment(choose2 - 1, choose1);
				//cout << "711Ա��: ��ӭ�´ι��٣�" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "711Ա��: ��ӭ�´ι��٣�" << endl;
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

		cout << "��ѡ��Ҫ������װ�����ͣ���1.���� 2.���� [3.�˳�]��" << endl;
		cout << ">>>>";
	}

	return 0;
}