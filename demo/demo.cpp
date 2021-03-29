// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <common/config.h>
#include <common/renderer.h>
#include <common/camera.h>
//#include <common/scene.h>
#include <common/sprite.h>
#include <common/entity.h>
#include <common/input.h>

#include "myscene.h"

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

int main( void )
{
	Renderer renderer;
	Input input;

	MyScene* myscene = new MyScene();
	
	do {
		// get deltaTime and update camera
		float dt = renderer.updateDeltaTime();
		myscene->camera()->computeViewMatrixFromInput(renderer.window(), dt);
		glm::vec3 mp = input.getCursor();
		input.update(renderer.window());
		glfwSetKeyCallback(renderer.window(), keyCallBack );
		//std::cout << mp.x << std::endl;
		//std::cout << mp.y << std::endl;
		// Update the scene
		myscene->update(dt); // TODO make subclass for Scene (and make Scene abstract?)
		//rgba->rotation += dt; // for now, do it here
		// Render the scene
		renderer.renderScene(myscene);
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete myscene;

	return 0;
}
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << key << std::endl;
}

