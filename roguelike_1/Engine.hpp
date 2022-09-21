#pragma once
#define SDL_MAIN_HANDLED

#include <map>

#include "Position.hpp"
#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>

#include <string>
#include <typeindex>

#include "Entity.hpp"
#include "System.hpp"

namespace cyberrogue
{
	class Engine
	{
	public:
		Engine(int width, int height, const std::string& title, int argc, char* argv[]);
		~Engine();
		static Engine current;

		void HandleEvents();

		bool IsRunning() const;
		void Render();
		void ProcessSystems();

		bool DrawObject(pos_t position, renderable render);

	private:
		void RegisterSystems();

		tcod::Console mainConsole;
		tcod::Context mainContext;
		Entity player;
		SDL_Event event;
		std::map<std::type_index, std::unique_ptr<System>> systems;
	};
}
