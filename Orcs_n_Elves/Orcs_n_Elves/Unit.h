#ifndef _UNIT_H
#define _UNIT_H
#include<iostream>
#include<string>
using namespace std;
class Unit
{
public:
	
	int _attackCoolDown;//cooldown variables
	int _defenceCoolDown;

	enum Weapon//enums for various characteristics
	{
		BROADSWORD = 0,
		MACE = 1,
		SHORTSWORD = 2,
		DAGGER = 3,
		BOW = 4,
		TANTO = 5,
		KATANA = 6,
		SPEAR = 7
	};
	enum Defensive
	{
		SHIELD = 0,
		EXTRAARMOR = 1,
		HELMET = 2,
	};
	enum Class
	{
		LIGHT = 0,
		MEDIUM = 1,
		HEAVY = 2,
	};

	Weapon _weapon;
	Defensive _defensive;
	Class _class;

	string _name;
	int _attack;
	int _defence;
	int _speed;
	int _health;
	int _attackBuff;//buffs and powerups to various stats
	int _defenceBuff;
	int _speedBuff;
	int _lives;
	Unit();
	virtual ~Unit(void);
	virtual void Attack(Unit* _unit);
	virtual void PrintStats();
	virtual void Draw();
};

#endif