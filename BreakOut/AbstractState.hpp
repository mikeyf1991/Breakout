#pragma once
#include "StateManager.hpp"
#include <SFML\System\NonCopyable.hpp>

class AbstractState : private sf::NonCopyable // Abstract state finite state machine for the playing state 
{
public:
	AbstractState(StateManager& state_manager) :
		state_manager_(state_manager),
		paused_(false)
	{

	}

	virtual ~AbstractState() {}

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void update(const sf::Time& delta) = 0;
	virtual void render() = 0;
	virtual void handle_input(const sf::Time& delta) = 0;
	virtual void handle_state_changes() = 0;

	void set_paused(bool pause) { paused_ = pause; }
	bool get_paused() const { return paused_; }

protected:
	StateManager& state_manager_;
private:
	bool paused_;
	const std::string state_name_;
};