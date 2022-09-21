#include "EntitySystem.hpp"

#include <iostream>

namespace cyberrogue
{
	EntitySystem::EntitySystem()
	{
		
	}


	bool EntitySystem::update()
	{
		std::cout << "update entities" << std::endl;
		//mEngine->
		return true;
	}

	bool EntitySystem::registerEntity(std::unique_ptr<Entity> entity)
	{
		entities[ecount_] = std::move(entity);
		ecount_++;
		return true;
	}

}
