#pragma once
#include "BaseShape.hpp"

#include <SFML\Graphics.hpp>

class Ball : public BaseShape<sf::CircleShape>
{
public:
	Ball(sf::Vector2f postion, float size, sf::Color colour);
	void setvel(sf::Vector2f vel);
	sf::Vector2f getvel();
	sf::Vector2f getStartPos();
	sf::Vector2f setStartVel();

	void setPosition();

private:
	sf::Vector2f velocity;
	sf::Vector2f StartPos;
	sf::Vector2f StartVel;

};

