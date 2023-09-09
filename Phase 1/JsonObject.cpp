#include "JsonObject.hpp"

using namespace std;

JsonDatum::JsonDatum(const string& _key)
{
    key = _key;
}

StringDatum::StringDatum(const string& _key, const string& _value)
                        : JsonDatum(_key)
{
    value = _value;
}

IntegerDatum::IntegerDatum(const string& _key, const int& _value)
                            : JsonDatum(_key)
{
    value = _value;
}

ArrayDatum::ArrayDatum(const int& _arrayId, const string& _key)
                        : JsonDatum(_key)
{
    arrayId = _arrayId;
}

ObjectDatum::ObjectDatum(const int& _objectId, const std::string _key)
                        : JsonDatum(_key)
{
    objectId = _objectId;
}

void ObjectDatum::addString(const string& _key, const string& value)
{
    containingData.push_back(new StringDatum(_key, value));
}

void ObjectDatum::addInteger(const std::string& _key, const int& value)
{
    containingData.push_back(new IntegerDatum(_key, value));
}

ObjectDatum* ObjectDatum::addObjectToObject(const int& newObjectId, const std::string _key)
{
    ObjectDatum* newObject = new ObjectDatum(newObjectId, _key);
    containingData.push_back(newObject);
    return newObject;
}

ArrayDatum* ObjectDatum::addArrayToObject(const int& newArrayId, const std::string _key)
{
    ArrayDatum* newArray = new ArrayDatum(newArrayId, _key);
    containingData.push_back(newArray);
    return newArray;
}

void ArrayDatum::addString(const string& value)
{
    containingData.push_back(new StringDatum(KIES_IN_ARRAY, value));
}

void ArrayDatum::addInteger(const int& value)
{
    containingData.push_back(new IntegerDatum(KIES_IN_ARRAY, value));
}

ObjectDatum* ArrayDatum::addObjectToArray(const int& newObjectId)
{
    ObjectDatum* newObject = new ObjectDatum(newObjectId, KIES_IN_ARRAY);
    containingData.push_back(newObject);
    return newObject;
}

ArrayDatum* ArrayDatum::addArrayToArray(const int& newArrayId)
{
    ArrayDatum* newArray = new ArrayDatum(newArrayId, KIES_IN_ARRAY);
    containingData.push_back(newArray);
    return newArray;
}

void JsonDatum::setTabNumbersInPrint(const int& tabNumbers)
{
    tabNumbersInPrint = tabNumbers;
}

void StringDatum::print()
{
    printTabs();
    if (key == KIES_IN_ARRAY)
        cout << "\"" << value << "\"";
    else
        cout << "\"" << key << "\"" << ": " << "\"" << value << "\"";
}

void IntegerDatum::print()
{
    printTabs();
    if (key == KIES_IN_ARRAY)
        cout << value;
    else
        cout << "\"" << key << "\"" << ": " << value;
}

void ArrayDatum::print()
{
    printTabs();
    if (key != KIES_IN_ARRAY)
        cout << "\"" << key << "\": ";
    cout << "["; 
    if (containingData.size() != 0)
    {
        cout << endl;
        for (int i = 0; i < containingData.size(); i++)
        {
            containingData[i]->setTabNumbersInPrint(tabNumbersInPrint + 1);
            containingData[i]->print();
            printSeperatingComma(i, containingData.size());
        }
        printTabs();
    }
    cout << "]";
}

void ObjectDatum::print()
{
    printTabs();
    if (key != KIES_IN_ARRAY && tabNumbersInPrint != 0)
        cout << "\"" << key << "\": "; 
    cout << "{"; 
    if (containingData.size() != 0)
    {
        cout << endl;
        for (int i = 0; i < containingData.size(); i++)
        {
            containingData[i]->setTabNumbersInPrint(tabNumbersInPrint + 1);
            containingData[i]->print();
            printSeperatingComma(i, containingData.size());
        }
        printTabs();
    }
    cout << "}";
}

void JsonDatum::printTabs()
{
    for (int i = 0; i < tabNumbersInPrint; i++)
        cout << "    ";
}

void JsonDatum::printSeperatingComma(const int& currentDatumNumber, const int& NumberOfData)
{
    if (currentDatumNumber < NumberOfData - 1)
        cout << "," << endl;
    if (currentDatumNumber >= NumberOfData - 1)
        cout << endl;
}

bool ObjectDatum::checkDuplicatedKeyError(std::string key)
{
    for (int i = 0; i < containingData.size(); i++)
        if (key == containingData[i]->getKey())
            return true;
    return false;
}

bool ArrayDatum::checkDuplicatedKeyError(std::string key)
{
    for (int i = 0; i < containingData.size(); i++)
        if (key == containingData[i]->getKey())
            return true;
    return false;
}

string JsonDatum::getKey()
{
    return key;
}
