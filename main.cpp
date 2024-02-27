#define _CRT_SECURE_NO_DEPRECATE//防止sprintf报错//#include<graphics.h>
#include "Map.h"
#include <easyx.h>
#include<conio.h>
#include <time.h>
#include "System.h"

#pragma comment(lib,"winmm.lib")
using namespace std;
typedef struct Text_
{
	int x;
	int y;
	WCHAR str[2];  //
	COLORREF color; // unsigned int
	struct Text_* next;  // 链表
}Text;
//对链表进行封装
typedef struct
{
	int x, y;
	int w; // 文字输出的最大宽度
	Text* front;
	Text* tail;
	Text* curoutText;
}TextList;

//void InitImg();
int welcomePage();
int backgroundGame();
void Loading_interface();

void text_init(Text* text, int x, int y, const WCHAR* str);
void textList_init(TextList* list, int x, int y, int w, const WCHAR* str);
//void textList_draw(TextList* list);
void welcome();
void game_begin_welcome();

int main()
{
	//System game_system;
	SetConsoleTitle(L"海大侠客行");
	initgraph(1200, 800);
	srand(time(NULL));

	TextList list = { 0 };
	welcome();
	
	//system("color f4");
	//initgraph(800, 600);
	//mciSendString(L"play 23.mp3 repeat", 0, 0, 0);
	//InitImg();
	//while (1)
	//{
	//	BeginBatchDraw();
	//	putimage(0, 0, &bg);
	//	EndBatchDraw();
	//}
	System game_system;
	//Map game_map;
	Loading_interface();
	cout << ">>";
	int judge;
	cin >> judge;
	switch (judge)
	{
	case 1:
	{
		game_begin_welcome();
		game_system.begin(/*game_map*/);
		break;
	}
	case 2:
	{
		game_system.file_read();
		game_system.begin(/*game_map*/);
		break;
	}
	case 3:
	{
		cout << "**成功退出！" << endl;
		return 0;
	}
	}
	system("pause");//悬停

	return 0;


}

int backgroundGame()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	//system("cls");
	//cout << "		   " << "故事背景" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	//string background = "    游戏发生在美国不知名高校“美国海洋大学”（Ocean University of American），在这里，被挂科之神选中的人将被授予“学业警示”，发配到西海岸校区（加利福尼亚州）。玩家将扮演一位名为”约翰“的大三学生，在荒凉破败的废墟中邂逅性格各异，能力独特的朋友们，和他们一起击败强敌，找到生存的方法——同时，逐步发掘”西海岸“的真相。";
	//for (int i = 0; i < background.length(); i++) {
	//	Sleep(1);
	//	cout << background[i];
	//}
	
	//getchar();

	return 0;
}
void Loading_interface()
{
	welcomePage();
	backgroundGame();
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0xC);
	string newGameMenu = "   1.新的游戏  2.读取存档  3.退出游戏";
	for (int i = 0; i < newGameMenu.length(); i++) {
		//Sleep(20);
		cout << newGameMenu[i];
	}
	cout << endl << endl<< "*你的选择";
}


void text_init(Text* text, int x, int y, const WCHAR* str)
{
	text->x = x;
	text->y = y;
	wcsncpy(text->str, str, 1); // copy a chinese
	text->color = RGB(rand() % 256, rand() % 256, rand() % 256);
}
void textList_init(TextList* list, int x, int y, int w, const WCHAR* str)
{
	list->x = x;
	list->y = y;
	list->w = w;
	int row = 0, col = 0;
	int len = wcslen(str);
	for (int i = 0; i < len; i++)
	{
		// look for malloc
		Text* newNode = (Text*)calloc(1, sizeof(Text)); // calloc 会初始化

		int tx = x + col * textwidth(L"我");
		int ty = y + row * textwidth(L"我");
		text_init(newNode, tx, ty, str + i);
		if (newNode->x > list->x + list->w || wcsncmp(newNode->str, L"\r\n", 1) == 0)
		{
			++row;
			col = -1;
		}
		else
		{
			++col;
		}

		// link
		if (list->front == NULL || list->tail == NULL)
		{
			list->front = newNode;
			list->tail = newNode;
		}
		else
		{
			list->tail->next = newNode;
			list->tail = newNode;
		}
	}
	list->curoutText = list->front;
}
void textList_draw(TextList* list, int type = 0)
{

	// 逐字输出
	Text* curNode = list->front;
	while (curNode != list->curoutText)
	{
		if(type == 0) settextcolor(curNode->color);
		else settextcolor(RGB(255, 255, 0));
		outtextxy(curNode->x, curNode->y, curNode->str);
		curNode = curNode->next;
	}

	if (list->curoutText)
	{
		if (type == 0) settextcolor(list->curoutText->color); // 随机颜色 
		else settextcolor(RGB(255, 255, 0));
		outtextxy(list->curoutText->x, list->curoutText->y, list->curoutText->str);
		list->curoutText = list->curoutText->next;
		Sleep(5); // !!
	}
}

