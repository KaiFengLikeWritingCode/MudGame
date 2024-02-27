#include "System.h"
#include<string>
#include <iostream>
#include <sstream>

void System::file_write()
{
	/*fstream fin;*/
	//fin.open("Player.dat", ios::app);
	//fin.close();
	/*fin.open("Player.dat", ios::out | ios::binary);
	if (!fin) {
		cout << "存档文件打开失败！" << endl;
		exit(1);
	}
	fin.seekp(0, ios::beg);
	fin.write((char*)&player, sizeof(Leader));
	fin.close();*/

	ofstream fileLeader("leader.dat", ios::binary);
	ofstream fileWeapon("weapon.dat", ios::binary);
	ofstream fileArmor("armor.dat", ios::binary);
	ofstream fileConsume("consume.dat", ios::binary);
	ofstream fileQuest("quest.dat", ios::binary);
	ofstream fileGood("good.txt");
	ofstream fileQuestMap("questMap.txt");
	ofstream fileNpcFlag("flag.dat", ios::binary);
	ofstream fileTask("task.dat", ios::binary);
	ofstream filePosition("position.dat", ios::binary);
	ofstream fileSize("size.dat", ios::binary);

	if (fileLeader && fileWeapon && fileArmor && fileConsume && fileQuest && fileGood && fileQuestMap
		&& fileNpcFlag && fileTask)
	{
		cout << " " << endl;
	}
	else
	{
		cout << "文件打开失败" << endl;
	}
	
	fileLeader << player.getExp() << ' '
		<< player.getMoney() << ' '
		<< player.getLevel() << ' '
		<< player.getNowHP() << ' '
		<< player.getNowMp() << ' '
		<< player.getNowStrength() << ' '
		<< player.getNowAgility() << ' '
		<< player.getNowIntelligence() << ' '
		<< player.getTempStrength() << ' '
		<< player.getTempAgility() << ' '
		<< player.getTempIntelligence() << ' '
		<< player.getHP() << ' '
		<< player.getMP() << ' '
		<< player.getStrength() << ' '
		<< player.getAgility() << ' '
		<< player.getIntelligence() << ' '
		<< player.getWeaponSize() << ' '
		<< player.getArmorSize() << ' '
		<< player.getConsumeSize() << ' '
		<< player.getQuestSize();
	//for (int i = 0; i < 9; i++)
	//{
	//	/*fileWeapon.write(reinterpret_cast<char*>(&player.getWeapon(i)), sizeof(Weapon));
	//	fileArmor.write(reinterpret_cast<char*>(&player.getArmor(i)), sizeof(Armor));
	//	fileConsume.write(reinterpret_cast<char*>(&player.getConsume_items(i)), sizeof(Consume_items));
	//	fileQuest.write(reinterpret_cast<char*>(&player.getQuest_items(i)), sizeof(Quest_Items));*/
	//	Weapon weapon = player.getWeapon(i);
	//	Armor armor = player.getArmor(i);
	//	Consume_items consumeItems = player.getConsume_items(i);
	//	Quest_Items questItems = player.getQuest_items(i);

	//	fileWeapon.write(reinterpret_cast<char*>(&weapon), sizeof(Weapon));
	//	fileArmor.write(reinterpret_cast<char*>(&armor), sizeof(Armor));
	//	fileConsume.write(reinterpret_cast<char*>(&consumeItems), sizeof(Consume_items));
	//	fileQuest.write(reinterpret_cast<char*>(&questItems), sizeof(Quest_Items));
	//}
	/*for (const auto& i : player.getGoods()) 
	{
		fileGood << i.first << ' ' << i.second << ' ';
	}
	for (const auto& i : player.getConsume_map())
	{
		fileQuestMap << i.first << ' ' << i.second << ' ';
	}*/
	for (const auto& pair : player.getGoods())
	{
		fileGood << pair.first << " " << pair.second << endl;
	}
	for (const auto& pair : player.getConsume_map())
	{
		fileQuestMap << pair.first << " " << pair.second << endl;
	}
	for (int i = 0; i < 9; i++)
	{
		fileNpcFlag << game_npc[i].get_flag() << ' ';
		fileTask << game_task[i].judge_flag() << ' ';
	}
	filePosition << game_map.get_now_pos() << ' ' << game_map.get_x() << ' ' << game_map.get_y();
	
	for (int i = 0; i < 15; i++)
	{
		/*fileWeapon.write(reinterpret_cast<char*>(&player.getWeapon(i)), sizeof(Weapon));
		fileArmor.write(reinterpret_cast<char*>(&player.getArmor(i)), sizeof(Armor));
		fileConsume.write(reinterpret_cast<char*>(&player.getConsume_items(i)), sizeof(Consume_items));
		fileQuest.write(reinterpret_cast<char*>(&player.getQuest_items(i)), sizeof(Quest_Items));*/
		/*Weapon weapon = player.getWeapon(i);
		Armor armor = player.getArmor(i);
		Consume_items consumeItems = player.getConsume_items(i);
		Quest_Items questItems = player.getQuest_items(i);

		fileWeapon.write(reinterpret_cast<char*>(&weapon), sizeof(Weapon));
		fileArmor.write(reinterpret_cast<char*>(&armor), sizeof(Armor));
		fileConsume.write(reinterpret_cast<char*>(&consumeItems), sizeof(Consume_items));
		fileQuest.write(reinterpret_cast<char*>(&questItems), sizeof(Quest_Items));*/
		if (i == 0 || player.leader_weapon[i - 1].get_name() != "NULL" )
		{
				fileWeapon << player.leader_weapon[i].get_name() << ' '
				<< player.leader_weapon[i].get_value() << ' '
				<< player.leader_weapon[i].get_style() << ' '
				/*<< player.leader_weapon[i].getIntroduce() << ' '*/
				<< player.leader_weapon[i].get_attack_power();
		}
		if (i == 0 || player.leader_armor[i - 1].get_name() != "NULL" )
		{
			fileArmor << player.leader_armor[i].get_name() << ' '
				<< player.leader_armor[i].get_value() << ' '
				<< player.leader_armor[i].get_style() << ' '
				/*<< player.leader_armor[i].getIntroduce() << ' '*/
				<< player.leader_armor[i].get_defensive_power();
		}
		if (i == 0 || player.leader_consume_items[i - 1].get_name() != "NULL")
		{
			fileConsume << player.leader_consume_items[i].get_name() << ' '
				<< player.leader_consume_items[i].get_value() << ' '
				<< player.leader_consume_items[i].get_style() << ' '
				<< player.leader_consume_items[i].getConsumeStyle() << ' '
				<< player.leader_consume_items[i].getEffect();
		}
		if (i == 0 || player.leader_quest_items[i - 1].get_name() != "NULL")
		{
			fileConsume << player.leader_quest_items[i].get_name() << ' '
				<< player.leader_quest_items[i].get_value() << ' '
				<< player.leader_quest_items[i].get_style();
		}
	}

	fileLeader.close();
	fileWeapon.close();
	fileArmor.close();
	fileConsume.close();
	fileQuest.close();
	fileGood.close();
	fileQuestMap.close();
	fileNpcFlag.close();
	fileTask.close();
	filePosition.close();
	fileSize.close();

	/*for (int i = 0; i < 15; i++)
	{
		fileArmor.write(reinterpret_cast<char*>(&player.getArmor(i)), sizeof(Armor));
	}
	for (int i = 0; i < 15; i++)
	{
		fileConsume.write(reinterpret_cast<char*>(&player.getConsume_items(i), sizeof(Consume_items))
	}*/
	
} 
void System::file_read() {
	/*fstream fin;

	Leader leader = Leader("xxx", 2, 3, 4, 5, 6, 7);

	fin.open("Player.dat", ios::in | ios::binary);
	if (!fin.is_open()) {
		cout << "存档文件打开失败！" << endl;
	}
	fin.read((char*)&leader, sizeof(leader));
	player = leader;
	fin.close();*/
	ifstream fileLeader("leader.dat", ios::binary | ios::in);
	ifstream fileWeapon("weapon.dat", ios::binary);
	ifstream fileArmor("armor.dat", ios::binary);
	ifstream fileConsume("consume.dat", ios::binary);
	ifstream fileQuest("quest.dat", ios::binary);
	ifstream fileGood("good.txt");
	ifstream fileQuestMap("questMap.txt");
	ifstream fileNpcFlag("flag.dat", ios::binary);
	ifstream fileTask("task.dat", ios::binary);
	ifstream filePosition("position.dat", ios::binary);
	ifstream fileSize("size.dat", ios::binary);
	

	int exp, money, level, nowHp, nowMp, nowStr, nowAgi, nowInt, tmpStr, tmpAgi, tmpInt
		, Hp, Mp, Str, Agi, Int, weaponSize, armorSize, consumeSize, questSize;
	fileLeader >> exp >> money >> level >> nowHp >> nowMp >> nowStr >> nowAgi >> nowInt 
		>> tmpStr >> tmpAgi >> tmpInt >> Hp >> Mp >> Str >> Agi >> Int
		>> weaponSize >> armorSize >> consumeSize >> questSize;
	//Leader tmpPlayer;
	/*cout << level << endl;
	system("pause");*/
	player.setExp(exp);
	player.setLevel(level);
	player.setMoney(money);
	player.setNowHp(nowHp);
	player.setNowMp(nowMp);
	player.setNowStrength(nowStr);
	player.setNowAgility(nowAgi);
	player.setNowIntelligence(nowInt);
	player.setTempStrength(tmpStr);
	player.setTempAgility(tmpAgi);
	player.setTempIntelligence(tmpInt);
	player.setHP(Hp);
	player.setMP(Mp);
	player.setStrength(Str);
	player.setAgility(Agi);
	player.setIntelligence(Int);
	player.setWeaponSize(weaponSize);
	player.setArmorSize(armorSize);
	player.setConsumeSize(consumeSize);
	player.setQuestSize(questSize);

	for (int i = 0; i < 15 ; i++)
	{
		int value, style, power, effect;
		string name, introduce, consumeStyle;
		
		fileWeapon >> name >> value >> style /*>> introduce*/ >> power;
		if (name != "NULL")
		{
			player.leader_weapon[i].setName(name);
			player.leader_weapon[i].setValue(value);
			player.leader_weapon[i].setStyle(style);
			//player.leader_weapon[i].setIntroduce(introduce);
			player.leader_weapon[i].setPower(power);
		}

		fileArmor >> name >> value >> style /*>> introduce*/ >> power;
		if (name != "NULL")
		{
			player.leader_armor[i].setName(name);
			player.leader_armor[i].setValue(value);
			player.leader_armor[i].setStyle(style);
			//player.leader_armor[i].setIntroduce(introduce);
			player.leader_armor[i].setPower(power);
		}
		fileConsume >> name >> value >> style >> consumeStyle >> effect;
		if (name != "NULL")
		{
			player.leader_consume_items[i].setName(name);
			player.leader_consume_items[i].setValue(value);
			player.leader_consume_items[i].setStyle(style);
			player.leader_consume_items[i].setConsumeStyle(consumeStyle);
			player.leader_consume_items[i].setEffect(effect);
		}
		fileQuest >> name >> value >> style;
		if (name != "NULL")
		{
			player.leader_quest_items[i].setName(name);
			player.leader_quest_items[i].setValue(value);
			player.leader_quest_items[i].setStyle(style);
		}

	}

	/*for (int i = 0; i < 15; i++)
	{
		Weapon tmpWeapon;
		fileWeapon.read(reinterpret_cast<char*>(&tmpWeapon), sizeof(Weapon));
		player.setWeapon(i, tmpWeapon);
		Armor tmpArmor;
		fileArmor.read(reinterpret_cast<char*>(&tmpArmor), sizeof(Armor));
		player.setArmor(i, tmpArmor);
	}*/
	/*map<string, int> tmpHaveGoods;
	while (!fileGood.eof())
	{
		string key;
		int value;
		fileGood >> key >> value;
		tmpHaveGoods.insert(pair<string, int>(key, value));
	}
	player.setHaveGood(tmpHaveGoods);
	map<string, int> tmpConsumeMap;
	while (!fileQuestMap.eof())
	{
		string key;
		int value;
		fileGood >> key >> value;
		tmpConsumeMap.insert(pair<string, int>(key, value));
	}
	player.setConsumeMap(tmpConsumeMap);*/
	map<string, int> tmpHaveGoods;
	string key;
	int value;
	while (fileGood >> key >> value)
	{
		tmpHaveGoods[key] = value;
	}
	player.setHaveGood(tmpHaveGoods);
	map<string, int> tmpConsumeMap;
	while (fileQuestMap >> key >> value)
	{
		tmpConsumeMap[key] = value;
	}
	player.setConsumeMap(tmpConsumeMap);
	for (int i = 0; i < 9; i++)
	{
		double tmpFlag;
		fileNpcFlag >> tmpFlag;
		game_npc[i].setFlag(tmpFlag);
		fileTask >> tmpFlag;
		game_task[i].setFlag(tmpFlag);
	}
	int tmpPos, tmpX, tmpY;
	filePosition >> tmpPos >> tmpX >> tmpY;
	game_map.setNowPos(tmpPos);
	game_map.setX(tmpX);
	game_map.setY(tmpY);

	fileLeader.close();
	fileWeapon.close();
	fileArmor.close();
	fileConsume.close();
	fileQuest.close();
	fileGood.close();
	fileQuestMap.close();
	fileNpcFlag.close();
	fileTask.close();
	filePosition.close();
	fileSize.close();
	
}


