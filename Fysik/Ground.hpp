#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ground : public Drawable
{
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	Ground();
	~Ground();

	bool collision;

	//gr�na
	RectangleShape g1;
	RectangleShape g2;

	//bruna
	RectangleShape w1;
	RectangleShape w2;
	RectangleShape w3;

	//N�got i stil med detta
	//void Update(float dt);
	//bool Update(float dt, Hero hero_object, Enemy enemy_object);
};




#endif