#pragma once

#include "BaseShape.hpp"

#include <SFML\Graphics.hpp>

class Block : public BaseShape<sf::RectangleShape>
{
public:
	Block(sf::Vector2f postion, sf::Vector2f size, sf::Color colour);
	bool getvis();
	void setvis(bool Nvis);

private:
	bool vis;

};