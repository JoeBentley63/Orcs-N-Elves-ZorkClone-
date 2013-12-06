#include "Unit.h"
/*
Super class for the units in the turnbased section of the game
*/
using namespace std;
Unit::Unit()
{
}


Unit::~Unit(void)
{
}

void Unit::Attack(Unit* _unit)//every unit needed to attack.
{
}

void Unit::PrintStats()//print the various variables that make the unit unique
{
	cout<<"\nStats--------------";
	cout<<"\n Attack : " << _attack + _attackBuff;
	cout<<"\n Defence : " << _defence + _defenceBuff;
	cout<<"\n Speed : " << this->_speed + _speedBuff;
	cout<<"\n Health : " << this->_health;
	cout<<"\n Lives : " << this->_lives;
}

void Unit::Draw()//debug function
{
	cout<<"\nStats \n\n attack " << _attack << ", Defence " << _defence << "Health" << _health<< ", Name : " << _name ;
}
	