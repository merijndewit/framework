#include <common/config.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <common/config.h>
#include <common/renderer.h>
#include <common/camera.h>
//#include <common/scene.h>
#include <common/sprite.h>
#include <common/entity.h>

#include "input.h"

double mousePosX;
double mousePosY;

Input::Input()
{
	_cursor = glm::vec3(0, 0, 0);
}

Input::~Input()
{

}

void Input::update(GLFWwindow* window)
{
	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	_cursor = glm::vec3(xpos, ypos, 0);
}

