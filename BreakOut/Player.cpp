#include "Player.hpp"

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Color colour)
{
	m_shape.setSize(size);
	m_shape.setOutlineThickness(3);
	m_shape.setOutlineColor(sf::Color::Green);
	m_shape.setFillColor(colour);
	m_shape.setOrigin(size / 2.f);

	m_shape.setPosition(position);

	startPos = position;
}

sf::Vector2f Player::getStartPos()
{
	return startPos;
}

void Player::setPosition()
{
	m_shape.setPosition(startPos);
}