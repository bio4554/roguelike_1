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
		MessageBus(std::function<void(Message)> engRec) { engineReceiver = engRec; }
		~MessageBus() {  }

		void addReceiver(std::function<void(Message)> messageReceiver);

		void sendMessage(Message message);

		void notify();

		Message peek();

	private:
		std::function<void(Message)> engineReceiver;
		std::vector<std::function<void(Message)>> receivers;
		std::queue<Message> messages;
	};
}