int welcomePage()
{
	HANDLE hConsole;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	fontInfo.dwFontSize.X = 20;  // 设置字体宽度
	fontInfo.dwFontSize.Y = 20; // 设置字体高度
	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, 1200, 850, TRUE);
	cout << "\t\t\t\t\t\t    " << "\x1b[3;4;1m";
	cout << "海大侠客行" << endl;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << '\t' << '\t' << '\t' << '\t';
	cout << '\t' << "      ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "          游戏制作信息" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "      ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "    " << "\x1b[3;4;1m" << "制作人：中国海洋大学2022夏季学期c++课程设计" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "\t" << "\x1b[3;4;1m" << "戴志伟、董凯志、董博伟、曹勇、陈哲" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t';
	cout << endl << endl << '\t' << '\t' << '\t' << '\t' << "   ";
	return 0;

}
void welcome()
{
	settextcolor(RED);
	settextstyle(120, 0, L"楷体");

	TextList list = { 0 };
	textList_init(&list, 300, 20, 800, L"海大侠客行");
	int time = 1;
	while (!_kbhit())
	{
		time++;
		textList_draw(&list, 0);
		if (time > 3000) break;
	}
	time = 0;
	settextstyle(30, 0, L"楷体");
	settextcolor(RGB(0, 255, 0));
	outtextxy(420, 140, L"********************");
	outtextxy(480, 180, L"游戏制作信息\n");
	outtextxy(420, 220, L"********************");
	outtextxy(300, 260, L"  中国海洋大学2022夏季学期c++课程设计");
	outtextxy(290, 300, L"制作人：	戴志伟、董凯志、董博伟、曹勇、陈哲");

	TextList list2 = { 0 };
	settextstyle(20, 0, L"楷体");
	settextcolor(RGB(128, 0, 128));
	outtextxy(530, 330, L"故事背景");
	textList_init(&list2, 200, 350, 800,
		L"游戏发生在美国不知名高校“美国海洋大学”（Ocean University of American），在这里，被挂科之神选中的人将被授予“学业警示”，发配到西海岸校区（加利福尼亚州）。玩家将扮演一位名为”约翰“的大三学生，在荒凉破败的废墟中邂逅性格各异，能力独特的朋友们，和他们一起击败强敌，找到生存的方法——同时，逐步发掘”西海岸“的真相。\r\n"
		);

	// 检测是否有按键按下 有为true
	while (!_kbhit())
	{
		time++;
		textList_draw(&list2, 1);
		if (time > 1000) break;
	}
	Sleep(4000);
	time = 0;
	cleardevice();
	settextstyle(50, 0, L"楷体");
	TextList list3 = { 0 };
	textList_init(&list3, 100, 50, 1100,
		L"201X年，我所就读的校区被评为全美最烂校区\r\n"
		"主要原因呢\r\n"
		"及格线以下的学生数量位列全国第一\r\n"
		"无法否认，可事实就是如此\r\n"
		"这校区总会给你一丝希望\r\n"
		"谎言也好\r\n"
		"幻觉也罢\r\n"
		"但就近在咫尺\r\n"
		"仿佛触手可及\r\n"
		"让你舍生忘死\r\n"
		"破败的校区\r\n"
		"我正是求生之人....\r\n"
	);
	//Sleep(600)
	while (!_kbhit())
	{
		time++;
		textList_draw(&list3, 1);
		if (time > 800) break;
	}
	cleardevice();
	settextstyle(40, 0, L"楷体");
	TextList list4 = { 0 };
	textList_init(&list4, 100, 50, 900,
		L"我的名字是约翰史密斯，就叫我约翰吧。\r\n"
		"我曾经是美国海洋大学的一位优等生，有着优渥的生活条件。单人间的学生公寓，24小时热水供应，被评为米其林三星的食堂，出校门就是美国最繁华的市区。\r\n"
		"然而，在大二时，我偶然接触到了一款由中国留学生引入的开放世界游戏，这个意外的邂逅逐渐将我引向了不同的轨道。渐渐地，我离开了原本的学业顶峰，不断沉浸在游戏的虚拟世界中，与挂科的阴影逐渐拉近。\r\n"
		"美国海洋大学在加利福利亚州有一个西海岸校区，但是在主校区很少有人提起。如果你去问学校的老师，他们往往会面露难色，然后转移话题。但其实每个人都清楚西海岸校区是个糟糕透顶的地方。学校每年都会把得到学业警示的学生流放到西海岸校区。\r\n"
		"最终，我不幸迎来了学业警示，成为被流放到西海岸的学生之一。被流放的废土之地成为了我新的现实，荒凉的景象与我曾经的光辉形成了鲜明的对比。在这片荒芜的土地上，我将不得不寻找生存的方法。\r\n"
	);
	while (!_kbhit())
	{
		time++;
		textList_draw(&list4, 1);
		if (time > 1600) break;
	}
	Sleep(600);
	cleardevice();
	closegraph();
}

