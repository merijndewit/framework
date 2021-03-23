#include <iostream>

#include <common/entity.h>

int Entity::_nextGuid = 0;

Entity::Entity()
{
	_guid = _nextGuid;
	_nextGuid++;

	//printf("Entity ctor %d\n", _guid);

	_parent = nullptr;

	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);

	_worldposition = glm::vec3(0.0f, 0.0f, 0.0f);
	_worldrotation = glm::vec3(0.0f, 0.0f, 0.0f);
	_worldscale = glm::vec3(1.0f, 1.0f, 1.0f);

	_sprite = nullptr;


	//_input = Singleton<Input>::instance();
}

Entity::~Entity()
{
	//printf("Entity dtor %d\n", _guid);
	deleteSprite();
	deleteSpritebatch();
}

void Entity::addChild(Entity* child)
{
	if(child->_parent != nullptr) {
		child->_parent->removeChild(child);
	}
	child->_parent = this;
	this->_children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
	std::vector< Entity* >::iterator it = _children.begin();
	while (it != _children.end()) {
		if ((*it)->_guid == child->_guid) {
			child->_parent = nullptr;
			it = _children.erase(it);
		} else {
			++it;
		}
	}
}

Entity* Entity::getChild(unsigned int i)
{
	if (i < _children.size()) {
		return _children[i];
	}
	return nullptr;
}

void Entity::addSprite(const std::string& filename)
{
	this->addSprite(filename, 0.5f, 0.5f);
}


