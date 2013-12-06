#ifndef _SCENE_H
#define _SCENE_H
#include <string>
#include <iostream>
using namespace std;
class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);
	virtual void SceneInfo();
	virtual void Move(string _info);
	virtual void Get(string _info);
	virtual void TalkTo(string _info);
	
	
};

#endif
