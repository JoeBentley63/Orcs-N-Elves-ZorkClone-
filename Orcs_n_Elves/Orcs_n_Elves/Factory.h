#ifndef _FACTORY_H
#define _FACTORY_H

#include "scene.h"
#include "SceneManager.h"
class Factory :
	public Scene
{
public:
	
	Factory(void);
	~Factory(void);
	virtual void SceneInfo();
	virtual void Move(string _info);
	virtual void Get(string _info);
	virtual void TalkTo(string _info);
};

#endif
