#pragma once

namespace cyberrogue
{
	class System : public BusNode
	{
	public:
		System(MessageBus* messageBus) : BusNode(messageBus) {}
		virtual void update() = 0;
	};
}