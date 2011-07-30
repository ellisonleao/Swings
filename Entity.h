#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

class Entity
{
protected:
	int x;
	int y;
	int width;
	int height;
public:
	Entity(void);
	~Entity(void);

	int getX();
	int getY();
	int getWidth();
	int getHeight();

	void setX(int px);
	void setY(int py);
	void setWidth(int pwidth);
	void setHeight(int pheight);

	void setPosition(int px, int py);

	virtual void process(unsigned int time_passed)=0;
	virtual void show()=0;
	virtual void erase()=0;
	virtual void draw()=0;
};

#endif
