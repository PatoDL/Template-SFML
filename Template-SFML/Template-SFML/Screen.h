#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
private:
public:
	virtual void init() = 0;
	virtual void deInit() = 0;
	virtual void checkInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif // !SCREEN_H

