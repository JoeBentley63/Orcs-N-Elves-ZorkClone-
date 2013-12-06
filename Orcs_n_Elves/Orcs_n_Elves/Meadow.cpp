#include "Meadow.h"
//Location player can enter

Meadow::Meadow(void)
{
}


Meadow::~Meadow(void)
{
}

void Meadow::SceneInfo()
{
	system("cls");
	cout<<"The man pacing about the meadow appears to be infact an ORC.He appears annoyed."
		<<"The meadow is filled with wildlife.A small blonde BOY, dressed in green is running about, chopping the grass"
		<<"with his sword.He looks familure.Due to a fallen TREE, you cannot progress any furthur into the meadow.";
}
void Meadow::Move(string _info)
{
	if(_info == "west")
	{
		SceneManager::GetInstance()->ChangeScene(SceneManager::A0_1);
	}
		
	else
	{
		cout<<"The meadow is blocked, i must return WEST..";
	}
}
void Meadow::Get(string _info)
{
	cout<<"There is nothing to pick up here?";
}
void Meadow::TalkTo(string _info)
{
	if(_info == "orc")
	{
		Unit* _orc = OrcFactory::GetInstance()->CreateOrc("Jeff");
		Battle* _battle = new Battle(GameLoop::_player,_orc);
		cout<<"\n Good Battle warrior, speak to me again if you wish to spar again :D ";
	}
	else if(_info == "boy" || _info == "link" )
	{
		cout<<"I am going to be a HERO!! Heeyaah!, woops, looks like im running out of TIME, better get back to looking for gems";
	}
	else
	{
		cout<<"I cant talk to that";
	}
}
