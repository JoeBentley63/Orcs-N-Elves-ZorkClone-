#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H
#include <iostream>
#include "BeginningScene.h"
#include "A0_1.h"
#include "Meadow.h"
#include "DirtPath.h"
#include "Factory.h"

using namespace std;
class SceneManager
{
private:
	
	static SceneManager* _me;
	SceneManager(void);
public:
	Scene* _scene;
	enum Scenes
	{
		BEGINNING,
		A0_1,
		A0_2,
		DIRTPATH,
		FACTORY
	};
	Scenes _currentScene;
	static SceneManager* GetInstance();
	void ChangeScene(Scenes _newScene);
	~SceneManager(void);
};

#endif

