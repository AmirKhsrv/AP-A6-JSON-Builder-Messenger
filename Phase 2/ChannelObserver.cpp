#include "ChannelObserver.hpp"

using namespace std;

ChannelObserver::ChannelObserver()
{

}

void ChannelObserver::addBot(ChannelBot* botToAdd)
{
    channelBots.push_back(botToAdd);
}

Channel* ChannelObserver::getChannelForEcho()
{
    for (int i = 0; i < channelBots.size(); i++)
        if (channelBots[i]->getBotType() == "echo")
            return channelBots[i]->getChannel();
    return NULL;
}

Channel* ChannelObserver::getChannelForFred()
{
    for (int i = 0; i < channelBots.size(); i++)
        if (channelBots[i]->getBotType() == "fred")
            return channelBots[i]->getChannel();
    return NULL;
}

Channel* ChannelObserver::getChannelForLibrarian()
{
    for (int i = 0; i < channelBots.size(); i++)
        if (channelBots[i]->getBotType() == "librarian")
            return channelBots[i]->getChannel();
    return NULL;
}

void ChannelObserver::getAddressForLogger(std::string message)
{
    for (int i = 0; i < channelBots.size(); i++)
        if (channelBots[i]->getBotType() == "logger")
            channelBots[i]->notifyAndRun(message);
}