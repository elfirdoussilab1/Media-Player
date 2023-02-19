#ifndef Requestrocessor_h
#define Requestrocessor_h
#include "Database.h"
#include <vector>
#include <map>
#include <functional>
#include <iostream>
#include <memory>

using namespace std;

// Here we define the map of functions that the server will do
extern map<string, function<string(vector<string>, DatabasePtr )>> my_functions;

// Here we declare functions that we will use to manipulate the Database
string create( vector<string>request, DatabasePtr database);

string play(vector<string> request, DatabasePtr database);


string deleteM(vector<string> request, DatabasePtr database);

string display(vector<string> request, DatabasePtr database); 

string displayAll(vector<string> request, DatabasePtr database);

#endif