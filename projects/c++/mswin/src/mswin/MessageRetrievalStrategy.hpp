#ifndef __MESSAGE__RETRIEVAL__STRATEGY__H__
#define __MESSAGE__RETRIEVAL__STRATEGY__H__

#include <utility>
#include <string>

class MessageRetrievalStrategy
{
friend class MessageRetrievalStrategies;
protected:
	std::pair<int,std::string> strategy;
	MessageRetrievalStrategy(int,std::string);
public:
	std::string getName() const;
	int getValue() const;
};

class MessageRetrievalStrategies
{
public:
	MessageRetrievalStrategy UsePeekMessage = MessageRetrievalStrategy(1,"UsePeekMessage");
	MessageRetrievalStrategy UseGetMessage = MessageRetrievalStrategy(2,"UseGetMessage");
};

#endif
