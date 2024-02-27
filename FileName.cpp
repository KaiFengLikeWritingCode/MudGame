//#define _CRT_SECURE_NO_DEPRECATE//防止sprintf报错//#include<graphics.h>
////#include<graphics.h>
////#include<stdio.h>
////#include<Gdiplus.h>
////#include<conio.h>
////#include<Windows.h>
////#include<string.h>
////#include <tchar.h>
//#include "Map.h"
////#include<bits/stdc++.h>
//#include <iostream>
//#include <cstdio>
//#include <easyx.h>
//#include<conio.h>
//#include <stdlib.h>
//#include <time.h>
//#pragma comment(lib,"winmm.lib")
//using namespace std;
//IMAGE bg;
//static TCHAR szWindowClass[] = _T("WindowClass"); //窗口类名
//static TCHAR szTitle[] = _T("海大侠客行"); //窗口标题
//void InitImg()
//{
//	loadimage(&bg, "image\\background.jpg", 720, 430);
//}
//
//int welcomePage()
//{
//	HANDLE hConsole;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
//	/*
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 13);
//	*/
//	for (int i = 0; i < 8; i++)
//		cout << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "0		0					     0			" << "    0   0           0          0           " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "  0   000000000000			     0			" << "    0   0            0         0 0  000    " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "   0 0						     0			" << "    000000000  000000000000    0 0         " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "       000000000		  000000000000000   " << "   0    0      0    0     0   0  0 00000   " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "0      0   0   0				 0  		" << "  00  0 0  0   0   0  0   0  0  0    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "  0  000000000000000			0  0		" << "0      00 0       0 0  0       00    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "    0  0   0   0			   0	0		" << "   0 00000000   0    0       0  0    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "      00000000000			  0		 0	    " << "   0    00         0   0        0    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "    0      0				 0		  0		" << "   0   0  0      0 00000 0      0    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "  0      0 0				0 		   0	" << "   0  0    0   0   0   0  0     0  0 0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "0         10			   0			00 	" << "   0 0      0      00000        0   00     " << endl << endl;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 10);
//	cout << '\t' << '\t' << '\t' << '\t';
//	cout << '\t' << "      ********************" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "          游戏制作信息" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "      ********************" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "   制作人：中国海洋大学2022夏季学期c++课程设计" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "	戴志伟、董凯志、董博伟、曹勇、陈哲" << endl << endl;
//	cout << '\t' << '\t' << '\t' << '\t';
//	cout << endl << endl << '\t' << '\t' << '\t' << '\t' << "   ";
//	return 0;
//}
//int backgroundGame()
//{
//	HANDLE hConsole;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 10);
//	//system("cls");
//	cout << "		   故事背景" << endl << endl;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 14);
//	string background = "    鸿蒙开化之初，中州大陆昆仑之巅的鸿钧上人创立道教，并收徒三人，各授以道门绝技，三徒皆修成混元大罗金仙万劫不坏之体，分别发展出道教的人道、阐教和截教三个分支。此三徒正是人道教主太上老君、阐教教主元始天尊和截教的通天教主。";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(10);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    三教主秉承师父鸿钧上人教诲，广收门徒将道教流传于世。只因入道门中即可修仙，使人跳出三界之外，不在五行之中，免除生死轮回之苦，使得入道修行之人多不胜数！但修仙之道并非苦心修炼便可达成。修行路上，均要经历三百年一小劫，一千五百年一大劫的劫数。修行之人均无法避开劫数，只能根据自身道行的深浅去经历劫数。";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    值商周两朝交替之时，恰逢修仙一千五百年仙劫，于是三教主共议封神榜，以观众仙道行浅深。然劫数难逃，封神一役，致使道门内部阐教和截教不和，修仙众人俱遭屠戮，更引来西方教派参与纷争，后因鸿钧上人亲自出面调停，终得以平息。";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    五百年后的中洲大陆，故事就发生在一个平凡冷清的小镇上。";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//	system("pause");
//
//	return 0;
//}
//
//int main()
//{
//	//initgraph(800, 600);
//	//mciSendString("play 23.mp3 repeat", 0, 0, 0);
//	//InitImg();
//	//while (1)
//	//{
//	//	BeginBatchDraw();
//	//	putimage(0, 0, &bg);
//	//	EndBatchDraw();
//	//}
//	welcomePage();
//	backgroundGame();
//	HANDLE hConsole;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 0xC);
//	string newGameMenu = "   1.新的游戏  2.读取存档  3.退出游戏";
//	for (int i = 0; i < newGameMenu.length(); i++) {
//		Sleep(20);
//		cout << newGameMenu[i];
//	}
//	int judge;
//	cin >> judge;
//	switch (judge)
//	{
//	case 1:
//	{
//
//		break;
//	}
//	case 2:
//	{
//		break;
//
//	}
//	case 3:
//	{
//		return 0;
//	}
//	}
//	system("pause");//悬停
//
//	printf("hello world!");
//	return 0;
//
//
//}


