#ifndef _BATTLE_H
#define _BATTLE_H

#include "Unit.h"
#include <time.h>
#include <string.h>
class Battle
{
public:
	Unit* _player;
	Unit* _orc;
	string _quotes[4];
	Battle(Unit* _player,Unit* _orc);
	void DoAnAttack(Unit* _attacker,Unit* _target,int _selection);
	~Battle(void);
	void StartBattle();
};

#endif
