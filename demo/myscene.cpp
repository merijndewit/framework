#include <common/config.h>
#include <common/input.h>
#include <common/entity.h>
#include "myscene.h"
Input input;

MyScene::MyScene() : Scene()
{
	
	
	box->position = glm::vec3(300.0f, 300.0f, 0.0f);
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
	std::cout << boxPlaced << std::endl;

	if (mp.x >= 200 && mp.x <= 400 && mp.y >= 200 && mp.y <= 400)
	{
		if (boxPlaced == true)
		{
		
		} 
		else
		{
			this->addSprite(box);
			boxPlaced = true;
		}
	}
	else
	{
		this->removeSprites(3);
		boxPlaced = false;
	}
	
}
