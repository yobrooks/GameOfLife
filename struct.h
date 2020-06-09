#ifndef STRUCT_H
#define STRUCT_H
#include <vector>
#include <iostream>

using namespace std;
//define struct here
struct Cell{
    char value; //MIGHT CHANGE
    int numGenActive;
    vector< pair<int, int> > neighbors;
};
#endif