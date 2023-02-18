#include "Multimedia.h"
#include <iostream>
// Implementatin of all methods declared in Multimedia.h
using namespace std;

/// @brief constructor of Multimedia object
/// @param name 
/// @param path 
Multimedia::Multimedia(string const & name, string const & path){
    this->name = name;
    this->path = path;
}

/// @brief getter of name
/// @return the name of the Multimedia object
string const & Multimedia::getName() const {
    return name;
}

/// @brief getter of path
/// @return the path to the Multimedia file
string const & Multimedia::getPath() const {
    return path;
}

/// @brief a setter of the name
/// @param name (string)
void Multimedia::setName(string const & name){
    this->name = name;
}

/// @brief Setter of the path
/// @param path (string)
void Multimedia::setPath(string const & path){
    this->path = path;
}


/// @brief This method displays in the output stream s the values of each variable of the Multimedia object
/// @param s 
void Multimedia::printValues(ostream & s) const {
    s << "Name : " << name << std::endl
      << "Path : " << path << std::endl;    
}