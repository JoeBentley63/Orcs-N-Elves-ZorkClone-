/*
Game initialization and character creator

*/
#include "GameLoop.h"
#include <iostream>
#include "Orc.h"
#include "OrcFactory.h"
#include <string>
#include "Player.h"
#include "SceneManager.h"
#include "StringParser.h"
#include "Battle.h"

using namespace std;

Player* GameLoop::_player = 0;//player pointer
Unit::Class _class;//what class did they pick
Unit::Weapon _weapon;//weapon
Unit::Defensive _defensive;//defensive armor or weapon
string _name ;//and their name
int _selection = 1;
StringParser* _parser;

void PrintWeaponSelection();//various function prototypes
void PrintDefensiveSelection();
void PrintClassSelection();
int main()
{
	GameLoop::_player = 0;//set player to null
	OrcFactory* _orcFactory = OrcFactory::GetInstance();//create orc manager
	cout<<"------------------Orcs n' Elves----------------";
	cout<<"\n What is your name fabled warrior? \n";
	getline(cin, _name, '\n');//read in name
	PrintWeaponSelection();//jump to weapon select, ect
	PrintDefensiveSelection();
	PrintClassSelection();
	
	GameLoop::_player = new Player(_weapon,_defensive,_class,_name);//create the player
	cin.get();
	cout<<"\nWell " << _name << " ,Let your journey begin....\n";
	cin.get();

	SceneManager* _sceneManager = SceneManager::GetInstance();//begin the game

	_parser = StringParser::GetInstance();
	for(;;)
	{
		cout<<"\nso what are you going to do?\n";//read in players choice, parse it and pass it to current scene
		string _selection = " ";
		getline(cin, _selection, '\n');
		_parser->ParseString(_selection);
	}


	cin.get();
	cin.get();
	cin.get();
	return 0;
}

void PrintClassSelection()
{
	cout<<"\n and One more question, whats your build?\n"; 
	for(bool _continue = false; _continue == false; )
	{
		cout<<"\n -------------------------------------------------------";
		cout<<"\n 1 : Light";
		cout<<"\n 2 : Medium";
		cout<<"\n 3 : Heavy\n";
		cin>>_selection;

		if(_selection<1 || _selection>3)//ensure selection is vaid
		{
			cout<<"I'm afraid I've never heard of that class, me lord,do try again? ";
		}
		else
		{
			_continue = true;
			switch(_selection)
			{
			case 1 : _class = Unit::LIGHT; break;
			case 2 : _class = Unit::MEDIUM; break;
			case 3 : _class = Unit::HEAVY; break;
			}
		}
	}

}
void PrintDefensiveSelection()
{
	cout<<"\n hmmmm.... and what defence do you prefer??\n"; 

	for(bool _continue = false; _continue == false; )
	{
		cout<<"\n -------------------------------------------------------";
		cout<<"\n 1 : SHIELD";
		cout<<"\n 2 : EXTRAARMOR";
		cout<<"\n 3 : HELMET \n";


		cin>>_selection;

		if(_selection<1 || _selection>3)
		{
			cout<<"I'm afraid I've never heard of that me lord,do try again? ";
		}
		else
		{
			_continue = true;
			switch(_selection)
			{
			case 1 : 
				cout<<"\n A Shield eh? A True warrior knows their limitations...";
				_weapon = Unit::BROADSWORD; 
				break;
			case 2 : 
				cout<<"\n  Extra Armor Eh? Better safe than sorry haha...";
				_weapon = Unit::MACE; 
				break;
			case 3 : 
				cout<<"\n A Helmet Eh? Protect whats important...";
				_weapon = Unit::SHORTSWORD; 
				break;
			}

		}

	}
}
void PrintWeaponSelection()
{
	cout<<"\n "<<_name <<" ? Aye? well "<< _name << ", what offensive Weapon thus thou weild?\n"; 

	for(bool _continue = false; _continue == false; )
	{
		cout<<"\n--------------------------------------------------";
		cout<<"\n 1 : BROADSWORD";
		cout<<"\n 2 : MACE";
		cout<<"\n 3 : SHORTSWORD";
		cout<<"\n 4 : DAGGER";
		cout<<"\n 5 : BOW";
		cout<<"\n 6 : TANTO";
		cout<<"\n 7 : KATANA";
		cout<<"\n 8 : SPEAR\n ";

		cin>>_selection;
		if(_selection >8 || _selection <1)
		{
			cout<<"I'm afraid I've never heard of that weapon me lord, try again? ";
		}
		else
		{
			_continue = true;
			switch(_selection)
			{
			case 1 : 
				cout<<"\n A Broad Sword Eh? A Balanced weapon for a balanced warrior perhaps?..";
				_weapon = Unit::BROADSWORD; 
				break;
			case 2 : 
				cout<<"\n A Mace Eh? Powerfull but slow...";
				_weapon = Unit::MACE; 
				break;
			case 3 : 
				cout<<"\n A ShortSword Eh? Trusty and reliable..";
				_weapon = Unit::SHORTSWORD; 
				break;
			case 4 : 
				cout<<"\n A Dagger Eh? Bruteforce is not always the solution";
				_weapon = Unit::DAGGER; 
				break;
			case 5 :
				cout<<"\n A Bow Eh? Death from a distance..";
				_weapon = Unit::BOW;
				break;
			case 6 : 
				cout<<"\n A Tanto Eh? An Assassin maybe?..";
				_weapon = Unit::TANTO; 
				break;
			case 7 : 
				cout<<"\n A Katana Eh? are you a warrior from the east maybe?..";
				_weapon = Unit::KATANA; 
				break;

			case 8 : 
				cout<<"\n A Spear Eh? Balanced and powerfull, weapon of a warrior..";
				_weapon = Unit::SPEAR; 
				break;

			}
		}
	}
}