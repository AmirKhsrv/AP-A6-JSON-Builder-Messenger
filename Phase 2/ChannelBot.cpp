#include "ChannelBot.hpp"

using namespace std;

ChannelBot::ChannelBot()
{

}

EchoBot::EchoBot(Channel* channel)
{
    destinationChannel = channel;
}

LoggerBot::LoggerBot(Address fileAddress)
{
    logFileAdress = fileAddress;
}

FredBot::FredBot(Channel* _channel)
{
    channel = _channel;
}

LibrarianBot::LibrarianBot(Channel* _channel)
{
    messageCounter = 1;
    channel = _channel;
}

void LoggerBot::notifyAndRun(std::string channelMessage)
{
    ofstream logFileStream;
    logFileStream.open(logFileAdress, std::ios_base::app);
    logFileStream << channelMessage;
    logFileStream.close();
}

void EchoBot::notifyAndRun(std::string channelMessage)
{

}

void FredBot::notifyAndRun(std::string channelMessage)
{
    
}

void LibrarianBot::notifyAndRun(std::string channelMessage)
{
    
}

string EchoBot::getBotType()
{
    return "echo";
}

string LoggerBot::getBotType()
{
    return "logger";
}

string FredBot::getBotType()
{
    return "fred";
}

string LibrarianBot::getBotType()
{
    return "librarian";
}

Channel* EchoBot::getChannel()
{
    return destinationChannel;
}

Channel* FredBot::getChannel()
{
    return channel;
}

Channel* LibrarianBot::getChannel()
{
    return channel;
    messageCounter++;
}

Address LoggerBot::getAddress()
{
    return logFileAdress;
}

Channel* LoggerBot::getChannel()
{

}
