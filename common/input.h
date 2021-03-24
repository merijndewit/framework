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
	glm::vec3 getCursor() { return _cursor; };

private:
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
	glm::vec3 _cursor;
};
	
	
#endif /* INPUT_H */