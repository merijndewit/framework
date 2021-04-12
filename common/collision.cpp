#include <iostream>
#include <cstdio>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <common/collision.h>



bool Collision::boxMouseCollision(float boxWidth, float boxHeight, float boxPosx, float boxPosy, float mousePosx, float mousePosy)
{
	if (mousePosx >= (0 + boxPosx) && mousePosx <= (boxWidth + boxPosx) && mousePosy >= (0 + boxPosy) && mousePosy <= (boxHeight + boxPosy))
	{
		//std::cout << "it be working" << std::endl;
		return true;
	}else
	{
		return false;
	}
}

bool Collision::box2box(float box1Posx, float box1Posy, float box1Width, float box1Height, float box2Posx, float box2Posy, float box2Width, float box2Height)
{
	if (box1Posx < box2Posx + box2Width &&box1Posx + box1Width > box2Posx && box1Posy < box2Posy + box2Height && box1Posy + box1Height > box2Posy) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