void System::begin(/*Map& game_map*/)
{

	int option;
	while (1)
	{

		system("cls");
		//int game_idx = game_map.get_now_pos();
		//init_graph();
		int game_idx = game_map.get_now_pos();
		int task_idx = task_map[game_idx];
		//cout << "你当前位于：" << game_map.get_now_map_name() << endl;
		game_map.Position_show();

		cout << "这里有：\t" << "NPC: " << game_npc[game_idx].get_name();
		if (game_npc[game_idx].get_name() != "NULL")
		{
			cout << "(" << game_npc[game_idx].get_introduce() << ")";
		}
		cout << endl;

		cout << "        \t" << "野怪: " << enemy[game_idx].get_name();
		if (enemy[game_idx].get_name() != "NULL")
		{
			cout << "(" << enemy[game_idx].get_introduce() << ")";
		}
		cout << endl;

		player.display();

		cout << "任务：" << endl;
		for (int i = 0; i <= game_idx; i++)
		{
			if (i == 0 || i == 2 || i == 3 || i == 6) game_npc[i].show_task();
		}

		

		cout << "\033[34m" << "1.交谈  2.战斗  3.钓鱼  4.移动  5.仓库  6.商店  7. 退出  8. 保存并退出"  << endl;
		cout <<  "请输入你的选择： " <<"\033[0m"<< endl << ">>>>";

		//try
		//{
		//	std::cin >> option;
		//}
		//catch (std::invalid_argument& e) {
		//	// 捕获无效参数异常，说明输入不是一个有效的数字
		//	std::cerr << "输入不是一个有效的数字。" << std::endl;
		//}
		//catch (std::out_of_range& e) {
		//	// 捕获超出范围异常，说明输入的数字太大或太小
		//	std::cerr << "输入的数字超出了可表示范围。" << std::endl;
		//}
		std::string input;
		while (true) {
			//std::cout << "请输入一个数字：";
			std::cin >> input;

			try {
				std::istringstream iss(input);
				double number;

				if (iss >> number) {
					// 输入成功转换为数字，输出数字并跳出循环
					//std::cout << "输入的数字是：" << number << std::endl;
					break;
				}
				else {
					// 输入无法转换为数字，抛出异常
					throw std::invalid_argument("输入不是一个有效的数字");
				}
			}
			catch (const std::invalid_argument& e) {
				// 捕获无效参数异常，说明输入不是一个有效的数字
				std::cerr << e.what() << " 请重新输入。" << std::endl;
			}
		}
		option = stoi(input);

		
		getchar();
		switch (option)
		{
		case 1:
		{
			if (game_npc[game_idx].get_introduce() != "NULL")
			{
				if (game_idx == 6 && game_npc[game_idx].get_flag() == 1)
				{
					//game_task[task_idx].change_flag();
					game_npc[game_idx].change_common_words(npc6_common_words[1], 2);
					game_npc[game_idx].change_task_words(npc6_task_words[1], 18);
					game_npc[6].init_npc_goods_award(&game_quest_items[4], &game_weapon[2]); // 海洋生物样本    一件nb的武器
				}

				double Judge_task_over = 0;

				if ((game_idx == 0 || game_task[task_idx].judge_flag() == 1 || game_task[game_idx].judge_flag() == 1 || game_idx == 6))
				{
					Judge_task_over = game_npc[game_idx].common_talk(player/*, game_task, task_idx*/);
				}
				else cout << game_npc[game_idx].get_name() << ": 我很忙！" << endl;

				if (Judge_task_over == 0.5)
				{
					if ((game_idx == 0 || game_task[task_idx].judge_flag() == 1 || game_task[task_idx].judge_flag() == 0.5 && game_idx == 6 || game_task[game_idx].judge_flag() == 1))
					{
						int task_option;
						cout << "1：接受 2：拒绝" << endl << ">>>>";
						cin >> task_option;
						getchar();
						if (task_option == 1)
						{
							game_task[game_idx].change_flag();
							if (game_idx == 0) 	game_task[game_idx].change_flag();

							game_npc[game_idx].task_words_talk(player);
						}
						else
						{
							cout << game_npc[game_idx].get_name() << ": 那就下次吧" << endl;
						}
					}

				}
				if (Judge_task_over == 1)
				{
					game_task[game_idx].change_flag();
				}


				game_map.map_judge(player);
				if (player.judge("防辐射服"))
				{
					game_map.change_flag_end();
				}

				system("pause");
			}
			if (enemy[game_idx].get_introduce() != "NULL") enemy[game_idx].common_talk(), system("pause");
			break;
		}
		case 2:
		{
			if (enemy[game_idx].get_introduce() == "NULL")
			{
				cout << "该处没有可战斗的对象！" << endl;
				system("pause");
				break;
			}
			else
			{
				game_fight.FightRound(player, enemy[game_idx], game_map);
				system("pause");
			}
			break;
		}
		case 3:
		{
			//-------------------------------------------------------------
			int count = 0;        //保底计数器
			static int count1 = 0;

			while (1)
			{
				cout << "1.开始钓鱼    0.退出" << endl;
				int ch4;
				while (true)
				{
					cout << "选择：";
					cin >> ch4;
					if (ch4 != 1 && ch4 != 0)
					{
						cout << "选择无效，重新选择" << endl;
					}
					else break;
				}
				if (ch4 == 1)
				{
					srand((unsigned)time(NULL));
					int random1 = rand() % 200;// 生成钓鱼种子/

					int random2 = rand() % 4;// 生成时间种子/
					random2 += 1;//消除0秒；
					system("cls");
					char str[14] = "fishing......";
					srand(time(nullptr));
					int min2 = 1, max2 = 200;
					int randTime = randTime = (rand() % (max2 - min2 + 1)) + min2;//范围[min,max]
					random1 = (random1 + randTime) / 2;

					for (int k = 0; k < random2; k++)   //钓鱼时间
					{
						for (int i = 0; i < 14; i++)
						{
							cout << str[i];
							Sleep(100);
						}
						system("cls");
					}
					count = pool.fishing(random1, player);
					if (count == 1)
					{
						count1++;
						if (count1 == 3)
						{
							player.change_money(2);    //三次不中保底￥2
						}
					}
					//cout << random1 << endl;   //查看随机数
					//break;
				}
				else break;
			}

			//-------------------------------------------------------------
			system("pause");
			break;
		}
		case 4:
		{
			/*game_map.show_map();*/
			game_map.move();
			system("pause");
			break;
		}
		case 5:
		{
			int logout_flag = 0;
			int bag_option;
			int bag_statue = player.show_equip();
			if (bag_statue)
			{
				cout << "1. 更换装备\t 2.查看形象\t 3.退出" << endl;
				cout << ">>>>";
				while (cin >> bag_option)
				{
					switch (bag_option)
					{
					case 1:
					{
						if (bag_statue == 4)
						{
							cout << "没有可以装卸的装备！" << endl;
							break;
						}
						cout << "1. 换武器， 2. 换防具" << endl;
						int change_equip_option, change_idx;
						cout << ">>>>";
						cin >> change_equip_option;
						if (change_equip_option == 1)
						{
							if (bag_statue != 1 && bag_statue != 3)cout << "你没武器诶！考虑考虑防具吧！" << endl;
							else
							{
								cout << "请选择要换上的武器的序号>>";
								cin >> change_idx;
								player.change_equipment(change_idx - 1, change_equip_option);
								cout << "更换成功！" << endl;
								logout_flag = 1;
							}
						}
						if (change_equip_option == 2)
						{
							if (bag_statue != 2 && bag_statue != 3)cout << "你没防具诶！考虑考虑武器吧！" << endl;
							else
							{
								cout << "请选择要换上的防具的序号>>";
								cin >> change_idx;
								player.change_equipment(change_idx - 1, change_equip_option);
								cout << "更换成功！" << endl;
								logout_flag = 1;
							}
						}
						break;
					}

					case 2:        //查看形象
					{
						if (player.getWeapon_size() != 0 && player.getArmor_size() != 0)
						{
							system("cls");
							printCharacter_arms_armor();
						}

						else if (player.getArmor_size() != 0 && player.getWeapon_size() == 0)
						{
							system("cls");
							printCharacter_armor();
						}

						else if (player.getArmor_size() == 0 && player.getWeapon_size() != 0)
						{
							system("cls");
							printCharacter_arms();
						}

						else
						{
							system("cls");
							printCharacter_null();
						}


						logout_flag = 1;
						break;
					}

					case 3:
					{
						logout_flag = 1;
						break;
					}

					default:
					{
						cout << "输入有误，请检查！！" << endl;
						break;
					}
					}
					if (logout_flag == 1) break;
					cout << "1. 更换装备\t 2.退出" << endl;
					cout << ">>>>";
				}
			}
			else
			{
				cout << "多打怪，多完成任务才能让背包充盈哦~" << endl;
				cout << "1.查看形象\t 2.直接退出" << endl;
				cout << ">>>>";
				int watch_flag;
				cin >> watch_flag;
				if (watch_flag == 1)
				{
					system("cls");
					printCharacter_null();
				}

				else break;
			}
			system("pause");
			break;
		}
		case 6:
		{
			cout << "1. 购买物品\t 2.售出物品\t 3.退出" << endl;
			int store_option, logout_flag = 0;
			cout << ">>>>";
			while (cin >> store_option)
			{
				switch (store_option)
				{
				case 1:
				{
					game_store.store_show();
					cout << "请选择购买的物品种类： 1. 武器  2.防具  3.道具 (4. 退出）" << endl;
					cout << ">>>>";
					int buy_style, buy_success = 0, buy_idx;
					while (cin >> buy_style)
					{
						switch (buy_style)
						{
						case 1:
						{
							cout << "请输入购买武器的ID号：" << endl;
							cout << ">>>>";
							cin >> buy_idx;
							buy_success = game_store.buy(player, buy_style, buy_idx);
							break;
						}
						case 2:
						{
							cout << "请输入购买防具的ID号：" << endl;
							cout << ">>>>";
							cin >> buy_idx;
							buy_success = game_store.buy(player, buy_style, buy_idx);
							break;
						}
						case 3:
						{
							cout << "请输入购买道具的ID号：" << endl;
							cout << ">>>>";
							cin >> buy_idx;
							buy_success = game_store.buy(player, buy_style, buy_idx);
							break;
						}
						case 4:
						{
							buy_success = 1;
							break;
						}
						default:
						{
							cout << "选项无效！请检查！" << endl;
							break;
						}
						}
						if (buy_success) break;
						cout << "请选择购买的物品种类： 1. 武器  2.防具  3.道具 (4. 退出）" << endl;
						cout << ">>>>";
					}
					break;
				}
				case 2:
				{
					game_store.sell(player);
					//cout << "售卖成功！" << endl;
					break;
				}
				case 3:
				{
					logout_flag = 1;
					break;
				}
				default:
				{
					cout << "选项无效！请检查！" << endl;
				}
				}
				if (logout_flag)
				{
					cout << "欢迎光临！" << endl;
					break;
				}
				cout << "1. 购买物品\t 2.售出物品\t 3.退出" << endl;
				cout << ">>>>";
			}


			break;
		}
		case 7:
		{
			cout << "游戏结束，退出成功！" << endl;
			system("pause");
			exit(0);
			break;
		}
		case 8:
		{
			file_write();
			cout << "存档成功，成功退出！" << endl;
			system("pause");
			exit(0);
			break;
			//ofstream savefile("save.dat", ios::trunc | ios::binary);
			//if (!savefile)
			//{
			//	cerr << "存档失败" << endl;
			//	exit(1);
			//}

			//savefile.write(reinterpret_cast<char*>(&player), sizeof(Leader));
			//savefile.write(reinterpret_cast<char*>(game_npc), 9 * sizeof(Npc));
			//savefile.write(reinterpret_cast<char*>(game_task), 9 * sizeof(Task));
			//int tmpPos = game_map.get_now_pos();
			//savefile.write(reinterpret_cast<char*>(&tmpPos), sizeof(tmpPos));
			//cout << "存档成功，成功退出！" << endl;
			//system("pause");
			//exit(0);
			//break;




		}
		default:
		{
			cout << "你输入的选项不在范围内， 请重新输入>>" << endl;
			system("pause");
			break;
		}
		}
	}


}

