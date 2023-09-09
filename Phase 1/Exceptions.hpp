#ifndef EXCEPTIONSO_H
#define EXCEPTIONSO_H "EXCEPTIONSO_H"

#include <string>
#include <vector>

class InvalidId : public std::exception
{
public:
    InvalidId();
    const char* what() const noexcept;

private:
};

class DuplicateKey : public std::exception
{
public:
    DuplicateKey();
    const char* what() const noexcept ;

private:
};

class UndefinedType : public std::exception
{
public:
    UndefinedType();
    const char* what() const noexcept ;

private:
};
#endif 