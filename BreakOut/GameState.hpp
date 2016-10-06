#pragma once
#include "AbstractState.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Ball.hpp"

#include <iostream>
#include <random>
#include <vector>

class GameState : public AbstractState // This is the main game state where everthing needed is created, this extends from the AbstractState class.
{
public:
	GameState(StateManager& state_manager);
	~GameState();

	void pause() override final;
	void resume() override final;

	void update(const sf::Time& delta) override final;
	void render() override final;
	void handle_input(const sf::Time& delta) override final;
	void handle_state_changes() override final;



private:

	void create_Blocks();
	void check_collisions();
	
	Player player_;

	float velx;

	std::vector<Block> blocks_;

	Ball ball_;

	sf::View view_main;
	sf::Texture background;
	sf::Sprite bg_sprite;

};
