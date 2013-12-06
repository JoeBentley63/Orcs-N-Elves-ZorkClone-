#include "SceneManager.h"
/*
The scene manager, which will handle scene tranversal.
*/

SceneManager* SceneManager::_me; //a singleton, so that only 1 object can change our scenes
SceneManager::SceneManager(void)
{
	_currentScene = BEGINNING;//set up so the first scene will show
	_scene = new BeginningScene();//create the scene, then print its intro
	_scene->SceneInfo();
}


SceneManager::~SceneManager(void)
{
}

SceneManager* SceneManager::GetInstance()//public get instance, for singleton pattern
{
	if(_me == NULL)
	{
		_me = new SceneManager();
	}
	return _me;
}
void SceneManager::ChangeScene(Scenes _newScene)//change the schene
{
	switch(_newScene)//based on the new scene, we change the current scene
	{
	case BEGINNING:
		_scene = new BeginningScene();
		break;
	case A0_1:
		_scene = new A01();
		break;
	case A0_2:
		_scene = new Meadow();
		break;
	case DIRTPATH:
		_scene = new DirtPath();
		break;
	case FACTORY:
		_scene = new Factory();
		break;
	}
	_scene->SceneInfo();//once the scene is created, print its intro
}