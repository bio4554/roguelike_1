#pragma once
#include <string>

namespace cyberrogue
{
	class Message
	{
	public:
		Message(const std::string event);

		std::string getEvent();

	private:
		std::string messageEvent;
	};
}
