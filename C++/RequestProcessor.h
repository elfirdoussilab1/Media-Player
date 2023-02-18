#ifndef Requestrocessor_h
#define Requestrocessor_h
#include "Database.h"
#include <vector>
#include <map>
#include <functional>

using namespace std;

// Here we define the map of functions that the server will do
map<string, std::function <string const &(vector<string> const &, DatabasePtr )>> my_functions;

// Here we declare functions that we will use to manipulate the Database
string const & create( vector<string> const & request, DatabasePtr database);

string const & play(vector<string> const & request, DatabasePtr database);


string const & deleteM(vector<string> const & request, DatabasePtr database);

string const & display(vector<string> const & request, DatabasePtr database); 

string const & displayAll(vector<string> const & request, DatabasePtr database);

#endif