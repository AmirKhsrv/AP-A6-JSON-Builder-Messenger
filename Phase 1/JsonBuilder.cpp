#include "JsonBuilder.hpp"

using namespace std;

JsonBuilder::JsonBuilder()
{
    numberOfObjects = 0;
    numberOfArrays = 0;
    numberOfObjects++;
    jsonObjects.push_back(new ObjectDatum(numberOfObjects, MAINO_OBJECT_KEY));
}

void JsonBuilder::addStringToObject(int parentId, std::string key, std::string value)
{
    checkErrorsForObject(parentId, key, OBJECT);
    jsonObjects[parentId]->addString(key, value);
}

void JsonBuilder::addIntegerToObject(int parentId, std::string key, int value)
{
    checkErrorsForObject(parentId, key, OBJECT);
    jsonObjects[parentId]->addInteger(key, value);
}

int JsonBuilder::addContainerToObject(int parentId, std::string key, std::string type)
{
    checkErrorsForObject(parentId, key, type);
    if (type == OBJECT)
    {
        numberOfObjects++;
        jsonObjects.push_back(jsonObjects[parentId]->addObjectToObject(numberOfObjects, key)); 
        return numberOfObjects - 1;
    }
    if (type == ARRAY)
    {
        numberOfArrays++;        
        jsonArrays.push_back(jsonObjects[parentId]->addArrayToObject(numberOfArrays, key)); 
        return numberOfArrays - 1;
    }
}

void JsonBuilder::addStringToArray(int parentId, std::string value)
{
    checkErrorsForArray(parentId, ARRAY);
    jsonArrays[parentId]->addString(value);
}

void JsonBuilder::addIntegerToArray(int parentId, int value)
{
    checkErrorsForArray(parentId, ARRAY);
    jsonArrays[parentId]->addInteger(value);
}

int JsonBuilder::addContainerToArray(int parentId, std::string type)
{
    checkErrorsForArray(parentId, type);
    if (type == OBJECT)
    {
        numberOfObjects++;
        jsonObjects.push_back(jsonArrays[parentId]->addObjectToArray(numberOfArrays)); 
        return numberOfObjects - 1;
    }
    if (type == ARRAY)
    {
        numberOfArrays++;        
        jsonArrays.push_back(jsonArrays[parentId]->addArrayToArray(numberOfArrays)); 
        return numberOfArrays - 1;
    }
}

void JsonBuilder::print(int id)
{
    if (id >= numberOfObjects || id < 0)
        throw InvalidId();
    jsonObjects[id]->setTabNumbersInPrint(0);
    jsonObjects[id]->print();
    cout << endl;
}

void JsonBuilder::checkErrorsForArray(int parentId, std::string type)
{
    if (type != ARRAY && type != OBJECT)
        throw UndefinedType();
    if (parentId >= numberOfArrays || parentId < 0)
        throw InvalidId();
}

void JsonBuilder::checkErrorsForObject(int parentId, std::string key, std::string type)
{
    if (type != ARRAY && type != OBJECT)
        throw UndefinedType();
    if (parentId >= numberOfObjects || parentId < 0)
        throw InvalidId();
    if (jsonObjects[parentId]->checkDuplicatedKeyError(key))
        throw DuplicateKey();
}
