#include "JsonBuilder.hpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int> arr,ob;
ob.push_back(0);
JsonBuilder jsonBuilder;
ob.push_back(jsonBuilder.addContainerToObject(ob[0],"zz","object"));
ob.push_back(jsonBuilder.addContainerToObject(ob[0],"zy","object"));
ob.push_back(jsonBuilder.addContainerToObject(ob[2],"zx","object"));
jsonBuilder.addIntegerToObject(ob[3],"zw",811);
ob.push_back(jsonBuilder.addContainerToObject(ob[0],"zv","object"));
jsonBuilder.addIntegerToObject(ob[4],"zu",102);
jsonBuilder.addStringToObject(ob[1],"zt","zt");
jsonBuilder.addStringToObject(ob[4],"zs","zs");
ob.push_back(jsonBuilder.addContainerToObject(ob[4],"zr","object"));
jsonBuilder.addStringToObject(ob[4],"zq","zq");
jsonBuilder.print(ob[2]);
jsonBuilder.addIntegerToObject(ob[1],"zo",1187);

}
