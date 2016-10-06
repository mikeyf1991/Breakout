#pragma once

#include "InputKey.hpp"

#include <SFML\Graphics.hpp>


#include <list>

class InputManager : private sf::NonCopyable // class for handling the keypresses, telling the program what to do with each one.
{
public:
	InputManager(sf::Window& window) :
		window_(window),
		left_click_(false),
		right_click_(false),
		mouse_x_(0),
		mouse_y_(0)
	{
		initialise();
	}

	void update();

	inline const bool left_clicked() const
	{
		return left_click_;
	}

	inline const bool right_clicked() const
	{
		return right_click_;
	}

	inline const bool is_key_released(int key) const
	{
		return key_released_[key];
	}

	inline const bool is_key_pressed(int key) const
	{
		return key_pressed_[key];
	}

	inline const int get_mouse_x() const
	{
		return mouse_x_;
	}

	inline const int get_mouse_y() const
	{
		return mouse_y_;
	}

private:
	sf::Window& window_;

	bool key_released_[sf::Keyboard::KeyCount];
	bool key_pressed_[sf::Keyboard::KeyCount];

	bool left_click_;
	bool right_click_;

	int mouse_x_;
	int mouse_y_;

	void initialise();
	void reset();
};