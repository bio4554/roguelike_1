#include "PlayerInputSystem.hpp"

#include <iostream>
#include <optional>

namespace cyberrogue
{
	PlayerInputSystem::PlayerInputSystem(MessageBus* messageBus, Entity* pla) : System(messageBus), player(pla)
	{
	}


	void PlayerInputSystem::update()
	{
		std::cout << "Update PlayerInputSystem" << std::endl;
		SDL_PollEvent(&event);

		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				--player->position.y;
				send({ "PLAYER_MOVED", {{"x", std::to_string(player->position.x)},{"y",std::to_string(player->position.y)}}});
				break;
			case SDLK_s:
				++player->position.y;
				send({ "PLAYER_MOVED", {{"x", std::to_string(player->position.x)},{"y",std::to_string(player->position.y)}} });
				break;
			case SDLK_a:
				--player->position.x;
				send({ "PLAYER_MOVED", {{"x", std::to_string(player->position.x)},{"y",std::to_string(player->position.y)}} });
				break;
			case SDLK_d:
				++player->position.x;
				send({ "PLAYER_MOVED", {{"x", std::to_string(player->position.x)},{"y",std::to_string(player->position.y)}} });
				break;
			default:
				break;
			}
		} else if(event.type == SDL_QUIT)
		{
			send({ "SDL_QUIT" });
		}
		
	}


	void PlayerInputSystem::onNotify(Message message)
	{
		
	}
}
