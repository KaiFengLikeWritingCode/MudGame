#include "Object.h"

void Object::init_style(int new_style) { style = new_style; } // 初始化装备类型
int Object::get_value() { return value; }
int Object::get_style() { return style; }
string Object::getIntroduce()
{
	//cout << "-1";
	cout << introduce;
	return introduce;
}