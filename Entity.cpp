#include "Entity.h"

Entity::Entity(void)
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}


Entity::~Entity(void)
{
}

int Entity::getX()
{
	return x;
}

int Entity::getY()
{
	return y;
}

int Entity::getWidth()
{
	return width;
}

int Entity::getHeight()
{
	return height;
}

void Entity::setX(int px)
{
	x = px;
}

void Entity::setY(int py)
{
	y = py;
}

void Entity::setWidth(int pwidth)
{
	width = pwidth;
}

void Entity::setHeight(int pheight)
{
	height = pheight;
}

void Entity::setPosition(int px, int py)
{
	setX(px);
	setY(py);
}
