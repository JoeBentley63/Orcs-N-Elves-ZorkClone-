#ifndef _ORC_H
#define _ORC_H
#include "Unit.h"
#include <iostream>

using namespace std;
class Orc :
	public Unit
{
public:
	Orc(Weapon _weapon,Defensive _defensive,Class _class,string _name);
	~Orc(void);
private:
	void GeneratePlayerStats();
    void Attack(Unit* _unit);
};

#endif