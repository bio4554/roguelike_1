#include "EntitySystem.hpp"

#include <iostream>

namespace cyberrogue
{
	EntitySystem::EntitySystem(MessageBus* messageBus) : System(messageBus)
	{
		
	}


	void EntitySystem::update()
	{
#ifdef _DEBUG
		std::cout << "Update Entities" << std::endl;
#endif

		for(const auto& entity : entities)
		{
			std::map<std::string, std::string> messageData;
			messageData["x"] = std::to_string(entity.second->position.x);
			messageData["y"] = std::to_string(entity.second->position.y);
			messageData["str"] = entity.second->render.glyph;
			auto message = Message("DRAW_CHAR", messageData);
			send(message);
		}
	}

	unsigned int EntitySystem::registerEntity(Entity* entity)
	{
		entities[ecount_] = entity;
		ecount_++;
		return ecount_ - 1;
	}

	void EntitySystem::onNotify(Message message)
	{
		
	}

	Entity* EntitySystem::getEntity(unsigned id)
	{
		return entities[id];
	}

	void EntitySystem::moveEntity(int x, int y, unsigned id)
	{
		entities[id]->position.x = x;
		entities[id]->position.y = y;
	}


}
