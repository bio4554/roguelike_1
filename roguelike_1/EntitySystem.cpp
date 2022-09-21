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
		return true;
	}

}
