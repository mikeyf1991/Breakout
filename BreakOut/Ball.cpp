#include "Ball.hpp"



Ball::Ball(sf::Vector2f position, float size, sf::Color colour)
{
	m_shape.setRadius(size);
	m_shape.setOutlineThickness(3);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setFillColor(colour);
	
	m_shape.setPosition(position);
}

void Ball::setvel(sf::Vector2f vel)
{
	velocity = vel;
}

sf::Vector2f Ball::getvel()
{
	return velocity;
}