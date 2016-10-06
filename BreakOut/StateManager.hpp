#pragma once

#include "Helpers.hpp"
#include "InputManager.hpp"

#include <SFML\Graphics.hpp>
#include <SFML\System\NonCopyable.hpp>

#include <stack>
#include <memory>
#include <string>

class AbstractState;

class StateManager : private sf::NonCopyable
{
public:
	StateManager(std::string window_title, const int width = 800, const int height = 600);
	~StateManager();

	void change_state(std::unique_ptr<AbstractState> state);
	void push_state(std::unique_ptr<AbstractState> state);
	void pop_state();

	int run();

	void quit()
	{
		running_ = false;
	}

	sf::RenderWindow& get_render_window()
	{
		return render_window_;
	}

	InputManager& get_input_manager()
	{
		return input_manager_;
	}

	template<typename T>
	std::unique_ptr<T> state_ptr();

protected:
private:
	sf::RenderWindow render_window_;
	InputManager input_manager_;

	std::stack<std::unique_ptr<AbstractState>> states_;

	bool running_;

	const sf::Time time_per_frame_;

	void render();
	void update(const sf::Time& delta);
	void handle_input(const sf::Time& delta);
	void handle_state_changes();

	bool is_running() const { return running_ && render_window_.isOpen(); }
};

template<typename T>
std::unique_ptr<T> StateManager::state_ptr()
{
	return std::move(std::unique_ptr<T>(new T(*this)));
}