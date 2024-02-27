#pragma once
// ΚµΜε
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

class Entity 
{
private:
	string name;
	int id;
	map<string, int> id_mp;
public:
	string get_name();
	int get_id();
	int get_id_mp(string name);
	void change_name(string _name);
	void change_id(int _id);

	Entity(string name, int id) : name(name), id(id) { id_mp[name] = id; }
	Entity() { name = "NULL", id = -1; }
	Entity(const Entity& p)
	{
		name = p.name;
		id = p.id;
		id_mp = p.id_mp;
	}
	Entity& operator=(const Entity& p)
	{
		if (this != &p)
		{
			name = p.name;
			id = p.id;
			id_mp = p.id_mp;
		}
		return *this;
	}
	void setName(string _name) { name = _name; }

};