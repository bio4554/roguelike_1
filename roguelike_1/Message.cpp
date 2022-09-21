#include "Message.hpp"

#include <utility>

namespace cyberrogue
{
	Message::Message(const std::string type, std::map<std::string, std::string> data) : messageType(type),
		messageData(std::move(data))
	{
	}

	Message::Message(const std::string type) : messageType(type)
	{
		
	}


	std::string Message::getType()
	{
		return messageType;
	}

	std::map<std::string, std::string> Message::getData()
	{
		return messageData;
	}
}