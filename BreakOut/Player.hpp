#pragma once

#include "BaseShape.hpp"

#include <SFML\Graphics.hpp>

class Player : public BaseShape<sf::RectangleShape>
{
public:
	Player(sf::Vector2f postion, sf::Vector2f size, sf::Color colour);

private:

	
};