////#define _CRT_SECURE_NO_DEPRECATE//防止sprintf报错//#include<graphics.h>
////#pragma comment(lib,"winmm.lib")
//#include "Map.h"
//#include <iostream>
//#include <cstdio>
//#include <easyx.h>
//#include<conio.h>
//#include <stdlib.h>
//#include <time.h>
//using namespace std;
////IMAGE bg;
////static TCHAR szWindowClass[] = _T("WindowClass"); //窗口类名
////static TCHAR szTitle[] = _T("海大侠客行"); //窗口标题
////void InitImg()
////{
////	loadimage(&bg, "image\\background.jpg", 720, 430);
////}
//
//int welcomePage()
//{
//	HANDLE hConsole;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
//	/*
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 13);
//	*/
//	for (int i = 0; i < 8; i++)
//		cout << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "0		0					     0			" << "    0   0           0          0           " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "  0   000000000000			     0			" << "    0   0            0         0 0  000    " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "   0 0						     0			" << "    000000000  000000000000    0 0         " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "       000000000		  000000000000000   " << "   0    0      0    0     0   0  0 00000   " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "0      0   0   0				 0  		" << "  00  0 0  0   0   0  0   0  0  0    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "  0  000000000000000			0  0		" << "0      00 0       0 0  0       00    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "    0  0   0   0			   0	0		" << "   0 00000000   0    0       0  0    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "      00000000000			  0		 0	    " << "   0    00         0   0        0    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "    0      0				 0		  0		" << "   0   0  0      0 00000 0      0    0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "  0      0 0				0 		   0	" << "   0  0    0   0   0   0  0     0  0 0     " << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "0         10			   0			00 	" << "   0 0      0      00000        0   00     " << endl << endl;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 10);
//	cout << '\t' << '\t' << '\t' << '\t';
//	cout << '\t' << "      ********************" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "          游戏制作信息" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "      ********************" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "   制作人：中国海洋大学2022夏季学期c++课程设计" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "	戴志伟、董凯志、董博伟、曹勇、陈哲" << endl << endl;
//	cout << '\t' << '\t' << '\t' << '\t';
//	cout << endl << endl << '\t' << '\t' << '\t' << '\t' << "   ";
//	return 0;
//}
//int backgroundGame()
//{
//	HANDLE hConsole;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 10);
//	//system("cls");
//	cout << "		   故事背景" << endl << endl;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 14);
//	string background = "    游戏发生在美国不知名高校“美国海洋大学”（Ocean University of American），在这里，被挂科之神选中的人将被授予“学业警示”，发配到西海岸校区（加利福尼亚州）。玩家将扮演一位名为”约翰“的大三学生，在荒凉破败的废墟中邂逅性格各异，能力独特的朋友们，和他们一起击败强敌，找到生存的方法——同时，逐步发掘”西海岸“的真相。";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(10);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    三教主秉承师父鸿钧上人教诲，广收门徒将道教流传于世。只因入道门中即可修仙，使人跳出三界之外，不在五行之中，免除生死轮回之苦，使得入道修行之人多不胜数！但修仙之道并非苦心修炼便可达成。修行路上，均要经历三百年一小劫，一千五百年一大劫的劫数。修行之人均无法避开劫数，只能根据自身道行的深浅去经历劫数。";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    值商周两朝交替之时，恰逢修仙一千五百年仙劫，于是三教主共议封神榜，以观众仙道行浅深。然劫数难逃，封神一役，致使道门内部阐教和截教不和，修仙众人俱遭屠戮，更引来西方教派参与纷争，后因鸿钧上人亲自出面调停，终得以平息。";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    五百年后的中洲大陆，故事就发生在一个平凡冷清的小镇上。";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//	system("pause");
//
//	return 0;
//}
//
//
//
//typedef struct Text_
//{
//	int x;
//	int y;
//	WCHAR str[2];  //
//	COLORREF color; // unsigned int
//	struct Text_* next;  // 链表
//}Text;
//
//void text_init(Text* text, int x, int y, const WCHAR* str)
//{
//	text->x = x;
//	text->y = y;
//	wcsncpy(text->str, str, 1); // copy a chinese
//	text->color = RGB(rand() % 256, rand() % 256, rand() % 256);
//}
//
////对链表进行封装
//typedef struct
//{
//	int x, y;
//	int w; // 文字输出的最大宽度
//	Text* front;
//	Text* tail;
//	Text* curoutText;
//}TextList;
//void textList_init(TextList* list, int x, int y, int w, const WCHAR* str)
//{
//	list->x = x;
//	list->y = y;
//	list->w = w;
//	int row = 0, col = 0;
//	int len = wcslen(str);
//	for (int i = 0; i < len; i++)
//	{
//		// look for malloc
//		Text* newNode = (Text*)calloc(1, sizeof(Text)); // calloc 会初始化
//
//		int tx = x + col * textwidth("我");
//		int ty = y + row * textwidth("我");
//		text_init(newNode, tx, ty, str + i);
//		if (newNode->x > list->x + list->w || wcsncmp(newNode->str, L"\r\n", 1) == 0)
//		{
//			++row;
//			col = -1;
//		}
//		else
//		{
//			++col;
//		}
//
//		// link
//		if (list->front == NULL || list->tail == NULL)
//		{
//			list->front = newNode;
//			list->tail = newNode;
//		}
//		else
//		{
//			list->tail->next = newNode;
//			list->tail = newNode;
//		}
//	}
//	list->curoutText = list->front;
//}
//
//void textList_draw(TextList* list, int type = 0)
//{
//
//	// 逐字输出
//	Text* curNode = list->front;
//	while (curNode != list->curoutText)
//	{
//		if (type == 0) settextcolor(curNode->color);
//		else settextcolor(RGB(255, 255, 0));
//
//		char narrowStr[3];  // 假设每个WCHAR字符串只有一个字符
//		WideCharToMultiByte(CP_UTF8, 0, curNode->str, -1, narrowStr, sizeof(narrowStr), NULL, NULL);
//		outtextxy(curNode->x, curNode->y, narrowStr);  // 使用窄字符输出函数
//		//outtextxy(curNode->x, curNode->y, curNode->str);
//
//		curNode = curNode->next;
//	}
//
//	if (list->curoutText)
//	{
//
//		if (type == 0) settextcolor(list->curoutText->color); // 随机颜色 
//		else settextcolor(RGB(255, 255, 0));
//		//outtextxy(list->curoutText->x, list->curoutText->y, list->curoutText->str);
//		
//		char narrowStr[3]; // 假设每个WCHAR字符串只有一个字符
//		WideCharToMultiByte(CP_UTF8, 0, list->curoutText->str, -1, narrowStr, sizeof(narrowStr), NULL, NULL);
//		outtextxy(list->curoutText->x, list->curoutText->y, narrowStr); // 使用窄字符输出函数
//		
//		list->curoutText = list->curoutText->next;
//		Sleep(20);
//	}
//}
//
//
//void welcome()
//{
//	settextcolor(RED);
//	settextstyle(120, 0, "楷体");
//
//	TextList list = { 0 };
//	textList_init(&list, 300, 20, 800, L"海大侠客行");
//	int time = 1;
//	while (!_kbhit())
//	{
//		time++;
//		textList_draw(&list);
//		if (time > 3000) break;
//	}
//	TextList list3 = { 0 };
//	settextstyle(30, 0, "楷体");
//	settextcolor(RGB(0, 255, 0));
//	outtextxy(420, 140, "********************");
//	outtextxy(480, 180, "游戏制作信息\n");
//	outtextxy(420, 220, "********************");
//	outtextxy(300, 260, "  中国海洋大学2022夏季学期c++课程设计");
//	outtextxy(290, 300, "制作人：	戴志伟、董凯志、董博伟、曹勇、陈哲"	);
//
//	TextList list2 = { 0 };
//	settextstyle(20, 0, "楷体");
//	settextcolor(RGB(128, 0, 128));
//	outtextxy(530, 330, "故事背景");
//	textList_init(&list2, 200, 350, 800,
//		L"游戏发生在美国不知名高校“美国海洋大学”（Ocean University of American），在这里，被挂科之神选中的人将被授予“学业警示”，发配到西海岸校区（加利福尼亚州）。玩家将扮演一位名为”约翰“的大三学生，在荒凉破败的废墟中邂逅性格各异，能力独特的朋友们，和他们一起击败强敌，找到生存的方法——同时，逐步发掘”西海岸“的真相。\r\n"
//		/*"楷体\r\n"
//		"鹅鹅鹅\r\n"
//		"曲项向天歌aaaaaaaaaaaa11111\r\n"
//		"白毛浮绿水\r\n"
//		"圣诞节快乐\r\n"
//		"圣诞节快乐\r\n"*/);
//
//	// 检测是否有按键按下 有为true
//	while (!_kbhit())
//	{
//		textList_draw(&list2,1);
//	}
//	// 切换界面
//	//_getch(); // 获取字符
//
//	cleardevice();
//
//	system("pause");
//	closegraph();

	//WCHAR str[] = L"我喜欢你,阿斯顿发斯蒂芬";
	//outtextxy(200, 350, L"小D快乐");
//}
//
//
//
//
//
//
//int main()
//{
//
//	initgraph(1200, 800);
//	//SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
//	srand(time(NULL));
//	TextList list = { 0 };
//	welcome();
//
//	//initgraph(800, 600);
//	//mciSendString("play 23.mp3 repeat", 0, 0, 0);
//	//InitImg();
//	//while (1)
//	//{
//	//	BeginBatchDraw();
//	//	putimage(0, 0, &bg);
//	//	EndBatchDraw();
//	//}
//	welcomePage();
//	backgroundGame();
//	HANDLE hConsole;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 0xC);
//	string newGameMenu = "   1.新的游戏  2.读取存档  3.退出游戏";
//	for (int i = 0; i < newGameMenu.length(); i++) {
//		Sleep(20);
//		cout << newGameMenu[i];
//	}
//	int judge;
//	cin >> judge;
//	switch (judge)
//	{
//	case 1:
//	{
//		
//		break;
//	}
//	case 2:
//	{
//		break;
//
//	}
//	case 3:
//	{
//		return 0;
//	}
//	}
//	system("pause");//悬停
//
//	printf("hello world!");
//	return 0;
//
//
//}