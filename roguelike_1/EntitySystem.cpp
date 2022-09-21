#include "EntitySystem.hpp"

#include <iostream>

namespace cyberrogue
{
	EntitySystem::EntitySystem(MessageBus* messageBus) : System(messageBus)
	{
		
	}


	bool EntitySystem::update()
	{
		std::cout << "update entities" << std::endl;
		//mEngine->

		for(const auto& entity : entities)
		{
			std::map<std::string, std::string> messageData;
			messageData["x"] = std::to_string(entity.second->position.x);
			messageData["y"] = std::to_string(entity.second->position.y);
			messageData["str"] = entity.second->render.glyph;
			auto message = Message("DRAW_CHAR", messageData);
			send(message);
		}

		return true;
	}

	bool EntitySystem::registerEntity(Entity* entity)
	{
		entities[ecount_] = entity;
		ecount_++;
		return true;
	}

	void EntitySystem::onNotify(Message message)
	{
		
	}
}
