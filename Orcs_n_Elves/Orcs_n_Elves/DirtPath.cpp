#include "DirtPath.h"
//Location player can enter



DirtPath::DirtPath(void)
{
}


DirtPath::~DirtPath(void)
{
}

void DirtPath::SceneInfo()
{
	system("cls");
	cout<<"\nYou walk down the dirt path, into the forest you seen when you first awoken."
		<<"You stumble as you walk as your footing seems to be rubble and dirt."
		<<"As you continue through the forest, you reach an opening.Before you is the Orc Factory."
		<<"'Is this what the old man was talking about?' you think to yourself."
		<<"As you stand there, awe struck, glowing insects circle your body and rush off into the DARK."
		<<"\n You can move NORTH, or backtrack SOUTH..or you could try the DARK";
}
void DirtPath::Move(string _info)
{
	if(_info == "dark")
	{
		system("cls");
		cout<<"You walk down the Dark chamber, lights flicker around you, its very mysterious."
			<<"You appear to be moving down at a slope, following these fairy like creatures."
			<<"As you walk forward you see a beutiful clearing, with a spring in the center."
			<<"Drinking from it, you feel regenerated and ready for your journey.You look around,"
			<<"but your fairy friends seemed to have dissapeared. to the right you see a cliff."
			<<"Below the cliff you see where you woke up.'strange.I taught I moved North?' you think..."
			<<"Before you can comprehend the situation, a russeling in the bushes beside you has you on edge"
			<<"You raise your sword , ready for battle.....\n";
		cin.get();
		Unit* _orc = OrcFactory::GetInstance()->CreateOrc("Franklin");
		Battle* _battle = new Battle(GameLoop::_player,_orc);
		cout<<"\n with a final swipe, Franklin knocks you off the cliff.You hit the floor, struck with amnesia.<fade to black>\n";

		SceneManager::GetInstance()->ChangeScene(SceneManager::BEGINNING);
	}
	else if(_info == "north" )
	{
		SceneManager::GetInstance()->ChangeScene(SceneManager::FACTORY);
	}
	else if(_info == "south" )
	{
		SceneManager::GetInstance()->ChangeScene(SceneManager::A0_1);
	}
	else if(_info == "west" )
	{
		cout<<"\n the forest is too thick...id get lost";
	}
	else
	{
		cout<<"I cant move to there.";
	}
}
void DirtPath::Get(string _info)
{
	cout<<"<looks around> I cant take anything";
}
void DirtPath::TalkTo(string _info)
{
	if(_info == "self")
	{
		cout<<"\nThose fairys seemed to be ushering me towards them....\n";
	}
	
	else
	{
		cout<<"There is no one to talk to..except maybe my SELF...";
	}
}
