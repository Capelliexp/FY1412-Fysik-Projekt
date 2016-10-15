#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ground : public Drawable
{
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	bool collision;

	//gröna
	RectangleShape grass1;
	RectangleShape grass2;

	//bruna
	RectangleShape dirt1;
	RectangleShape dirt2;
	RectangleShape dirt3;

	//texturer
	Texture grassTex;
	Texture dirtTex;

	Ground();
	~Ground();
};
#endif