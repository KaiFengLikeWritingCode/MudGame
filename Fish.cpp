#include "Fish.h"


Fish::Fish(int id)
{
	switch (id)
	{
	case 0: {
		type = id;
		name = "…≥∂°”„";
		chance = 0.5;
		price = 10;
		break;
	}
	case 1: {
		type = id;
		name = "∑¯µ∫”„";
		chance = 0.15;
		price = 30;
		break;
	}
	case 2: {
		type = id;
		name = "ˆË”„";
		chance = 0.05;
		price = 50;
		break;
	}
	case 3: {
		type = id;
		name = "∫£πÍ";
		chance = 0.04;
		price = 150;
		break;
	}
	case 4: {
		type = id;
		name = "√¿»À”„";
		chance = 0.02;
		price = 15000;
		break;
	}
	default:
		break;
	}
}
string Fish::getName()
{
	return name;
}
int Fish::gettype()
{
	return type;
}
int Fish::getPrice()
{
	return price;
}
int Fish::getChance()
{
	return chance;
}