#include <common/config.h>
#include <common/camera.h>
#include <common/input.h>

#include <common/entity.h>
//#include "myscene.h"

Camera::Camera()
{
	
	_projectionMatrix = glm::ortho(0.0f, (float)WIDTH, (float)HEIGHT, 0.0f, 0.1f, 100.0f);
	_viewMatrix = glm::mat4(1.0f);
	_cursor = glm::vec3( 0, 0, 0 );
}

Camera::~Camera()
{
	
}

void Camera::computeViewMatrixFromInput(GLFWwindow* window, float deltaTime)
{
	Input input;
	// Right and Up vector
	glm::vec3 right = glm::vec3(1, 0, 0);
	glm::vec3 up = glm::vec3(0, -1, 0);

	static glm::vec3 position = glm::vec3( 0, 0, 10 ); // Initial position : on +Z
	float speed = 300.0f; // units / second

	// Move up
	if (input.getKeyCode() == 265){
		position += up * deltaTime * speed;
	}
	// Move down
	if (input.getKeyCode() == 264){
		position -= up * deltaTime * speed;
	}
	// Strafe right
	if (input.getKeyCode() == 262){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (input.getKeyCode() == 263){
		position -= right * deltaTime * speed;
	}

	// View matrix
	_viewMatrix = glm::lookAt(
			position, /* Camera is at (xpos,ypos,zpos), in World Space */
			position + glm::vec3(0, 0, -1), /* and looks towards Z */
			glm::vec3(0, 1, 0)  /* Head is up (set to 0,-1,0 to look upside-down) */
		);
}
