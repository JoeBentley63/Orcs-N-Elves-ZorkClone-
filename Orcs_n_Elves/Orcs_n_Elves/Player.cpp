#include "Player.h"
/*The user controlled Unit in the game.Used to store all the various attributes*/

Player::Player(Weapon _weapon,Defensive _defensive,Class _class,string _name)
{
	this->_name = _name;//assign the variables based on arguments
	this->_weapon = _weapon;
	this->_defensive = _defensive;
	this->_class = _class;
	this->_attackCoolDown = 0;
	this->_defenceCoolDown = 0;
	this->_lives = 3;
	GeneratePlayerStats();

}

void Player::GeneratePlayerStats()//generate the states
{
	srand (_name.length());
	_attack = rand() % 20;//so first we generate some randoms as the base values
	_defence = rand() % 20;
	_health = rand() % 20;
	_speed =  rand() % 20;
	_attackBuff = 0;
	_speedBuff = 0;
	_defenceBuff = 0;
	switch(_class)//based on the class, we then increment or decrement various attributes
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

	switch(_weapon)//based on the weapon, we then increment or decrement various attributes
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

	switch(_defensive)//based on the Defensive, we then increment or decrement various attributes
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
	cout<<"\n By my calculations...that makes your stats :";//print final stats
	cout<<"\n Name : " << _name;
	cout<<"\n Attack : " << _attack;
	cout<<"\n Defence : " << _defence;
	cout<<"\n Speed : " << this->_speed;

	
}
void Player::Attack(Unit* _unit)//this unit attacks another unit
{
	_unit->_health -= (_unit->_defence-(_attack + _attackBuff)/2);
	cout<<(_unit->_defence-(_attack + _attackBuff)/2) << " Damage!!";
}
Player::~Player(void)
{
}
