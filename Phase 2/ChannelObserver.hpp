#ifndef CHANNEL_OBSERVER_H
#define CHANNEL_OBSERVER_H "CHANNEL_OBSERVER_H"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ChannelBot.hpp"

typedef std::vector<ChannelBot*> ChannelBots;

class ChannelObserver
{
public:
    ChannelObserver();
    void addBot(ChannelBot* botToAdd);
    Channel* getChannelForEcho();
    Channel* getChannelForFred();
    Channel* getChannelForLibrarian();
    void getAddressForLogger(std::string message);

private:
    ChannelBots channelBots;
};

#endif 