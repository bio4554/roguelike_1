#pragma once
#include "System.hpp"

namespace cyberrogue
{
	class EntitySystem : public System
	{
	public:
		EntitySystem();
		bool update() override;
	};
}
