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
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << key << std::endl;

	if (key == GLFW_KEY_SPACE)
	{
		switch ( action )
		{
			case GLFW_PRESS:
				std::cout << "space key is pressed" << std::endl;
				break;
			case GLFW_REPEAT:
				std::cout << "space key is being held down" << std::endl;
				break;
			case GLFW_RELEASE:
				std::cout << "space key is being released" << std::endl;
				break;
		default:
			break;
		}


		
	}

}
