#include "Exceptions.hpp"

using namespace std;

ExistingChannel::ExistingChannel()
{

}

NoMatchingChannel::NoMatchingChannel()
{
    
}

SameSourceAndDestination::SameSourceAndDestination()
{
    
}

const char* ExistingChannel::what() const noexcept 
{
    return "Channel already exists\n";
}

const char* NoMatchingChannel::what() const noexcept 
{
    return "Channel does not exist\n";
}

const char* SameSourceAndDestination::what() const noexcept 
{
    return "Source and destination cannot be the same channel\n";
}