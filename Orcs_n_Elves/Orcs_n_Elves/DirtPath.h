#ifndef _DIRT_PATH_H
#define _DIRT_PATH_H

#include "scene.h"
#include "SceneManager.h"
class DirtPath :
	public Scene
{
public:
	
	DirtPath(void);
	~DirtPath(void);
	virtual void SceneInfo();
	virtual void Move(string _info);
	virtual void Get(string _info);
	virtual void TalkTo(string _info);
};

#endif
