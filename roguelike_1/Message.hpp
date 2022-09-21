#pragma once
#include <map>
#include <string>

namespace cyberrogue
{
	class Message
	{
	public:
		Message(const std::string type, std::map<std::string, std::string> data);
		Message(const std::string type);

		std::string getType();
		std::map<std::string, std::string> getData();

	private:
		std::string messageType;
		std::map<std::string, std::string> messageData;
	};
}
