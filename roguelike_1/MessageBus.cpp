#include "MessageBus.hpp"

namespace cyberrogue
{
	void MessageBus::addReceiver(std::function<void(Message)> messageReceiver)
	{
		receivers.push_back(messageReceiver);
	}

	void MessageBus::sendMessage(Message message)
	{
		messages.push(message);
	}

	void MessageBus::notify()
	{
		while(!messages.empty()) // empty the message queue
		{
			for(const auto& func : receivers) // send message to each system
			{
				func(messages.front());
			}

			messages.pop();
		}
	}


}