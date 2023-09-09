#include "Messenger.hpp"

using namespace std;

Messenger::Messenger()
{

}

void Messenger::getOrder()
{
    string order;
    cin >> order;
    if (order == ADD_CHANNEL)
        addChannel();
    if (order == ADD_BOT)
        addBot();
    if (order == Tell)
        tellChannel();
}

void Messenger::addChannel()
{
    string channelName;
    cin >> channelName;
    if (findChannelByName(channelName) == NULL)
        channels.push_back(new Channel(channelName));
    else
        throw ExistingChannel();
}

Channel* Messenger::findChannelByName(std::string channelName)
{
    for (int i = 0; i < channels.size(); i++)
        if (channelName == channels[i]->getName())
            return channels[i];
    return NULL;
}

void Messenger::addBot()
{
    string botType;
    cin >> botType;
    if (botType == ECHO_BOT)
        addEchoBot();
    if (botType == LOGGER_BOT)
        addLoggerBot();
    if (botType == FRED_BOT)
        addFredBot();
    if (botType == LIBRARIAN_BOT)
        addLibrarianBot();    
}

void Messenger::addEchoBot()
{
    string srcChannel, destChannel;
    cin >> srcChannel;
    cin >> destChannel;
    if (findChannelByName(srcChannel) == NULL || findChannelByName(destChannel) == NULL)
        throw NoMatchingChannel();
    if (srcChannel == destChannel)
        throw SameSourceAndDestination();
    EchoBot* newEchoBot = new EchoBot(findChannelByName(destChannel));
    findChannelByName(srcChannel)->addBot(newEchoBot);
}

void Messenger::addLoggerBot()
{
    Address logFileAddress;
    cin >> logFileAddress;
    LoggerBot* loggerBot = new LoggerBot(logFileAddress);
    for (int i = 0; i < channels.size(); i++)
        channels[i]->addBot(loggerBot);
}
void Messenger::addFredBot()
{
    string channel;
    cin >> channel;
    if (findChannelByName(channel) == NULL)
        throw NoMatchingChannel();
    FredBot* newFredBot = new FredBot(findChannelByName(channel));
    findChannelByName(channel)->addBot(newFredBot); 
}

void Messenger::addLibrarianBot()
{
    string channel;
    cin >> channel;
    if (findChannelByName(channel) == NULL)
        throw NoMatchingChannel();
    LibrarianBot* newLibrarianBot = new LibrarianBot(findChannelByName(channel));
    findChannelByName(channel)->addBot(newLibrarianBot);
}

void Messenger::tellChannel()
{
    string channel;
    cin >> channel;
    if (findChannelByName(channel) == NULL)
        throw NoMatchingChannel();
    string messageToTell;
    getline(cin, messageToTell);
    for (int i = 1; i < messageToTell.size(); i++)
        messageToTell[i - 1] = messageToTell[i];
    messageToTell[messageToTell.size() - 1] = '\n';
    findChannelByName(channel)->tell(messageToTell);
}
