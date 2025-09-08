#include "MessageRetrievalStrategy.hpp"

MessageRetrievalStrategy::MessageRetrievalStrategy(int value, std::string name)
{
	strategy = std::make_pair(value,name);
}

std::string MessageRetrievalStrategy::getName() const
{
	return strategy.second;
}

int MessageRetrievalStrategy::getValue() const
{
	return strategy.first;
}