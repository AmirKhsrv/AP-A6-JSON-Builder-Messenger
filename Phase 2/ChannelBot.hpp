#ifndef CHANNEL_BOT_H
#define CHANNEL_BOT_H "CHANNEL_BOT_H"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Exceptions.hpp"

typedef std::string Address;

class Channel;

class ChannelBot
{
public:
    ChannelBot();
    virtual void notifyAndRun(std::string channelMessage) = 0;
    virtual std::string getBotType() = 0;
    virtual Channel* getChannel() = 0;

protected:

};

class EchoBot : public ChannelBot
{
public:
    EchoBot(Channel* channel);
    std::string getBotType();
    Channel* getChannel();
    void notifyAndRun(std::string channelMessage);

private:
    Channel* destinationChannel;
};

class LoggerBot : public ChannelBot
{
public:
    LoggerBot(Address fileAddress);
    std::string getBotType();
    Address getAddress();
    void notifyAndRun(std::string channelMessage);
    Channel* getChannel();

private:
    Address logFileAdress;
};

class FredBot : public ChannelBot
{
public:
    FredBot(Channel* _channel);
    std::string getBotType();
    Channel* getChannel();
    void notifyAndRun(std::string channelMessage);

private:
    Channel* channel;
};

class LibrarianBot : public ChannelBot
{
public:
    LibrarianBot(Channel* _channel);
    std::string getBotType();
    Channel* getChannel();
    void notifyAndRun(std::string channelMessage);

private:
    Channel* channel;
    int messageCounter;
};

#endif 