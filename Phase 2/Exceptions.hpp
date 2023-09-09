#ifndef EXCEPTIONSO_H
#define EXCEPTIONSO_H "EXCEPTIONSO_H"

#include <string>
#include <vector>

class ExistingChannel : public std::exception
{
public:
    ExistingChannel();
    const char* what() const noexcept;

private:
};

class NoMatchingChannel : public std::exception
{
public:
    NoMatchingChannel();
    const char* what() const noexcept ;

private:
};

class SameSourceAndDestination : public std::exception
{
public:
    SameSourceAndDestination();
    const char* what() const noexcept ;

private:
};
#endif 