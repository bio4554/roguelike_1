#pragma once
#include <map>
#include <typeindex>

#include "System.hpp"

class ServiceLocator
{
public:
private:
	std::map<std::type_index, cyberrogue::System*> systems;
};
