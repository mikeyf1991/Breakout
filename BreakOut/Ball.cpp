#include "Ball.hpp"



Ball::Ball(sf::Vector2f position, float size, sf::Color colour)
{
	m_shape.setRadius(size);
	m_shape.setOutlineThickness(3);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setFillColor(colour);
	
	m_shape.setPosition(position);

	StartPos = position;
}

sf::Vector2f Ball::setStartVel()
{
	int randomint = rand() / (RAND_MAX / 2);

	float randomX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5));

	if (randomint == 1)
	{
		randomX *= -1;
	}

	return sf::Vector2f(randomX, -5.0f);
}

void Ball::setvel(sf::Vector2f vel)
{
	velocity = vel;
}

sf::Vector2f Ball::getvel()
{
	return velocity;
}

sf::Vector2f Ball::getStartPos()
{
	return StartPos;
}