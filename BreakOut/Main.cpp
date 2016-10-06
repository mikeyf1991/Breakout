#include "StateManager.hpp" 
#include "GameState.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		StateManager state_manager("ShadowPlay");

		state_manager.change_state(state_manager.state_ptr<GameState>());

		return state_manager.run();
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}