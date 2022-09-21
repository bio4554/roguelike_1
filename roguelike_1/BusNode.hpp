#pragma once
#include "MessageBus.hpp"

namespace cyberrogue
{
	class BusNode
	{
	public:
		BusNode(MessageBus* messageBus);

	protected:
		MessageBus* messageBus;

		std::function<void(Message)> getNotifyFunc();

		void send(Message message);

		virtual void onNotify(Message message) = 0; // all classes must implement message handling different
	};
}
