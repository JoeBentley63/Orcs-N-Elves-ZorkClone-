#include "Scene.h"
/*
Super class for the various scenes that player will be able to enter
*/

Scene::Scene(void)
{
}


Scene::~Scene(void)
{
}
void Scene::SceneInfo()//print the scenes information
{
}
void Scene::Move(string _info)//what should we do if we move in this scene?
{
}
void Scene::Get(string _info)//what should we do if we get something in this scene
{
}
void Scene::TalkTo(string _info)//what do we do if we talk to something in this scene?
{
}