Leader System::getLeader()
{
	return player;
}

Npc System::getNpc(int idx)
{
	return game_npc[idx];
}




void System::printCharacter_null()
{
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;iiiiiii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i;###K##K#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i,######W##K#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i#WW#iiii####;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##.#i:#:i#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#iii::::#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,ii::#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#,###:#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##GG#ii##,##;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;t#WffGGffGGGiiiiti;Kti;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LfjjLjfffffjGttttttttiD;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LfLfjLfjffjfGjjjtiiittiE;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LfLLLfffjffGGjjjttiiijjK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LLELLLLffffGGjfjjttiii;fK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;#LLLELLLLfjffGjffffttiiiift#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;#LLLEDLELjjffGjjffttffii;fi#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;#LLLELEDjfffLtjtjjffiiiiift#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;GLLLjLEELfffLLLjtjtjjjtiiiff#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;iGjLLjLEELffLjGLttttjttiiifLt#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;ELLLjL#DLffjjGLttttttiiijGtt#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;ELLfjL##LLLLLLLttttiiiiGGfii#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;Kffjf#;##WWWWWWWWWWWWW#i.;fK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;GGfff#;##WWWWWWW#KWKWW##L.,E;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;Kjit#;##WWWWWWW#W#WWWWWWW#Gj;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;i#Litt#;##WWWWWW#WWWWWWWWW#ii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;#G##t#;##WWWW#W#WWWWWWWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;E;W#i;##WW#WWW#WWWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;,Di#i;;##WWWWW##WWWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##W#KW##WWW#KWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW##WWWWWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW##WWWWKWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWWW#,#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWW#,#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWW#;#WKWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;######;#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;W###WK,#WWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i###WK#WWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;###KWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i###WWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWW#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i####D#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#K#KD#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;####;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
}
void System::printCharacter_arms()
{
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;iiiiiii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i;###K##K#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i,######W##K#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i#WW#iiii####;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##.#i:#:i#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#iii::::#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,ii::#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#,###:#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##GG#ii##,##;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;t#WffGGffGGGiiiiti;Kti;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LfjjLjfffffjGttttttttiD;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LfLfjLfjffjfGjjjtiiittiE;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LfLLLfffjffGGjjjttiiijjK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LLELLLLffffGGjfjjttiii;fK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;###;;;;;;;;;;;;;;;#LLLELLLLfjffGjffffttiiiift#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;######;;;;;;;;;;;;;#LLLEDLELjjffGjjffttffii;fi#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;#######;;;;;;;;;;;;#LLLELEDjfffLtjtjjffiiiiift#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;#######;;;;;;;;;;GLLLjLEELfffLLLjtjtjjjtiiiff#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;#######;;;;;;;;iGjLLjLEELffLjGLttttjttiiifLt#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;######;;;;;;;;;ELLLjL#DLffjjGLttttttiiijGtt#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;#####;;;;;;;;ELLfjL##LLLLLLLttttiiiiGGfii#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;####;;;;;;;Kffjf#;##WWWWWWWWWWWWW#i.;fK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;####;;;;;;GGfff#;##WWWWWWW#KWKWW##L.,E;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;####;;;;Kjit#;##WWWWWWW#W#WWWWWWW#Gj;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;####;i#Litt#;##WWWWWW#WWWWWWWWW#ii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;###;#G##t#;##WWWW#W#WWWWWWWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;###E;W#i;##WW#WWW#WWWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;#Di#i;;##WWWWW##WWWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;DD###;#;##W#KW##WWW#KWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;KK##;###WWWW##WWWWWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;##WWWW##WWWWKWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWWW#,#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWW#,#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWW#;#WKWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;######;#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;W###WK,#WWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i###WK#WWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;###KWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i###WWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWW#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i####D#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#K#KD#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;####;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
}
void System::printCharacter_armor()
{
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;iiiiiii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i;###K##K#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i,######W##K#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i#WW#iiii####;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##.#i:#:i#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#iii::::#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,ii::#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#,###:#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;$$##GG#ii##,#$$$;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;t#W$$GGffGGGiii$$4;Kti;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#Lf$$$$fffffjGtt$$$tttiD;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LfL$$$$$$fjfGj$$$$$$ttiE;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#Lf$$$$$$$$$$$$$$$$$$iijK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LL$$$$$$$$@@$$$$$$$$$$;fK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;#LLL$$$$$$$$@@@@$$$$$$$$ift#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;#LLL$$$$$$$@@@@@@$$$$$$$ifi#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;#LLL$$$$$$@@@@@@@@$$$$$$ift#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;GLLLL$$$$$$$@@@@@@$$$$$$$ttf#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;iGjLLL$$$$$$$$$@@@$$$$$$$$ttt#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;ELLLL$$$$$$$$$$@$$$$$$$$$ttt#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;ELLfjL$$$$$$$$$$$$$$$$$$tti#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;Kffjf#;##WWWWWWWWWWWWW#i.;fK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;GGfff#;##WWWWWWW#KWKWW##L.,E;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;Kjit#;##WWWWWWW#W#WWWWWWW#Gj;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;i#Litt#;##WWWWWW#WWWWWWWWW#ii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;#G##t#;##WWWW#W#WWWWWWWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;#E;W#i;##WW#WWW#WWWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;Di#i;;##WWWWW##WWWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;##W#KW##WWW#KWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;###WWWW##WWWWWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW##WWWWKWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWWW#,#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWW#,#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWW#;#WKWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;######;#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;W###WK,#WWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i###WK#WWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;###KWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i###WWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWW#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i####D#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#K#KD#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;####;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
}

