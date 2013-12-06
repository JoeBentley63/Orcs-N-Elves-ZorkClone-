#include "BeginningScene.h"


BeginningScene::BeginningScene(void)
{
}


BeginningScene::~BeginningScene(void)
{
}
void BeginningScene::SceneInfo()
{
	system("cls");
	cout<<"\n You find your self in an opening.Before you is a forest,lush with flora and fauna.You look around to find that NORTH is the only way to progress.You head racks with pain as you try to "
		<<"remember how you got here.The last thing you rememeber was an old man, speaking in a faint voice.The factory he muttered.what did it mean.There is a NOTE on the ground";
}
void BeginningScene::Move(string _info)
{
	if(_info == "north")
	{
		cout<<"\n MovedNorth";
		SceneManager::GetInstance()->ChangeScene(SceneManager::A0_1);

	}
	else
	{
		cout<<"The only way you can move is north, maybe you should try that?";
	}
}
void BeginningScene::Get(string _info)
{
	if(_info == "note")
	{
		system("cls");
		cout<<"Welcome to Orcs n' Elves, a simple text-based adventure.Basically its a ZORK clone, so most the controls are "
			<<"simular.This is not a full adventure, just a fun little demo." 
			<<"\n LIST OF KEYWORDS"
			<<"\nMovement: go/head/travel/walk/run/move/goto X"
			<<"\nGet: pickup/get/take/lift/grab X"
			<<"\nInfo: info/look/where"
			<<"\nTalk : ask/talkto/talk/speakto/lookat X";
	}
	else
	{
		cout<<"There is nothing to pick up there?";
	}
}
void BeginningScene::TalkTo(string _info)
{
	if(_info == "self")
	{
		cout<<"I should go north, see if i can't find something";
	}
	else if(_info == "note")
	{
		system("cls");
		cout<<"Welcome to Orcs n' Elves, a simple text-based adventure.Basically its a ZORK clone, so most the controls are "
			<<"simular.This is not a full adventure, just a fun little demo." 
			<<"\n LIST OF KEYWORDS"
			<<"\nMovement: go/head/travel/walk/run/move/goto X"
			<<"\nGet: pickup/get/take/lift/grab X"
			<<"\nInfo on Area: info/look/where"
			<<"\nTalk : ask/talkto/talk/speakto/lookat X"
			<<"\n Make X lowercase please :D ";
	
	
	
	}
	else
	{
		cout<<"There is no one to talk to";
	}
}
