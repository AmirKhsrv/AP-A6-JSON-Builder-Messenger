#ifndef JSON_BUILDER_H
#define JSON_BUILDER_H "JSON_BUILDER_H"

#include "JsonObject.hpp"
#include "Exceptions.hpp"

#include <string>
#include <vector>

const std::string ARRAY = "array";
const std::string OBJECT = "object";
const std::string MAINO_OBJECT_KEY = "";

typedef std::vector<ObjectDatum*> Objects;
typedef std::vector<ArrayDatum*> Arrays;

class JsonBuilder
{
public:
    JsonBuilder();
    void addStringToObject(int parentId, std::string key, std::string value);
    void addIntegerToObject(int parentId, std::string key, int value);
    int addContainerToObject(int parentId, std::string key, std::string type);
    void addStringToArray(int parentId, std::string value);
    void addIntegerToArray(int parentId, int value);
    int addContainerToArray(int parentId, std::string type);
    void print(int id);

private:
    void checkErrorsForArray(int parentId, std::string type);
    void checkErrorsForObject(int parentId, std::string key, std::string type);
    
    Objects jsonObjects;
    Arrays jsonArrays;
    int numberOfObjects;
    int numberOfArrays;
};

#endif 