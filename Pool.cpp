#include "Pool.h"

int Pool::fishing(int randomValue, Leader& player)
{

	if (randomValue >= 50 && randomValue <= 60 || randomValue <= 80 && randomValue >= 70 || randomValue < 100 && randomValue >= 90 || randomValue < 120 && randomValue >= 110 || randomValue <= 140 && randomValue > 130)      //�ɹ�����50%
	{
		cout << "����ɹ���" << endl << "���" << fish[0].getName() << "һ������ֵ" << fish[0].getPrice() << endl << "���Զ��һ�Ϊ���" << endl;
		player.change_money(fish[0].getPrice());
		return 0;
	}
	else if (randomValue >= 178 && randomValue < 188 || randomValue <= 50 && randomValue > 40 || randomValue <= 150 && randomValue > 140)//�ɹ�����15%
	{
		cout << "����ɹ���" << endl << "���" << fish[1].getName() << "һ������ֵ" << fish[1].getPrice() << endl << "���Զ��һ�Ϊ���" << endl;
		player.change_money(fish[1].getPrice());
		return 0;
	}
	else if (randomValue >= 8 && randomValue < 18 || randomValue <= 125 && randomValue > 120)//�ɹ�����5%
	{
		cout << "����ɹ���" << endl << "���" << fish[2].getName() << "һ������ֵ" << fish[2].getPrice() << endl << "���Զ��һ�Ϊ���" << endl;
		player.change_money(fish[2].getPrice());
		return 0;
	}
	else if (randomValue >= 80 && randomValue < 84 || randomValue < 129 && randomValue > 125)//�ɹ�����4%
	{
		cout << "����ɹ���" << endl << "���" << fish[3].getName() << "һ������ֵ" << fish[3].getPrice() << endl << "���Զ��һ�Ϊ���" << endl;
		player.change_money(fish[3].getPrice());
		return 0;
	}
	else if (randomValue == 188 || randomValue == 7 || randomValue == 199 || randomValue == 1)//�ɹ�����2%
	{
		cout << "����ɹ���" << endl << "���" << fish[4].getName() << "һ������ֵ" << fish[4].getPrice() << endl << "���Զ��һ�Ϊ���" << endl;
		player.change_money(fish[4].getPrice());
		return 0;
	}
	else
	{
		cout << "����ʧ�ܣ�����һ�ΰ�" << endl;
		return 1;
	}
}