#include "Engine.hpp"

#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>

namespace tutorial
{
	constexpr char PLAYER_ICON = '@';
	constexpr int MAX_FPS = 60;

	Engine::Engine(int width, int height, const std::string& title, int argc, char* argv[])
		: player_pos_(pos_t {width / 2, height / 2})
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
	}

	Engine::~Engine()
	{
		TCOD_quit();
	}

	void Engine::HandleInput()
	{
		TCOD_key_t key;

		SDL_PollEvent(&event);

		if(event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				--player_pos_.y;
				break;
			case SDLK_s:
				++player_pos_.y;
				break;
			case SDLK_a:
				--player_pos_.x;
				break;
			case SDLK_d:
				++player_pos_.x;
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

		tcod::print(mainConsole, { player_pos_.x, player_pos_.y }, "@", std::nullopt, std::nullopt);

		mainContext.present(mainConsole);
	}
}