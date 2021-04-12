#ifndef MYSCENE_H
#define MYSCENE_H

#include <common/scene.h>
#include <common/sprite.h>

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();
	void update(GLFWwindow* window);
	Sprite* boxclick = new Sprite("assets/box.tga");
	Sprite* box = new Sprite("assets/emptyBox.tga");
	Sprite* box1 = new Sprite("assets/box.tga");
	Sprite* box2 = new Sprite("assets/box.tga");
	Sprite* pencils = new Sprite("assets/pencils.tga");
	Sprite* rgba = new Sprite("assets/rgba.tga");
	
private:
	bool playing = true;
	bool boxPlaced = false;
	float score;
};

#endif /* MYSCENE_H */