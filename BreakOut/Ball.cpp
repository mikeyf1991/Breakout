#include "Ball.hpp"



Ball::Ball(sf::Vector2f position, float size, sf::Color colour)
{
	m_shape.setRadius(size);
	m_shape.setOutlineThickness(3);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setFillColor(colour);
	
	m_shape.setPosition(position);
	m_shape.setOrigin(position.x + size, position.y + size);
}