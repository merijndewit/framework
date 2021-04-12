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
int Input::_keyCode;
void Input::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//std::cout << key << std::endl;
	switch (action)
	{
	case GLFW_PRESS:
		_keyCode = key;
		break;
	case GLFW_REPEAT:
		//_keyCode = key;
		break;
	case GLFW_RELEASE:
		_keyCode = NULL;
		break;
	default:
		//_keyCode = NULL;
		break;
	}

	if (action) {


	}
	//_keyCode = NULL;
}
