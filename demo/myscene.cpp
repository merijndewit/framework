#include <common/config.h>
#include <common/input.h>
#include <common/entity.h>
#include "myscene.h"
#include <common/collision.h>
Input input;
Collision collision;

MyScene::MyScene() : Scene()
{
	box->position = glm::vec3(200.0f, 200.0f, 0.0f);
	Sprite* pencils = new Sprite("assets/pencils.tga");
	pencils->position = glm::vec3(900.0f, 300.0f, 0.0f);
	Sprite* rgba = new Sprite("assets/rgba.tga");
	rgba->position = glm::vec3(WIDTH / 2, HEIGHT / 2, 0.0f);
	rgba->scale = glm::vec3(3.0f, 3.0f, 1.0f);
	//this->addSprite(box);
	this->addSprite(pencils);
	this->addSprite(rgba);
}

MyScene::~MyScene()
{
}

void MyScene::update(GLFWwindow* window)
{
	glm::vec3 mp = input.getCursor(window);
	//std::cout << box->position.x << std::endl;

	if (collision.createBox(200, 200, 100, 100, mp.x, mp.y) == true)
	{
		if (boxPlaced == false)
		{
			this->addSprite(box);
			boxPlaced = true;
		}
	}
	else if (collision.createBox(200, 200, 100, 100, mp.x, mp.y) == false)
	{
		this->removeSprites(3);
		boxPlaced = false;
	}
}
