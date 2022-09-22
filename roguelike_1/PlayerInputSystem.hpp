#pragma once
#include <SDL2/SDL_events.h>

#include "BusNode.hpp"
#include "Entity.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
#include "System.hpp"

namespace cyberrogue
{
	class PlayerInputSystem : public System
	{
	public:
		PlayerInputSystem(MessageBus* messageBus, Entity* pla);
		void update() override; // System update
	private:
		void onNotify(Message message) override;

		SDL_Event event;
		Entity* player;
	};
}