void System::printCharacter_arms_armor()
{
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;iiiiiii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i;###K##K#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i,######W##K#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i#WW#iiii####;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##.#i:#:i#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#iii::::#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,ii::#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#,###:#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;$$##GG#ii##,#$$$;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;t#W$$GGffGGGiii$$4;Kti;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#Lf$$$$fffffjGtt$$$tttiD;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#LfL$$$$$$fjfGj$$$$$$ttiE;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#Lf$$$$$$$$$$$$$$$$$$$ijK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;；;;;;;;;;;;;;;;;;#LL$$$$$$$$@@$$$$$$$$$i;fK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;###;;;;;;;;;;;;;;;#LLL$$$$$$$$@@@@$$$$$$$$ift#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;######;;;;;;;;;;;;;#LLL$$$$$$$@@@@@@$$$$$$$tfi#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;#######;;;;;;;;;;;;#LLL$$$$$$@@@@@@@@$$$$$$tft#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;#######;;;;;;;;;;GLLLL$$$$$$$@@@@@@$$$$$$$$tf#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;#######;;;;;;;;iGjLLL$$$$$$$$$@@@$$$$$$$$$tt#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;######;;;;;;;;;ELLLL$$$$$$$$$$@$$$$$$$$$itt#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;#####;;;;;;;;ELLfjL$$$$$$$$$$$$$$$$$$$ti#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;####;;;;；;;Kffjf#;##WWWWWWWWWWWWW#i.;fK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;####;;;;；;GGfff#;##WWWWWWW#KWKWW##L.,E;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;####;;;;Kjit#;##WWWWWWW#W#WWWWWWW#Gj;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;####;i#Litt#;##WWWWWW#WWWWWWWWW#ii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;###;#G##t#;##WWWW#W#WWWWWWWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;###E;W#i;##WW#WWW#WWWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;#Di#i;;##WWWWW##WWWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;DD###;#;##W#KW##WWW#KWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;KK##;###WWWW##WWWWWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;##WWWW##WWWWKWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWWW#,#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWW#,#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWW#;#WKWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;######;#WWWKK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;W###WK,#WWWK#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i###WK#WWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;###KWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWWWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i###WWWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##WWWW#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i##WWW#i;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i####D#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#K#KD#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
	cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;####;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;i\n";
}