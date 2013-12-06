#include "Orc.h"
/*Orc Unit, produced by factory to fight the player*/

Orc::Orc(Weapon _weapon,Defensive _defensive,Class _class,string _name)
{
	this->_name = _name;//assign variables
	this->_weapon = _weapon;
	this->_defensive = _defensive;
	this->_class = _class;
	this->_lives = 1;
	this->_attackCoolDown = 0;
	this->_defenceCoolDown = 0;
	GeneratePlayerStats();

}

void Orc::GeneratePlayerStats()//generate stats, same as players function
{
	srand (_name.length());
	_attack = rand() % 20;
	_defence = rand() % 20;
	_health = rand() % 20;
	_speed =  rand() % 20;
	_attackBuff = 0;
	_speedBuff = 0;
	_defenceBuff = 0;
	switch(_class)
	{
	case HEAVY:
		_attack += 10;
		_speed -= 4;
		_defence += 5;
		break;

	case MEDIUM:
		_attack += 4;
		_defence += 2;
		break;

	case LIGHT:
		_attack -=3;
		_speed += 5;
		_defence -=2;
		break;
	}

	switch(_weapon)
	{
	case BROADSWORD:
		_attack += 5;

		break;
	case MACE:
		_attack += 10;
		_speed -= 1;

		break;

	case SHORTSWORD:
		_speed += 1;
		_attack+=1;
		break;
	case DAGGER:
		_speed += 3;
		_attack += 1;

		break;
	case BOW:
		_speed += 10;
		_attack -= 2;
		_defence -=2;
		break;

	case TANTO:
		_speed +=2;
		_attack +=2;

		break;

	case KATANA:
		_attack += 10;
		_speed += 7;
		_defence -= 4;
		break;

	case SPEAR:
		_attack += 2;
		_speed -= 1;
		_defence -= 1;
		break;
	}

	switch(_defensive)
	{
	case SHIELD:
		_defence+= 10;
		_speed -= 1;
		_attack += 1;
		break;

	case EXTRAARMOR:
		_defence += 12;
		_speed -= 1;
		break;

	case HELMET:
		_defence += 5;
		_speed += 4;

		break;
	}

}
void Orc::Attack(Unit* _unit)
{
	_unit->_health -= (_attack + _attackBuff) / 4;
	cout<<(_attack + _attackBuff) /4 << " Damage!!";

}
Orc::~Orc(void)
{
}
