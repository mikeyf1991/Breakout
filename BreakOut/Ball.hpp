#pragma once
#include "BaseShape.hpp"

#include <SFML\Graphics.hpp>

class Ball : public BaseShape<sf::CircleShape>
{
public:
	Ball(sf::Vector2f postion, float size, sf::Color colour);
	void setvel(sf::Vector2f vel);
	sf::Vector2f getvel();

private:
	sf::Vector2f velocity;

};

