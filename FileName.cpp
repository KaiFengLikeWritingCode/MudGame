//#define _CRT_SECURE_NO_DEPRECATE//��ֹsprintf����//#include<graphics.h>
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
//static TCHAR szWindowClass[] = _T("WindowClass"); //��������
//static TCHAR szTitle[] = _T("����������"); //���ڱ���
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
//	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "          ��Ϸ������Ϣ" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "      ********************" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "   �����ˣ��й������ѧ2022�ļ�ѧ��c++�γ����" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "	��־ΰ������־������ΰ�����¡�����" << endl << endl;
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
//	cout << "		   ���±���" << endl << endl;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 14);
//	string background = "    ���ɿ���֮�������ݴ�½����֮�۵ĺ�����˴������̣�����ͽ���ˣ������Ե��ž�������ͽ���޳ɻ�Ԫ���޽�����ٲ���֮�壬�ֱ�չ�����̵��˵������̺ͽؽ�������֧������ͽ�����˵�����̫���Ͼ������̽���Ԫʼ����ͽؽ̵�ͨ�������";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(10);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    ����������ʦ��������˽̻壬������ͽ����������������ֻ��������м������ɣ�ʹ����������֮�⣬��������֮�У���������ֻ�֮�࣬ʹ���������֮�˶಻ʤ����������֮�����ǿ���������ɴ�ɡ�����·�ϣ���Ҫ����������һС�٣�һǧ�����һ��ٵĽ���������֮�˾��޷��ܿ�������ֻ�ܸ���������е���ǳȥ����������";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    ֵ������������֮ʱ��ǡ������һǧ������ɽ٣��������������������Թ����ɵ���ǳ�Ȼ�������ӣ�����һ�ۣ���ʹ�����ڲ����̺ͽؽ̲��ͣ��������˾�����¾���������������ɲ���������������������Գ����ͣ���յ���ƽϢ��";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    ����������޴�½�����¾ͷ�����һ��ƽ�������С���ϡ�";
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
//	string newGameMenu = "   1.�µ���Ϸ  2.��ȡ�浵  3.�˳���Ϸ";
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
//	system("pause");//��ͣ
//
//	printf("hello world!");
//	return 0;
//
//
//}


