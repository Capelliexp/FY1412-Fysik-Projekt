#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ground
{
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	Ground();
	~Ground();

};




#endif