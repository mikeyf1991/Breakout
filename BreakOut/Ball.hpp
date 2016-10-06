#pragma once
#include "BaseShape.hpp"

#include <SFML\Graphics.hpp>

class Ball : public BaseShape<sf::CircleShape>
{
public:
	Ball(sf::Vector2f postion, float size, sf::Color colour);
	bool getvis();
	void setvis();

private:
	bool vis;

};

