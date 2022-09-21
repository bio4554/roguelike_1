#pragma once
#include <libtcod/libtcod.hpp>

#include "BusNode.hpp"
#include "System.hpp"
#include "Renderable.hpp"

namespace cyberrogue
{
	class Graphics : public System
	{
	public:
		Graphics(int width, int height, const std::string& title, int argc, char* argv[], MessageBus* messageBus);

		void render();
		void clear();
		bool update() override;

	private:
		void onNotify(Message message) override;
		
		void drawChar(int x, int y, std::string str);


		renderable mMap[40][40];
		tcod::Console mainConsole;
		tcod::Context mainContext;
	};
}
