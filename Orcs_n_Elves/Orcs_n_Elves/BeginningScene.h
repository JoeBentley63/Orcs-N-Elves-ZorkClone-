#ifndef BEGINNING_SCENE_H
#define BEGINNING_SCENE_H
#include "SceneManager.h"
#include "scene.h"
class BeginningScene :
	public Scene
{
public:
	BeginningScene(void);
	~BeginningScene(void);
	virtual void SceneInfo();
	virtual void Move(string _info);
	virtual void Get(string _info);
	virtual void TalkTo(string _info);
};

#endif
