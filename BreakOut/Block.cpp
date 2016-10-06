#include "Block.hpp"



Block::Block(sf::Vector2f position, sf::Vector2f size, sf::Color colour)
{
	m_shape.setSize(size);
	m_shape.setOutlineThickness(3);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setFillColor(colour);
	m_shape.setOrigin(size / 2.f);

	m_shape.setPosition(position);


	vis = true;
}

bool Block::getvis()
{
	return vis;
}

void Block::setvis(bool Nvis)
{
	vis = Nvis;
}