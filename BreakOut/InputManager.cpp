#include "InputManager.hpp"
#include <functional>

void InputManager::initialise()
{
	left_click_ = false;
	right_click_ = false;

	for (int i = 0; i < InputKey::key_count; ++i)
	{
		key_released_[i] = false;
		key_pressed_[i] = false;
	}
}

void InputManager::reset()
{
	for (int i = 0; i < InputKey::key_count; ++i)
	{
		key_released_[i] = false;
	}
}

void InputManager::update()
{
	reset();

	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window_.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			for (int i = 0; i < key_count; ++i)
			{
				if (event.key.code == i)
				{
					key_pressed_[i] = true;
				}
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			for (int i = 0; i < key_count; ++i)
			{
				if (event.key.code == i)
				{
					key_pressed_[i] = false;
					key_released_[i] = true;
				}
			}
		}
	}

	left_click_ = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	right_click_ = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	mouse_x_ = sf::Mouse::getPosition(window_).x;
	mouse_y_ = sf::Mouse::getPosition(window_).y;
}

