#include "Channel.hpp"

using namespace std;

Channel::Channel(std::string chName)
{
    channelName = chName;
    channelObserver = new ChannelObserver();
    sentMessageCounter = 0;
}

string Channel::getName()
{
    return channelName;
}

void Channel::addBot(ChannelBot* botToAdd)
{
    channelObserver->addBot(botToAdd);
}

void Channel::tell(std::string MessegeToTell)
{
    sentMessageCounter++;
    channelObserver->getAddressForLogger(MessegeToTell);
    if (channelObserver->getChannelForEcho() != NULL)
        channelObserver->getChannelForEcho()->tell(MessegeToTell);
    if (channelObserver->getChannelForFred() != NULL)
        if (MessegeToTell == "Hi\n")
            channelObserver->getChannelForFred()->tell("Hello\n");
    if (sentMessageCounter == 5 || (sentMessageCounter > 4 && sentMessageCounter % 5 == 4))
        channelObserver->getChannelForLibrarian()->tell("Quiet!\n");
}
