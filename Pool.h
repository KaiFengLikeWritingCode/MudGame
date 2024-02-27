#pragma once

#include "Fish.h"
#include "Leader.h"
#include <iostream>
using namespace std;

class Pool
{
public:
	int fishing(int randomValue, Leader& player);
private:
	Fish fish[5] = { 0,1,2,3,4 };
};
