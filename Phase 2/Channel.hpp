#ifndef CHANNEL_H
#define CHANNEL_H "CHANNEL_H"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ChannelObserver.hpp"

class ChannelBot;

class Channel
{
public:
    Channel(std::string chName);
    std::string getName();
    void addBot(ChannelBot* botToAdd);
    void tell(std::string MessegeToTell);

private:
    ChannelObserver* channelObserver;
    std::string channelName;
    int sentMessageCounter;
};

#endif 