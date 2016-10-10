#include "GameState.hpp"

#define LEVEL_WIDTH 1280
#define LEVEL_HEIGHT 768

GameState::GameState(StateManager& state_manager) :
	AbstractState(state_manager),
	player_(sf::Vector2f(LEVEL_WIDTH/2, LEVEL_HEIGHT - 30), sf::Vector2f(200, 25), sf::Color::Transparent),
	ball_(sf::Vector2f(LEVEL_WIDTH/2, LEVEL_HEIGHT - 55), 5.0f, sf::Color::Cyan)
{
	create_Blocks();
	

	view_main.setSize(sf::Vector2f(1360, 768));
	view_main.setCenter(sf::Vector2f(player_.Shape().getPosition().x, player_.Shape().getPosition().y));
	// zoom the view relatively to its current size (apply a factor 0.5, so its final size is 600x400)
	view_main.zoom(1.0f);
	// define a centered viewport, with half the size of the window
	view_main.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));

	if (!background.loadFromFile("Level1_BackGroundComplete2.png"))
	{
		std::cout << "Could not load image\n";
	}

	bg_sprite.setTexture(background);

	ball_.setStartVel();
}

void GameState::create_Blocks()
{
	sf::Color colour[4];
	colour[0] = sf::Color::Red;
	colour[1] = sf::Color::Magenta;
	colour[2] = sf::Color::Blue;
	colour[3] = sf::Color::Green;

	for (auto i = 1; i < 11; ++i)
	{
		for (auto j = 0; j < 4; ++j)
		{
			Block block(sf::Vector2f(100 * i + (i * 20), 35 * (j + 1)), sf::Vector2f(110, 25), colour[j]);
			blocks_.push_back(block);
		}
	}
}

GameState::~GameState() 
{

}

void GameState::pause()
{
	set_paused(true);
}

void GameState::resume()
{
	set_paused(false);
}

void GameState::handle_input(const sf::Time& delta)
{
	auto& inputManager = state_manager_.get_input_manager();

	if (inputManager.is_key_released(InputKey::escape))
	{
		state_manager_.quit();
	}

	if (inputManager.is_key_pressed(InputKey::a))
	{
		player_.Shape().move(sf::Vector2f(-5.0f, 0.0f));
		if (player_.Shape().getPosition().x - (player_.Shape().getSize().x / 2) < 0)
			player_.Shape().setPosition(0 + (player_.Shape().getSize().x / 2), player_.Shape().getPosition().y);

	}
	else if (inputManager.is_key_pressed(InputKey::d))
	{
		player_.Shape().move(sf::Vector2f(5.0f, 0.0f));
		if (player_.Shape().getPosition().x + (player_.Shape().getSize().x / 2) >= LEVEL_WIDTH)
			player_.Shape().setPosition(LEVEL_WIDTH - (player_.Shape().getSize().x / 2), player_.Shape().getPosition().y);
	}
}

void GameState::update(const sf::Time& delta)
{
	ball_.Shape().move(ball_.getvel());
	check_collisions();
	view_main.setCenter(LEVEL_WIDTH/2, LEVEL_HEIGHT/2);
}




void GameState::check_collisions()
{
	for (auto& blocks : blocks_)
	{
		if (blocks.getvis())
		{
			if (blocks.Shape().getGlobalBounds().intersects(ball_.Shape().getGlobalBounds()))
			{
				blocks.setvis(false);
				ball_.setvel(sf::Vector2f(ball_.getvel().x, (-1 * ball_.getvel().y)));
			}
		}
	}

	if (ball_.Shape().getPosition().x + ball_.Shape().getScale().x >= LEVEL_WIDTH)
			ball_.setvel(sf::Vector2f(ball_.getvel().x *-1, ball_.getvel().y));
	
	if(ball_.Shape().getPosition().x <= 0)
			ball_.setvel(sf::Vector2f(ball_.getvel().x *-1, ball_.getvel().y));

	if (ball_.Shape().getPosition().y <= 0)
		ball_.setvel(sf::Vector2f(ball_.getvel().x, ball_.getvel().y *-1));

	if (player_.Shape().getGlobalBounds().intersects(ball_.Shape().getGlobalBounds()))
	{
		ball_.setvel(sf::Vector2f(ball_.getvel().x, (ball_.getvel().y * -1)));
	}
}


void GameState::render()
{

	sf::RenderWindow& window = state_manager_.get_render_window();
	window.setView(view_main); // applying the view

	window.draw(bg_sprite);
	window.draw(player_.Shape());
	for (auto& blocks : blocks_)
	{
		if(blocks.getvis())
		window.draw(blocks.Shape());

	}

	window.draw(ball_.Shape());

}


void GameState::handle_state_changes()
{

}
