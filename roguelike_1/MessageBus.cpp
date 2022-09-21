#include "MessageBus.hpp"

#include <iostream>

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
			std::cout << "DISPATCH MESSAGE: " << messages.front().getType() << std::endl;
			for(const auto& func : receivers) // send message to each system
			{
				func(messages.front());
			}

			engineReceiver(messages.front()); // notify the engine of the message last

			messages.pop();
		}
	}

	Message MessageBus::peek()
	{
		return messages.front();
	}



}
