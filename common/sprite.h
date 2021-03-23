#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>
class Sprite
{
public:
	Sprite(const std::string& imagepath);
	virtual ~Sprite();

	GLuint texture() { return _texture; };
	GLuint vertexbuffer() { return _vertexbuffer; };
	GLuint uvbuffer() { return _uvbuffer; };

	unsigned int width() { return _width; };
	unsigned int height() { return _height; };

	glm::vec3 position;
	float rotation;
	glm::vec3 scale;

private:
	GLuint loadTGA(const std::string& imagepath);

	GLuint _texture;
	GLuint _vertexbuffer;
	GLuint _uvbuffer;

	unsigned int _width;
	unsigned int _height;
};

#endif /* SPRITE_H */
