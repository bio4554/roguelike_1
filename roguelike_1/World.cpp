#include "World.hpp"

#include <iostream>

namespace cyberrogue
{
	World::World(MessageBus* messageBus, Graphics* graphics) : System(messageBus), graphics(graphics)
	{
		initWorld(50, 50);
	}

	void World::onNotify(Message message)
	{
//#ifdef _DEBUG
//		//std::cout << "World received message: " << message.getType() << std::endl;
//#endif
	}

	void World::update()
	{
		std::cout << "Update World" << std::endl;
		drawMap();
	}

	void World::drawMap()
	{
		for(int y = 0; y < currentMap.size(); y++)
		{
			for(int x = 0; x < currentMap[y].size(); x++)
			{
				graphics->drawAt(x, y, currentMap[y][x].render.glyph); // way fucking faster
				/*std::map<std::string, std::string> messageData;
				messageData["x"] = std::to_string(x);
				messageData["y"] = std::to_string(y);
				messageData["str"] = currentMap[y][x].render.glyph;
				auto message = Message("DRAW_CHAR", messageData);
				send(message);*/
			}
		}
	}


	// fill current map with empty dots
	void World::initWorld(int width, int height)
	{
		for(int y = 0; y < height; y++)
		{
			currentMap.emplace_back(width);
			for(auto& col : currentMap[y])
			{
				col.render = { "." };
			}
		}
	}


}
