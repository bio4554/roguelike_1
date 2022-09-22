#pragma once
#include <map>
#include <memory>
#include <vector>

#include "BusNode.hpp"
#include "Entity.hpp"
#include "System.hpp"

namespace cyberrogue
{
	class EntitySystem : public System
	{
	public:
		EntitySystem(MessageBus* messageBus);
		void update() override; // System update
		unsigned int registerEntity(Entity* entity);

		Entity* getEntity(unsigned int id);


	private:
		void onNotify(Message message) override;

		void moveEntity(int x, int y, unsigned int id);

		std::map<unsigned int, Entity*> entities;
		unsigned int ecount_ = 0;
	};
}
