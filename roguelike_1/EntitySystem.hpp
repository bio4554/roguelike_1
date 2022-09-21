#pragma once
#include <map>
#include <memory>
#include <vector>

#include "Entity.hpp"
#include "System.hpp"

namespace cyberrogue
{
	class EntitySystem : public System
	{
	public:
		EntitySystem();
		bool update() override;
		bool registerEntity(std::unique_ptr<Entity> entity);

	private:
		std::map<unsigned int, std::unique_ptr<Entity>> entities;
		unsigned int ecount_ = 0;
	};
}
