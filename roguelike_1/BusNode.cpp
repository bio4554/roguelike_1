#include "BusNode.hpp"

namespace cyberrogue
{
	BusNode::BusNode(MessageBus* messageBus) : messageBus(messageBus)
	{
		this->messageBus->addReceiver(this->getNotifyFunc());
	}

	std::function<void(Message)> BusNode::getNotifyFunc()
	{
		auto messageListener = [=](Message message) -> void
		{
			this->onNotify(message);
		};
		return messageListener;
	}

	void BusNode::send(Message message)
	{
		messageBus->sendMessage(message);
	}
}