////#define _CRT_SECURE_NO_DEPRECATE//��ֹsprintf����//#include<graphics.h>
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
////static TCHAR szWindowClass[] = _T("WindowClass"); //��������
////static TCHAR szTitle[] = _T("����������"); //���ڱ���
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
//	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "          ��Ϸ������Ϣ" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "      ********************" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "   �����ˣ��й������ѧ2022�ļ�ѧ��c++�γ����" << endl;
//	cout << '\t' << '\t' << '\t' << '\t' << "	��־ΰ������־������ΰ�����¡�����" << endl << endl;
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
//	cout << "		   ���±���" << endl << endl;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 14);
//	string background = "    ��Ϸ������������֪����У�����������ѧ����Ocean University of American������������ҿ�֮��ѡ�е��˽������衰ѧҵ��ʾ�������䵽������У���������������ݣ�����ҽ�����һλ��Ϊ��Լ�����Ĵ���ѧ�����ڻ����ưܵķ����������Ը���죬�������ص������ǣ�������һ�����ǿ�У��ҵ�����ķ�������ͬʱ���𲽷����������������ࡣ";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(10);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    ����������ʦ��������˽̻壬������ͽ����������������ֻ��������м������ɣ�ʹ����������֮�⣬��������֮�У���������ֻ�֮�࣬ʹ���������֮�˶಻ʤ����������֮�����ǿ���������ɴ�ɡ�����·�ϣ���Ҫ����������һС�٣�һǧ�����һ��ٵĽ���������֮�˾��޷��ܿ�������ֻ�ܸ���������е���ǳȥ����������";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    ֵ������������֮ʱ��ǡ������һǧ������ɽ٣��������������������Թ����ɵ���ǳ�Ȼ�������ӣ�����һ�ۣ���ʹ�����ڲ����̺ͽؽ̲��ͣ��������˾�����¾���������������ɲ���������������������Գ����ͣ���յ���ƽϢ��";
//	for (int i = 0; i < background.length(); i++) {
//		Sleep(5);
//		cout << background[i];
//	}
//	cout << endl;
//
//	cout << endl;
//	background = "    ����������޴�½�����¾ͷ�����һ��ƽ�������С���ϡ�";
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
//	struct Text_* next;  // ����
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
////��������з�װ
//typedef struct
//{
//	int x, y;
//	int w; // ��������������
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
//		Text* newNode = (Text*)calloc(1, sizeof(Text)); // calloc ���ʼ��
//
//		int tx = x + col * textwidth("��");
//		int ty = y + row * textwidth("��");
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
//	// �������
//	Text* curNode = list->front;
//	while (curNode != list->curoutText)
//	{
//		if (type == 0) settextcolor(curNode->color);
//		else settextcolor(RGB(255, 255, 0));
//
//		char narrowStr[3];  // ����ÿ��WCHAR�ַ���ֻ��һ���ַ�
//		WideCharToMultiByte(CP_UTF8, 0, curNode->str, -1, narrowStr, sizeof(narrowStr), NULL, NULL);
//		outtextxy(curNode->x, curNode->y, narrowStr);  // ʹ��խ�ַ��������
//		//outtextxy(curNode->x, curNode->y, curNode->str);
//
//		curNode = curNode->next;
//	}
//
//	if (list->curoutText)
//	{
//
//		if (type == 0) settextcolor(list->curoutText->color); // �����ɫ 
//		else settextcolor(RGB(255, 255, 0));
//		//outtextxy(list->curoutText->x, list->curoutText->y, list->curoutText->str);
//		
//		char narrowStr[3]; // ����ÿ��WCHAR�ַ���ֻ��һ���ַ�
//		WideCharToMultiByte(CP_UTF8, 0, list->curoutText->str, -1, narrowStr, sizeof(narrowStr), NULL, NULL);
//		outtextxy(list->curoutText->x, list->curoutText->y, narrowStr); // ʹ��խ�ַ��������
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
//	settextstyle(120, 0, "����");
//
//	TextList list = { 0 };
//	textList_init(&list, 300, 20, 800, L"����������");
//	int time = 1;
//	while (!_kbhit())
//	{
//		time++;
//		textList_draw(&list);
//		if (time > 3000) break;
//	}
//	TextList list3 = { 0 };
//	settextstyle(30, 0, "����");
//	settextcolor(RGB(0, 255, 0));
//	outtextxy(420, 140, "********************");
//	outtextxy(480, 180, "��Ϸ������Ϣ\n");
//	outtextxy(420, 220, "********************");
//	outtextxy(300, 260, "  �й������ѧ2022�ļ�ѧ��c++�γ����");
//	outtextxy(290, 300, "�����ˣ�	��־ΰ������־������ΰ�����¡�����"	);
//
//	TextList list2 = { 0 };
//	settextstyle(20, 0, "����");
//	settextcolor(RGB(128, 0, 128));
//	outtextxy(530, 330, "���±���");
//	textList_init(&list2, 200, 350, 800,
//		L"��Ϸ������������֪����У�����������ѧ����Ocean University of American������������ҿ�֮��ѡ�е��˽������衰ѧҵ��ʾ�������䵽������У���������������ݣ�����ҽ�����һλ��Ϊ��Լ�����Ĵ���ѧ�����ڻ����ưܵķ����������Ը���죬�������ص������ǣ�������һ�����ǿ�У��ҵ�����ķ�������ͬʱ���𲽷����������������ࡣ\r\n"
//		/*"����\r\n"
//		"����\r\n"
//		"���������aaaaaaaaaaaa11111\r\n"
//		"��ë����ˮ\r\n"
//		"ʥ���ڿ���\r\n"
//		"ʥ���ڿ���\r\n"*/);
//
//	// ����Ƿ��а������� ��Ϊtrue
//	while (!_kbhit())
//	{
//		textList_draw(&list2,1);
//	}
//	// �л�����
//	//_getch(); // ��ȡ�ַ�
//
//	cleardevice();
//
//	system("pause");
//	closegraph();

	//WCHAR str[] = L"��ϲ����,��˹�ٷ�˹�ٷ�";
	//outtextxy(200, 350, L"СD����");
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
//	string newGameMenu = "   1.�µ���Ϸ  2.��ȡ�浵  3.�˳���Ϸ";
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
//	system("pause");//��ͣ
//
//	printf("hello world!");
//	return 0;
//
//
//}