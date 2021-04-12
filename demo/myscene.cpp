#include <common/config.h>
#include <common/input.h>
#include <common/entity.h>
#include "myscene.h"
#include <common/collision.h>
Input input;
Collision collision;

MyScene::MyScene() : Scene()
{
	box1->position = glm::vec3(80.0f, 700.0f, 0.0f);
	box1->scale = glm::vec3(0.5f, 0.5f, 0.0f);

	box2->position = glm::vec3(1200.0f, 700.0f, 0.0f);
	box2->scale = glm::vec3(0.5f, 0.5f, 0.0f);

	box->position = glm::vec3(200.0f, 200.0f, 0.0f);

	boxclick->position = glm::vec3(200.0f, 200.0f, 0.0f);
	
	pencils->position = glm::vec3(900.0f, 300.0f, 0.0f);
	
	rgba->position = glm::vec3(WIDTH / 2, HEIGHT / 2, 0.0f);
	rgba->scale = glm::vec3(3.0f, 3.0f, 1.0f);
	//this->addSprite(box);
	this->addSprite(pencils);
	this->addSprite(rgba);
	this->addSprite(box);
	this->addSprite(box1);
	this->addSprite(box2);
}

MyScene::~MyScene()
{
}

void MyScene::update(GLFWwindow* window)
{
	glm::vec3 mp = input.getCursor(window);
	//std::cout << box->position.x << std::endl;

	if (collision.boxMouseCollision(200, 200, 100, 100, mp.x, mp.y) == true)
	{
		if (boxPlaced == false)
		{
			this->addSprite(boxclick);
			boxPlaced = true;
		}
	}
	else if (collision.boxMouseCollision(200, 200, 100, 100, mp.x, mp.y) == false)
	{
		this->removeSprites(6);
		boxPlaced = false;
	}

	if (collision.box2box(box1->position.x, box1->position.y, 100, 100, box2->position.x, box2->position.y, 100, 100) == true)
	{
		std::cout << "yeyy" << std::endl;
	}
	box1->position.x += 0.1f;
}
