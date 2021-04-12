#ifndef INPUT_H
#define INPUT_H

#include <common/scene.h>
#include <common/sprite.h>



class Input
{
public:
	Input();
	virtual ~Input();

	void update(GLFWwindow* window);
	//	void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
	glm::vec3 getCursor(GLFWwindow* window) { 
		update(window);
		return _cursor; };

	static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
	int getKeyCode() { return _keyCode; };
private:
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
	glm::vec3 _cursor;
	static int _keyCode;
	static glm::vec2 keys;
};


#endif /* INPUT_H */