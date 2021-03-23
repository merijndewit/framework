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

#include "myscene.h"



int main( void )
{
	Renderer renderer;

	Scene* scene = new Scene();

	scene->addSprite(kingkong);
	scene->addSprite(pencils);
	scene->addSprite(rgba);


	do {
		// get deltaTime and update camera
		float dt = renderer.updateDeltaTime();
		scene->camera()->computeViewMatrixFromInput(renderer.window(), dt);

		// Update the scene
		scene->update(dt); // TODO make subclass for Scene (and make Scene abstract?)
		//rgba->rotation += dt; // for now, do it here
	
		// Render the scene
		renderer.renderScene(scene);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0, 0);
		glVertex2f(1, 1);
		glEnd();

		glfwPollEvents();
	

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete scene;

	return 0;
}


