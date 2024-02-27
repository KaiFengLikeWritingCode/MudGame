#define _CRT_SECURE_NO_DEPRECATE//��ֹsprintf����//#include<graphics.h>
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
	struct Text_* next;  // ����
}Text;
//��������з�װ
typedef struct
{
	int x, y;
	int w; // ��������������
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
	SetConsoleTitle(L"����������");
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
		cout << "**�ɹ��˳���" << endl;
		return 0;
	}
	}
	system("pause");//��ͣ

	return 0;


}

int backgroundGame()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	//system("cls");
	//cout << "		   " << "���±���" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	//string background = "    ��Ϸ������������֪����У�����������ѧ����Ocean University of American������������ҿ�֮��ѡ�е��˽������衰ѧҵ��ʾ�������䵽������У���������������ݣ�����ҽ�����һλ��Ϊ��Լ�����Ĵ���ѧ�����ڻ����ưܵķ����������Ը���죬�������ص������ǣ�������һ�����ǿ�У��ҵ�����ķ�������ͬʱ���𲽷����������������ࡣ";
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
	string newGameMenu = "   1.�µ���Ϸ  2.��ȡ�浵  3.�˳���Ϸ";
	for (int i = 0; i < newGameMenu.length(); i++) {
		//Sleep(20);
		cout << newGameMenu[i];
	}
	cout << endl << endl<< "*���ѡ��";
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
		Text* newNode = (Text*)calloc(1, sizeof(Text)); // calloc ���ʼ��

		int tx = x + col * textwidth(L"��");
		int ty = y + row * textwidth(L"��");
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

	// �������
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
		if (type == 0) settextcolor(list->curoutText->color); // �����ɫ 
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
	fontInfo.dwFontSize.X = 20;  // ����������
	fontInfo.dwFontSize.Y = 20; // ��������߶�
	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, 1200, 850, TRUE);
	cout << "\t\t\t\t\t\t    " << "\x1b[3;4;1m";
	cout << "����������" << endl;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << '\t' << '\t' << '\t' << '\t';
	cout << '\t' << "      ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "          ��Ϸ������Ϣ" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "      ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "    " << "\x1b[3;4;1m" << "�����ˣ��й������ѧ2022�ļ�ѧ��c++�γ����" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "\t" << "\x1b[3;4;1m" << "��־ΰ������־������ΰ�����¡�����" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t';
	cout << endl << endl << '\t' << '\t' << '\t' << '\t' << "   ";
	return 0;

}
void welcome()
{
	settextcolor(RED);
	settextstyle(120, 0, L"����");

	TextList list = { 0 };
	textList_init(&list, 300, 20, 800, L"����������");
	int time = 1;
	while (!_kbhit())
	{
		time++;
		textList_draw(&list, 0);
		if (time > 3000) break;
	}
	time = 0;
	settextstyle(30, 0, L"����");
	settextcolor(RGB(0, 255, 0));
	outtextxy(420, 140, L"********************");
	outtextxy(480, 180, L"��Ϸ������Ϣ\n");
	outtextxy(420, 220, L"********************");
	outtextxy(300, 260, L"  �й������ѧ2022�ļ�ѧ��c++�γ����");
	outtextxy(290, 300, L"�����ˣ�	��־ΰ������־������ΰ�����¡�����");

	TextList list2 = { 0 };
	settextstyle(20, 0, L"����");
	settextcolor(RGB(128, 0, 128));
	outtextxy(530, 330, L"���±���");
	textList_init(&list2, 200, 350, 800,
		L"��Ϸ������������֪����У�����������ѧ����Ocean University of American������������ҿ�֮��ѡ�е��˽������衰ѧҵ��ʾ�������䵽������У���������������ݣ�����ҽ�����һλ��Ϊ��Լ�����Ĵ���ѧ�����ڻ����ưܵķ����������Ը���죬�������ص������ǣ�������һ�����ǿ�У��ҵ�����ķ�������ͬʱ���𲽷����������������ࡣ\r\n"
		);

	// ����Ƿ��а������� ��Ϊtrue
	while (!_kbhit())
	{
		time++;
		textList_draw(&list2, 1);
		if (time > 1000) break;
	}
	Sleep(4000);
	time = 0;
	cleardevice();
	settextstyle(50, 0, L"����");
	TextList list3 = { 0 };
	textList_init(&list3, 100, 50, 1100,
		L"201X�꣬�����Ͷ���У������Ϊȫ������У��\r\n"
		"��Ҫԭ����\r\n"
		"���������µ�ѧ������λ��ȫ����һ\r\n"
		"�޷����ϣ�����ʵ�������\r\n"
		"��У���ܻ����һ˿ϣ��\r\n"
		"����Ҳ��\r\n"
		"�þ�Ҳ��\r\n"
		"���ͽ������\r\n"
		"�·��ֿɼ�\r\n"
		"������������\r\n"
		"�ưܵ�У��\r\n"
		"����������֮��....\r\n"
	);
	//Sleep(600)
	while (!_kbhit())
	{
		time++;
		textList_draw(&list3, 1);
		if (time > 800) break;
	}
	cleardevice();
	settextstyle(40, 0, L"����");
	TextList list4 = { 0 };
	textList_init(&list4, 100, 50, 900,
		L"�ҵ�������Լ��ʷ��˹���ͽ���Լ���ɡ�\r\n"
		"�����������������ѧ��һλ�ŵ������������׵��������������˼��ѧ����Ԣ��24Сʱ��ˮ��Ӧ������Ϊ���������ǵ�ʳ�ã���У�ž������������������\r\n"
		"Ȼ�����ڴ��ʱ����żȻ�Ӵ�����һ�����й���ѧ������Ŀ���������Ϸ���������������𽥽��������˲�ͬ�Ĺ���������أ����뿪��ԭ����ѧҵ���壬���ϳ�������Ϸ�����������У���ҿƵ���Ӱ��������\r\n"
		"���������ѧ�ڼ�������������һ��������У������������У�������������������ȥ��ѧУ����ʦ��������������¶��ɫ��Ȼ��ת�ƻ��⡣����ʵÿ���˶����������У���Ǹ����͸���ĵط���ѧУÿ�궼��ѵõ�ѧҵ��ʾ��ѧ�����ŵ�������У����\r\n"
		"���գ��Ҳ���ӭ����ѧҵ��ʾ����Ϊ�����ŵ���������ѧ��֮һ�������ŵķ���֮�س�Ϊ�����µ���ʵ�������ľ������������Ĺ���γ��������ĶԱȡ�����Ƭ���ߵ������ϣ��ҽ����ò�Ѱ������ķ�����\r\n"
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
	"Զ�������ĳ��У�λ�ڼ����������ݵ����������ѧ������У����������һ��������������У԰��������ѵĺ���λ�ú�׿Խ�Ľ���������������\n",
	"Ȼ����ĳ��δ֪���¼��ı���һ�У�����Ƭ������У�������һƬ���صĻ������档\n",
	"���У������������̾Ϊ��ֹ�Ľ��������Ĳ�ƺ������ɢ����������Ϣ��ͼ��ݡ��ڹ�ȥ��ѧ���������������֪ʶ�ĺ����У����¸���ѧ���о��������\n",
	"Ȼ����ĳһ�죬һ���޷����͵��¼������ˣ�����У��������һƬ����֮�С�\n",
	"����¼�ʹУ����û��ߣ��������ưܣ�ֲ����ή��һ�����յķ��پ��󶼵�Ȼ�޴档ѧУ������ͣ�٣�������뿪�ˣ�ֻ�������Ҵ���������Ƭ����֮�У���ͼ����Ƭ������������ȥ��\n",
	"......\n",
	"Լ����������֮һ......"
	};
	for (int i = 0; i < 7; i++) {
		cout << text_environment[i];
		Sleep(800);
	}
	cout << endl;
	system("pause");
	system("cls");
	string text_begin[16] = {
	"Լ�����յ��������е����İ������Լ��ҵ������ɡ�ԭ��������",
	"�����Ÿ����ѣ��ҳ���ԭ����������",
	"����A�����У��Ҷ�ԭ��������",
	"����B����Ҳ�ǣ��̲���һ�㡣",
	"Լ��������ԭ�������ô�����ˣ����Ǹò�������Ƥ�ɡ�",
	"������C�붯�ֵ���һ�Ե�����D��ֹ�ˣ�",
	"����E����Ҫ��ܣ���Ҫ��ܡ�������������������ˣ����ᵱȻҲҪʵ�������������ɣ�������һ��ͶƱ��ͬ�������ԭ�����Ű��������������֡�",
	"���㱻9��1Ͷ�˳�ȥ��",
	"�������������¥��һ�߿�����һ������ԭ��",
	"Լ�����������ΪʲôҪ����Ϊ������ԭ����ҡ���ֻ����ʹ�ҷ���ԭ�������֮����ϣ�����������ҵ�������顣�ٺٺ٣�ԭ������档",
	"���޹ܰ��̴�ʱע�⵽���㣩",
	"�޹ܰ��̣�С���ӣ�ԭ����Ҳ��ԭ��",
	"Լ�����ǰ����ǰ��������ֻ�����Ŀ�������3A������˭��ϲ���أ�",
	"�޹ܰ��̣�����ΪʲôҪ��¥�������أ�",
	"��Լ��������ľ��������˰��̣�",
	"�޹ܰ��̣��ҿ���ԭ��ʮ������ң�ԭ�����ѣ��Ҳ��ܲ��ܡ������ɣ��ҵķ�����һ���մ�λ������ʰ��ʰ�Ժ��˯���ǰɡ�"
	};
	cout << "\t\t\t\t" << "�ص�:"  << "\x1b[36m"<< "����" << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	for (int i = 0; i < 16; i++) {
		Sleep(800);
		cout << text_begin[i] << endl;
	}																																																			
	system("pause");
}