#include "Engine.hpp"

#include <ranges>
#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>

#include "EntitySystem.hpp"

namespace cyberrogue
{
	static std::unique_ptr<Engine> mEngine;
	constexpr char PLAYER_ICON = '@';
	constexpr int MAX_FPS = 60;

	Engine::Engine(int width, int height, const std::string& title, int argc, char* argv[])
	: messageBus(), graphics(width, height, title, argc, argv, &messageBus), player({width / 2, height / 2}, {"@"})
	{

		RegisterSystems();
	}

	Engine::~Engine()
	{
		TCOD_quit();
	}

	void Engine::HandleEvents()
	{
		SDL_PollEvent(&event);

		if(event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				--player.position.y;
				break;
			case SDLK_s:
				++player.position.y;
				break;
			case SDLK_a:
				--player.position.x;
				break;
			case SDLK_d:
				++player.position.x;
				break;
			default:
				break;
			}
		}
	}

	void Engine::RunGame()
	{
		while(true)
		{
			ProcessSystems();
			HandleEvents();
			graphics.render();
		}
	}


	bool Engine::IsRunning() const
	{
		return (event.type != SDL_QUIT);
	}

	void Engine::RegisterSystems()
	{
		systems[typeid(EntitySystem)] = std::make_unique<EntitySystem>();
	}

	void Engine::ProcessSystems()
	{
		for(const auto& system : systems | std::views::values)
		{
			system->update();
		}
	}
}
