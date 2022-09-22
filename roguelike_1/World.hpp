#pragma once

#include <vector>

#include "BusNode.hpp"
#include "Graphics.hpp"
#include "System.hpp"
#include "Tile.hpp"

namespace cyberrogue
{
	class World : public System
	{
	public:
		World(MessageBus* messageBus, Graphics* graphics);

		void update() override;

	private:
		void onNotify(Message message) override;
		void initWorld(int width, int height);
		void drawMap();

		Graphics* graphics;
		std::vector<std::vector<Tile>> currentMap; // maybe should use static array
	};
}