#pragma once
#include <libtcod/libtcod.hpp>

#include "BusNode.hpp"

namespace cyberrogue
{
	class Graphics : public BusNode
	{
	public:
		Graphics(int width, int height, const std::string& title, int argc, char* argv[], MessageBus* messageBus);

		void render();

	private:
		void onNotify(Message message) override;
		void nUpdate() override;

		tcod::Console mainConsole;
		tcod::Context mainContext;
	};
}
