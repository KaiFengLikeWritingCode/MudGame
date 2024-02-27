#include "Npc.h"

void Npc::init_npc_goods_award(Object* new_goods_need, Object* new_award)
{
	int style1 = new_goods_need->get_style(), style2 = new_award->get_style();
	switch (style1)
	{
	case 1:
	{
		goods_need = new Weapon(*new_goods_need);
		goods_need = new_goods_need;
		break;
	}
	case 2:
	{
		goods_need = new Armor(*new_goods_need);
		goods_need = new_goods_need;
		break;
	}
	case 3:
	{
		goods_need = new Consume_items(*new_goods_need);
		goods_need = new_goods_need;
		break;
	}
	case 4:
	{
		goods_need = new Quest_Items(*new_goods_need);
		goods_need = new_goods_need;
		break;
	}
	default:
	{
		cout << "error!" << endl;
		break;
	}
	}

	switch (style2)
	{
	case 1:
	{
		award = new Weapon(*new_award);
		award = new_award;
		break;
	}
	case 2:
	{
		award = new Armor(*new_award);
		award = new_award;
		break;
	}
	case 3:
	{
		award = new Consume_items(*new_award);
		award = new_award;
		break;
	}
	case 4:
	{
		award = new Quest_Items(*new_award);
		award = new_award;
		break;
	}
	default:
	{
		cout << "error!" << endl;
		break;
	}
	}

}

double Npc::common_talk(Leader& player/*, Task* game_task, int task_idx*/)
{
	if (flag == 1)
	{
		cout << get_name() << ": С�ﳤ������־~" << endl;
	}
	if (flag == 0)  // δ��������ʱ��̸��
	{
		for (int i = 1; i < 22; i++)
		{
			if (common_words[i] != "NULL")
			{
				cout << common_words[i] /*<< endl*/;
				//Sleep(10);

				if (i == 1) cout << " (Enter����)";
				getchar();
			}
			else break;
		}
		return 0.5;
	}
	if (task_words_talk(player))
	{
		return 1;
	}
	//if (task_words_talk(player))
	//{
	//	game_task[task_idx].change_flag();
	//}
	if (flag == 0.5) // �������񣬵�û�����ʱ��̸��
	{
		cout << common_words[0] << endl;
	}

	return 0;

}
int Npc::task_words_talk(Leader& major_role)
{
	//double Task_judge = 0;
	if (flag == 0)
	{
		flag = 0.5; // ����������̸��
		for (int i = 0; i < 22; i++)
		{
			if (task_words[i] != "NULL" && task_words[i] != "divide")
			{
				cout << task_words[i] /*<< endl*/;
				//Sleep(10);
				getchar();

			}
			else break;
		}
	}
	else if (flag == 0.5)  // ���������ٶԻ�ʱҪ�ж��Ƿ��������
	{
		return	judge_task(major_role); // 1��ɣ� 0û���
	}
}
void Npc::change_common_words(string* new_common_words, int common_len)
{
	flag = 0;
	for (int i = 1; i < 22; i++)
	{
		common_words[i] = "NULL";
	}

	for (int i = 1; i < common_len; i++)
	{
		common_words[i] = *(new_common_words + i);
	}

}
void Npc::change_task_words(string* new_task_words, int task_len)
{
	for (int i = 0; i < 22; i++)
	{
		task_words[i] = "NULL";
	}

	for (int i = 0; i < task_len; i++)
	{
		task_words[i] = *(new_task_words + i);
	}
}

int Npc::judge_task(Leader& major_role)
{
	if (major_role.judge(goods_need->get_name()))
	{
		flag = 1;
		/*	cout << "�������������" << endl;
			Sleep(50);
			cout << "�ǵģ�������jb���򵥰�����" << endl;
			cout << "��ϲ��������񣬹�ϲ���� ";*/
		int judge_divide = 0;
		for (int i = 0; i < 22; i++)
		{
			if (task_words[i] != "NULL" && judge_divide == 1)
			{
				cout << task_words[i] /*<< endl*/;
				//system("pause");
				getchar();
			}
			if (task_words[i] == "divide") judge_divide = 1;
			if (task_words[i] == "NULL") break;
		}
		//if(award->get_name() != "NULL")	cout << award->get_name() << endl;
		major_role.add_equipment_other(award, money, exp);
		return 1;
	}
	return 0;
}

double Npc::get_flag() // �ж��Ƿ��������
{
	return flag;
}
void Npc::setFlag(double tmpFlag)
{
	flag = tmpFlag;
}
string Npc::get_introduce()
{
	return introduction;
}

void Npc::show_task()
{
	if (goods_need->get_name() != "NULL" && flag != 0)
	{
		cout << get_name() << ": " << "need: " << goods_need->get_name();

		if (flag == 1)
			cout << "  ����ɣ�Ŀǰû�����������~";


		if (flag == 0.5)
			cout << "  δ��ɣ�";


		if (flag == 0)
			cout << "  δ���ܣ�";

		cout << endl;



	}
}