#include "PlayerInputSystem.hpp"

#include <optional>

namespace cyberrogue
{
	PlayerInputSystem::PlayerInputSystem(MessageBus* messageBus, Entity* pla) : System(messageBus), player(pla)
	{
	}


	bool PlayerInputSystem::update()
	{
		SDL_PollEvent(&event);

		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				--player->position.y;
				break;
			case SDLK_s:
				++player->position.y;
				break;
			case SDLK_a:
				--player->position.x;
				break;
			case SDLK_d:
				++player->position.x;
				break;
			default:
				break;
			}
		} else if(event.type == SDL_QUIT)
		{
			send({ "SDL_QUIT" });
		}

		return true;
	}


	void PlayerInputSystem::onNotify(Message message)
	{
		
	}
}
