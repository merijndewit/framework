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
	
private:

};

#endif /* MYSCENE_H */