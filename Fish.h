#pragma once
#include <string>
#include <iostream>

using namespace std;

class Fish
{
public:
	Fish(int id);
	~Fish() {}
	string getName();
	int gettype();
	int getPrice();
	int getChance();
private:
	string name;
	int type;
	int price;
	int chance;
};

