#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H "JSON_OBJECT_H"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Exceptions.hpp"

const std::string KIES_IN_ARRAY = "";

class ObjectDatum;
class ArrauDatum;

class JsonDatum
{
public:
    JsonDatum(const std::string& _key);
    void setTabNumbersInPrint(const int& tabNumbers);
    virtual void print() = 0;
    std::string getKey();

protected:
    void printTabs();
    void printSeperatingComma(const int& currentDatumNumber, const int& NumberOfData);
    
    std::string key;
    int tabNumbersInPrint;
};

typedef std::vector<JsonDatum*> JsonData;

class StringDatum : public JsonDatum
{
public:
    StringDatum(const std::string& _key, const std::string& _value);
    void print();

private:
    std::string value;
};

class IntegerDatum : public JsonDatum
{
public:
    IntegerDatum(const std::string& _key, const int& _value);
    void print();

private:
    int value;
};

class ArrayDatum : public JsonDatum
{
public:
    ArrayDatum(const int& _arrayId, const std::string& _key);
    void addString(const std::string& value);
    void addInteger(const int& value);
    ObjectDatum* addObjectToArray(const int& newObjectId);
    ArrayDatum* addArrayToArray(const int& newArrayId);
    void print();
    bool checkDuplicatedKeyError(std::string key);

private:
    int arrayId;
    JsonData containingData;  
};

class ObjectDatum : public JsonDatum
{
public:
    ObjectDatum(const int& _objectId, const std::string _key);
    void addString(const std::string& _key, const std::string& value);
    void addInteger(const std::string& _key, const int& value);
    ObjectDatum* addObjectToObject(const int& newObjectId, const std::string _key);
    ArrayDatum* addArrayToObject(const int& newArrayId, const std::string _key);
    void print();
    bool checkDuplicatedKeyError(std::string key);

private:
    int objectId;
    JsonData containingData;  
};

#endif 