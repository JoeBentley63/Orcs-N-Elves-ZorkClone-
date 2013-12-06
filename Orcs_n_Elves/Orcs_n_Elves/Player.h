#ifndef _PLAYER_H
#define _PLAYER_H
#include "Unit.h"
#include <iostream>

using namespace std;
class Player :
	public Unit
{
public:
	Player(Weapon _weapon,Defensive _defensive,Class _class,string _name);
	~Player(void);
private:
	void GeneratePlayerStats();
    void Attack(Unit* _unit);
};

#endif