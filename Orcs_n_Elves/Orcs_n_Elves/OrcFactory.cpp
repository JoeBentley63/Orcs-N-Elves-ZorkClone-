#include "OrcFactory.h"
/*
Orc Factory. Factory design pattern for instantiating orcs*/

OrcFactory* OrcFactory::_me;//also a singleton, so that there is only 1 source of the orcs


OrcFactory::OrcFactory(void)
{
}


OrcFactory::~OrcFactory(void)
{
}

Orc* OrcFactory::CreateOrc(string _name)//generate orcs simular to Units.
{
	//cout<<"Seed : " <<_name.length() << "name : " << _name;
	srand (_name.length());
	int _attack = rand() % 20;//random attributes based on its name
	int _defence = rand() % 20;
	int _health = rand() % 100;
	Unit::Weapon _weapon = Unit::MACE;//assign weapons
	Unit::Defensive _defensive = Unit::HELMET;
	Unit::Class _class = Unit::HEAVY;
	return new Orc(_weapon,_defensive,_class,_name);//create and return orc
}
OrcFactory* OrcFactory::GetInstance()
{
	if(_me == NULL)
	{
		_me = new OrcFactory();
	}
	return _me;
}