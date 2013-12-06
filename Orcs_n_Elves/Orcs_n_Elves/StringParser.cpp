#include "StringParser.h"
#include <iostream>
/*For the zork clone part, i needed a mechanism to parse strings typed in.
this singleton will provide that functionality for me
*/

StringParser* StringParser::_me = 0;//singleton,pointer to StringParser object
SceneManager* _sceneManager;

using namespace std;
StringParser::StringParser(void)
{
	_sceneManager = SceneManager::GetInstance();
}


StringParser::~StringParser(void)
{
}

StringParser* StringParser::GetInstance()
{
	if(_me == 0)
	{
		_me = new StringParser();
	}
	return _me;
}

void StringParser::ParseString(string _string)
{
    istringstream _stream(_string);//pass the string into a stream,
	string _firstSubString;//various substrings
	string _secondSubString;
	_stream >> _firstSubString;//read the first word
	_stream >> _secondSubString;//and the second

	for(int i = 0; i < _firstSubString.length(); i++)//convert to lower case character by character
	{
		_firstSubString[i] =tolower(_firstSubString[i]);
	}
	for(int i = 0; i < _secondSubString.length(); i++)
	{
		_secondSubString[i] =tolower(_secondSubString[i]);
	}

	//call the scene managers various functions, based on what the first string was.
	if(_firstSubString == "go" || _firstSubString == "head" || _firstSubString == "travel" || _firstSubString == "walk" || _firstSubString == "run"|| _firstSubString == "move" || _firstSubString == "goto")
	{
		//pass in the second substring, as it is the subject
		_sceneManager->_scene->Move(_secondSubString);
	}
	else if(_firstSubString == "pickup" || _firstSubString == "get" || _firstSubString == "take" || _firstSubString == "lift" || _firstSubString == "grab")
	{
		_sceneManager->_scene->Get(_secondSubString);
	}
	else if(_firstSubString == "info" || _firstSubString == "look" || _firstSubString == "where" || _firstSubString == "reload")
	{
		_sceneManager->_scene->SceneInfo();
	}
	else if(_firstSubString == "ask" || _firstSubString == "talkto" || _firstSubString == "talk" || _firstSubString == "speakto" || _firstSubString == "lookat" || _firstSubString == "read" )
	{
		
		_sceneManager->_scene->TalkTo(_secondSubString);
	}
	else//just in case
	{
		cout<<"I cant do that?";
	}	
	
}