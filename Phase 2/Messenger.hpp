#ifndef MESSENGER_H
#define MESSENGER_H "MESSENGER_H"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Channel.hpp"

typedef std::vector<Channel*> Channels;

const std::string ADD_CHANNEL = "add_channel";
const std::string ADD_BOT = "add_bot";
const std::string Tell = "tell";
const std::string ECHO_BOT = "echo";
const std::string LOGGER_BOT = "logger";
const std::string FRED_BOT = "fred";
const std::string LIBRARIAN_BOT = "librarian";

class Messenger
{
public:
    Messenger();
    void getOrder();

private:
    void addChannel();
    Channel* findChannelByName(std::string channelName);
    void addBot();
    void addEchoBot();
    void addLoggerBot();
    void addFredBot();
    void addLibrarianBot();
    void tellChannel();

    Channels channels;
};

#endif 