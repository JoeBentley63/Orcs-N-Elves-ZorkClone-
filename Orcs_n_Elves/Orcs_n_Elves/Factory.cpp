#include "Factory.h"
//Location player can enter, not factory for creating orcs, for that see OrcFactory.cpp

Factory::Factory(void)
{
}


Factory::~Factory(void)
{
}

void Factory::SceneInfo()
{
	system("cls");
	cout<<"You finally arrive at the Factory, Its billowing thick smoke into the world."
		<<"From outside you can see an army massing within its walls, enough to engulf the "
		<<"Seven kingdoms. You burst through the front door, weapon at the ready."
		<<"Entering the factory, you spot a switch labelled"
		<<"\n'Destructor Method, Warning, do not call,may cause army destruction'\n"
		<<"You wonder why such an important switch was so close to the door, and so ungaurded."
		<<"You can move SOUTH to re-enter the forest, or MOVE the SWITCH ";
}
void Factory::Move(string _info)
{
	if(_info == "switch" )
	{
		system("cls");
		cout<<"You pull the switch, with an almighty clank it hits the floor. The Factory begins to rumble"
			<<"and crack as it shakes itself apart. Looking around you see as the Orc army begins to vanish"
			<<"into clouds of binary.The Orc king bursts through from the throne room.'My Army!!' he shouts,"
			<<"falling to his knees.'All my work, my planning....gone..'.He looks around in anger, 'WHHHOOOOO!!'"
			<<"He spots you as you slip back out of the main entrance,grabs his sword and runs for you like a"
			<<"feral beast. 'YOU MUST DIE NOW!!.......\n press space to continue";
		cin.get();
		Unit* _orc = OrcFactory::GetInstance()->CreateOrc("Orc King!!");
		Battle* _battle = new Battle(GameLoop::_player,_orc);
		cout<<"........'NOOOOOOOOOOOOOOOOOOO!!' the Orc King screeches as you deliver the final blow."
			<<"The Factory continues to crumble before your eyes, rising as if by magic up into the air "
			<<"where it gets sucked into a singularity(Unallocated memory).The kingdoms have been saved from a threat they"
			<<"where unaware of.You job was done, but your story not complete..you look to the sky and walk into the distance"
			<<"\n END\n\n\n\n"
			<<"Thank you for playing :D";
			
	}
	if(_info == "south" )
	{
		SceneManager::GetInstance()->ChangeScene(SceneManager::DIRTPATH);
	}
	else
	{
		cout<<"I cant move to there.";
	}
}
void Factory::Get(string _info)
{
	cout<<"Stealing is wrong....except in RPG's apparently..";
}
void Factory::TalkTo(string _info)
{
	if(_info == "self")
	{
		cout<<"\n'I am 96% sure i should pull that switch'\n";
	}
	
	else
	{
		cout<<"There is no one to talk to..except maybe my SELF...";
	}
}