void game_begin_welcome()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	system("cls");
	string text_environment[7] = {
	"远离喧嚣的城市，位于加利福尼亚州的美国海洋大学西海岸校区，曾经是一座宁静、美丽的校园，以其绝佳的海滨位置和卓越的教育声誉而闻名。\n",
	"然而，某次未知的事件改变了一切，将这片宁静的校区变成了一片神秘的荒凉废墟。\n",
	"这个校区曾有着令人叹为观止的建筑，宽敞的草坪，还有散发着书香气息的图书馆。在过去，学生们在这里沉浸在知识的海洋中，从事各种学术研究和社会活动。\n",
	"然而，某一天，一个无法解释的事件发生了，整个校区陷入了一片混乱之中。\n",
	"这个事件使校区变得荒芜，建筑物破败，植被枯萎，一切昔日的繁荣景象都荡然无存。学校陷入了停顿，许多人离开了，只有少数幸存者留在这片废墟之中，试图在这片荒凉中生存下去。\n",
	"......\n",
	"约翰就是其中之一......"
	};
	for (int i = 0; i < 7; i++) {
		cout << text_environment[i];
		Sleep(800);
	}
	cout << endl;
	system("pause");
	system("cls");
	string text_begin[16] = {
	"约翰：刚到新宿舍有点无聊啊，给自己找点事做吧。原神，启动！",
	"其他九个舍友：我超，原！（齐声）",
	"舍友A：不行，我对原批过敏。",
	"舍友B：我也是，忍不了一点。",
	"约翰：我们原神玩家怎么你们了，你们该不会是皱皮吧。",
	"（舍友C想动手但被一旁的舍友D制止了）",
	"舍友E：不要打架，不要打架。我们现在是民主社会了，宿舍当然也要实行民主。这样吧，我们来一个投票，同意让这个原批带着包滚出宿舍的请举手。",
	"（你被9：1投了出去）",
	"（你带着行李在楼道一边哭泣，一边启动原神）",
	"约翰：这个世界为什么要处处为难我们原神玩家。我只是想和大家分享原神的美妙之处，希望大家能理解我的这份心情。嘿嘿嘿，原神真好玩。",
	"（宿管阿姨此时注意到了你）",
	"宿管阿姨：小伙子，原来你也玩原神。",
	"约翰：是啊，是啊。能在手机上玩的开放世界3A大作，谁不喜欢呢？",
	"宿管阿姨：可你为什么要在楼道上玩呢？",
	"（约翰把事情的经过告诉了阿姨）",
	"宿管阿姨：我可是原神十年老玩家，原友有难，我不能不管。这样吧，我的房间有一个空床位，你收拾收拾以后就睡在那吧。"
	};
	cout << "\t\t\t\t" << "地点:"  << "\x1b[36m"<< "宿舍" << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	for (int i = 0; i < 16; i++) {
		Sleep(800);
		cout << text_begin[i] << endl;
	}																																																			
	system("pause");
}