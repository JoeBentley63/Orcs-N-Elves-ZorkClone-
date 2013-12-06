#include "Battle.h"
/*A Battle, between the player and an orc.*/
Battle::Battle(Unit* _player,Unit* _orc)
{
	this->_player = _player;//the player involved, and the orc
	this->_orc = _orc;
	//quotes for when your lives hit 0
	this->_quotes[0] = "All that live must die, passing through nature to eternity. \n -:William Shakespeare(1564-1616) ";
	this->_quotes[1] = "To fear death, my friends, is only to think ourselves wise, without being wise: for it is to think that we know what we do not know. For anything that men can tell, death may be the greatest good that can happen to them: but they fear it as if they knew quite well that it was the greatest of evils. And what is this but that shameful ignorance of thinking that we know what we do not know?\n :-Socrates (BC 469-BC 399)" ;
	this->_quotes[2] = "When a great man dies, for years the light he leaves behind him, lies on the paths of men. \n:-Henry Wadsworth Longfellow (1807-1882)";
	this->_quotes[3] = "If a man hasn't discovered something that he will die for, he isn't fit to live. \n :-Martin Luther King Jr. (1929-1968)";
	StartBattle();//start the battle once everything is set up.
}


Battle::~Battle(void)
{
}

void Battle::StartBattle()
{
	if(_orc->_name == "Orc King!!")
	{
		_player->_lives = 1;//final battle time; all or nothing
	}
	int _selection = 0;
	system("cls");
	cout<<"\nA savage Orc : " <<this->_orc->_name<<" approaches.Weapon at the ready he charges!!.. \n";
	int _enemySelection = (rand()%5) + 1;//generate the orcs attack and power
	int _playerPower = 0;
	int _enemyPower = (rand()%3) + 1;

	for(bool _continue = false; _continue == false; )
	{
		if(_player->_attackCoolDown > 0)//decrement all cool down
		{
			_player->_attackCoolDown--;
		}
		if(_player->_defenceCoolDown > 0)
		{
			_player->_defenceCoolDown --;
		}
		

		bool _correctInput = false;
		while(_correctInput == false)//loop until suitable input 
		{
			cout<<"\nWhat will you do?";
			cout<<"\n 1 for attack" << "("<<_player->_attackCoolDown << " Moves to wait)";
			cout<<"\n 2 to buff attack(lasts duration of battle)";
			cout<<"\n 3 to buff health"; 
			cout<<"\n 4 to buff speed(lasts duration of battle)";
			cout<<"\n 5 to defend"<< "("<<_player->_defenceCoolDown << " Moves to wait)";
			cin>> _selection;

			system("cls");
			if(_selection<6 && _selection >0)//ensure correct input
			{
				_correctInput = true;
			}
			else
			{
				_correctInput = false;
			}

			switch(_selection)//check for cooldown issues
			{
			case 1 : 
				if(_player->_attackCoolDown>0)
				{
					cout<<"\n CoolDown has not yet expired \n";
					_correctInput = false;	
				}
				break;
			case 5 :
				if(_player->_defenceCoolDown>0)
				{
					cout<<"\n CoolDown has not yet expired \n";
					_correctInput = false;	
				}
				break;
			}

		}
		srand(time(NULL));
		_enemySelection = (rand()%5) + 1;//gen enemy attack
		_playerPower = 0;
		_enemyPower = (rand()%3) + 1;//and power
		if(_selection == 1 || _selection == 5)
		{
			for(bool _correct = false; _correct == false;)
			{
				cout<<"Enter Power Level";
				cin>>_playerPower;
				if(_playerPower > 0 && _playerPower<4)//ensure power level between params
				{
					_correct = true;
				}
			}
		}


		if(_enemySelection == 5 && _selection ==1)//enemy is defending
		{
			cout<<"\nThe Orc has defended at a power of : " <<_enemyPower <<", will your attack succeed?\n";
			if(_playerPower>_enemyPower)//your attack succeeds if your power > defend
			{
				cout<<"\nYour power : "<< _playerPower << " attack succeeded\n";
				DoAnAttack(_player,_orc,_selection);
			}
			else
			{
				_player->_attackCoolDown+=2;
				cout<<"\nYour attack was defended \n";
			}
		}
		else if(_selection == 5 && _enemySelection == 1)//player is defending
		{
			cout<<"\nyou have defended with a power of : " << _playerPower << ", will the orcs attack succeed?\n";
			if(_enemyPower>_playerPower)
			{
				cout<<"\nyour defend failed...his "<<_enemyPower <<" Attack was too strong\n ";
				_player->_defenceCoolDown+=2;
				DoAnAttack(_orc,_player,_enemySelection);
			}
			else
			{
				cout<<"\nYour defend succeeded!!\n";
			}
		}
		else//if neither player defended, then just execute attacks
		{
			if((_player->_speed + _player->_speedBuff) > (_orc->_speed + _orc->_speedBuff))//if your faster than the orc
			{
				cout<<" \n You do a :- "; 
				DoAnAttack(_player,_orc,_selection);
				cout<<" \n Orc does a :- ";
				DoAnAttack(_orc,_player,_enemySelection);
			}
			else//or vice versa
			{
				cout<<" \n Orc does a :- ";
				DoAnAttack(_orc,_player,_enemySelection);
				cout<<" \n You do a :- "; 
				DoAnAttack(_player,_orc,_selection);
			}
		}
		cin.get();
		_player->PrintStats();//print stats
		_orc->PrintStats();



		if(_orc->_health<=0)//check game state for victory
		{
			cout<<"\nYou are victorious!! \n";
			_continue = true;
			_player->_speedBuff = 0;
			_player->_attackBuff = 0;
			_player->_defenceBuff = 0;
			cin.get();
		}
		else if(_player->_health<=0)
		{
			cout<<"\nYou are defeated.... \n";
			_continue = true;
			_player->_speedBuff = 0;
			_player->_attackBuff = 0;
			_player->_defenceBuff = 0;
			_player->_lives--;

			if(_player->_lives <=0)//if the players lives have hit 0. print quote and end game.
			{
				system("cls");
				cout<<".......The fabled warrior has fallen.....\n\n\n\n";
				cout<<_quotes[(rand()%4)+1];
				cin.get();
				exit(0);
			}
			cin.get();
		}

	}

}


void Battle::DoAnAttack(Unit* _attacker,Unit* _target,int _selection)//unit does an attack
{
	switch(_selection)//based on selection, execute attacks
	{
	case 1: 
		if(_attacker == _player)//if player attacked, apply cooldown.
		{
			_player->_attackCoolDown = 4;
		}
		cout<<" Attack!!";
		_attacker->Attack(_target);
		break;

	case 2:
		cout<<" Attack Buff";
		_attacker->_attackBuff += 5;
		break;

	case 3:
		cout<<" Health Buff";
		_attacker->_health += 5;
		break;
	case 4: 
		cout<<" Speed Buff";
		_attacker->_speedBuff += 5;
		break;
	case 5: 
		cout<<"Defend";
		if(_attacker == _player)
		{
			_player->_defenceCoolDown = 4;
		}
		break;
	}

}