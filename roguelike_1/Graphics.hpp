#pragma once
#include <libtcod/libtcod.hpp>

#include "BusNode.hpp"
#include "System.hpp"
#include "renderable_t.hpp"

namespace cyberrogue
{
	class Graphics : public System
	{
	public:
		Graphics(int width, int height, const std::string& title, int argc, char* argv[], MessageBus* messageBus);

		void render();
		void clear();
		void update() override;
		void drawAt(int x, int y, std::string str); // should only be used in scenarios where performance is critical (bypass the message bus)

	private:
		void onNotify(Message message) override;


		renderable_t mMap[40][40];
		tcod::Console mainConsole;
		tcod::Context mainContext;
	};
}
