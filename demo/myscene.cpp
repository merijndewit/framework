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
	score = 0;
}

MyScene::~MyScene()
{
}

void MyScene::update(GLFWwindow* window)
{
	glm::vec3 mp = input.getCursor(window);
	//std::cout << box->position.x << std::endl;

	if (collision.boxMouseCollision(200, 200, 100, 100, mp.x, mp.y))
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

	if (collision.box2box(box1->position, 100, 100, box2->position, 100, 100) && playing == true)
	{
		playing = false;
		std::cout << "highscore:" << std::endl;
		std::cout << score << std::endl;
		score = 0;
	}
	
	if (input.getKeyCode() == 32 && playing == true && box1->position.x > 150)
	{
		box1->position.x = 80;
		float Distance = collision.getDistance();
		score += 100 - Distance;
		
	}

	if (playing == true) {
		box1->position.x += 0.5f;
		box2->position.x -= 0.1f;
	}
	if (playing == false && input.getKeyCode() == 32)
	{
		playing = true;
		box1->position.x = 80;
		box2->position.x = 1200;
	}
	
}
