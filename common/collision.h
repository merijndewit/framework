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
	bool Collision::boxMouseCollision(float boxWidth, float boxHeight, float boxPosx, float boxPosy, float mousePosx, float mousePosy);
	bool Collision::box2box(float box1Posx, float box1Posy, float box1Width, float box1Height, float box2Posx, float box2Posy, float box2Width, float box2Height);
private:
	
};

#endif /* COLLISION_H */
