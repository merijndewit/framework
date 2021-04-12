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

bool Collision::box2box(glm::vec3 boxPos, float box1Width, float box1Height, glm::vec3 box2Pos, float box2Width, float box2Height)
{

	distanceX = box2Pos.x - (boxPos.x + box1Width);

	if (boxPos.x < box2Pos.x + box2Width && boxPos.x + box1Width > box2Pos.x && boxPos.y < box2Pos.y + box2Height && boxPos.y + box1Height > box2Pos.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}



