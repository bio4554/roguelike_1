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
		bool update() override; // System update
		bool registerEntity(std::unique_ptr<Entity> entity);
		void nUpdate() override; // BusNode update



	private:
		void onNotify(Message message) override;

		std::map<unsigned int, std::unique_ptr<Entity>> entities;
		unsigned int ecount_ = 0;
	};
}
