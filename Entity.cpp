#include "Entity.h"

string Entity::get_name() { return name; }
int Entity::get_id() { return id; }
int Entity::get_id_mp(string name) { return id_mp[name]; }
void Entity::change_name(string _name) { name = _name; }
void Entity::change_id(int _id) { id = _id; }