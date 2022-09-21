#pragma once

#include <functional>
#include <queue>
#include <vector>

#include "Message.hpp"

namespace cyberrogue
{
	class MessageBus
	{
	public:
		MessageBus() {  }
		~MessageBus() {  }

		void addReceiver(std::function<void(Message)> messageReceiver);

		void sendMessage(Message message);

		void notify();

	private:
		std::vector<std::function<void(Message)>> receivers;
		std::queue<Message> messages;
	};
}
