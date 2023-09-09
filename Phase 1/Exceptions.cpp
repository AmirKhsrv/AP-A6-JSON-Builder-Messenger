#include "Exceptions.hpp"

using namespace std;

InvalidId::InvalidId()
{

}

DuplicateKey::DuplicateKey()
{
    
}

UndefinedType::UndefinedType()
{
    
}

const char* InvalidId::what() const noexcept 
{
    return "Invalid id.\n";
}

const char* DuplicateKey::what() const noexcept 
{
    return "Duplicate key.\n";
}

const char* UndefinedType::what() const noexcept 
{
    return "Undefined type.\n";
}