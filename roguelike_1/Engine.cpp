#include "Engine.hpp"

#include <ranges>
#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>

#include "EntitySystem.hpp"

namespace cyberrogue
{
	constexpr char PLAYER_ICON = '@';
	constexpr int MAX_FPS = 60;

	Engine::Engine(int width, int height, const std::string& title, int argc, char* argv[]) : player({ width / 2, height / 2 }, { "@" })
	{
		mainConsole = tcod::Console(width, height);
		auto params = TCOD_ContextParams{};
		params.tcod_version = TCOD_COMPILEDVERSION;  // This is required.
		params.console = mainConsole.get();  // Derive the window size from the console size.
		params.window_title = "Libtcod Project";
		params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
		params.vsync = true;
		params.argc = argc;  // This allows some user-control of the context.
		params.argv = argv;

		mainContext = tcod::Context(params);

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

	bool Engine::IsRunning() const
	{
		return (event.type != SDL_QUIT);
	}

	void Engine::Render()
	{
		TCOD_console_clear(mainConsole.get());

		tcod::print(mainConsole, { player.position.x, player.position.y }, player.render.glyph, std::nullopt, std::nullopt);

		mainContext.present(mainConsole);
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
