#include "Object.h"

void Object::init_style(int new_style) { style = new_style; } // ��ʼ��װ������
int Object::get_value() { return value; }
int Object::get_style() { return style; }
string Object::getIntroduce()
{
	//cout << "-1";
	cout << introduce;
	return introduce;
}