#include "A0_1.h"
/*Gorge scene,One of the locations that the player can enter*/

A01::A01(void)
{
}


A01::~A01(void)
{
}

void A01::SceneInfo()
{
	system("cls");
	cout<<"\nBefore you is a gorge.Beyond the gorge, you spot an Orc Factory."
		<<"The Factory is churning out Orcs ready for battle.WEST you see a dirt path, East you see a man pacing back and forth."
		<<"There is a SIGN at by the gorge.";
}
void A01::Move(string _info)
{
	if(_info == "west")
	{
		SceneManager::GetInstance()->ChangeScene(SceneManager::DIRTPATH);
	}
	else if(_info == "east" || _info == "man")
	{
		SceneManager::GetInstance()->ChangeScene(SceneManager::A0_2);
	}
	else
	{
		cout<<"The only way you can move is east or west, the gorge blocks the factory";
	}
}
void A01::Get(string _info)
{
	cout<<"There is nothing to pick up here?";
}
void A01::TalkTo(string _info)
{
	if(_info == "sign")
	{
		cout<<"\nThe sign reads: <West = Forest , East> Meadow\n";
	}
	else if(_info == "forest")
	{
		cout<<"\nA dense forest, who knows what secrets it may hold. \n";
	}
	else
	{
		cout<<"There is no one to talk to";
	}
}
