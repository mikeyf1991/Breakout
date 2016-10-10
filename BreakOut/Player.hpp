#pragma once

#include "BaseShape.hpp"

#include <SFML\Graphics.hpp>

class Player : public BaseShape<sf::RectangleShape>
{
public:
	Player(sf::Vector2f position, sf::Vector2f size, sf::Color colour);
	sf::Vector2f getStartPos();
	void setPosition();

private:
	int lives;
	sf::Vector2f startPos;
	
};