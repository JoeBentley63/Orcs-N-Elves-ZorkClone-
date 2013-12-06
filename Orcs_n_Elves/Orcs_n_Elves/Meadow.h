#ifndef _MEADOW_H
#define _MEADOW_H

#include "scene.h"
#include "Unit.h"
#include "Orc.h"
#include "Battle.h"
#include "OrcFactory.h"
#include "GameLoop.h"
#include "SceneManager.h"

class Meadow :
	public Scene
{
public:
	Meadow(void);
	~Meadow(void);
	virtual void SceneInfo();
	virtual void Move(string _info);
	virtual void Get(string _info);
	virtual void TalkTo(string _info);
};

#endif
