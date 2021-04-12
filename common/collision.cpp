#include <iostream>
#include <cstdio>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <common/collision.h>



bool Collision::createBox(float width, float height, float posx, float posy, float mousePosx, float mousePosy)
{
	if (mousePosx >= (0 + posx) && mousePosx <= (width + posx) && mousePosy >= (0 + posy) && mousePosy <= (height + posy))
	{
		std::cout << "it be working" << std::endl;
		return true;
	}else
	{
		return false;
	}
}
