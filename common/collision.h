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
	bool Collision::box2box(glm::vec3 boxPos, float box1Width, float box1Height, glm::vec3 box2Pos, float box2Width, float box2Height);
	float Collision::getDistance() { return distanceX; };
private:
	float distanceX;
};

#endif /* COLLISION_H */
