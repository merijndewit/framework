#ifndef COLLISION_H
#define COLLISION_H

#include <string>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>
class Collision
{
	
public:
	bool Collision::createBox(float width, float height, float posx, float posy, float mousePosx, float mousePosy);
private:
	
};

#endif /* COLLISION_H */
