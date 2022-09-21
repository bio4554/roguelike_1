#pragma once
#define SDL_MAIN_HANDLED

#include "Position.hpp"
#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>

#include <string>

namespace tutorial
{
	class Engine
	{
	public:
		Engine(int width, int height, const std::string& title, int argc, char* argv[]);
		~Engine();

		void HandleInput();

		bool IsRunning() const;
		void Render();

	private:
		tcod::Console mainConsole;
		tcod::Context mainContext;
		pos_t player_pos_;
		SDL_Event event;
	};
}