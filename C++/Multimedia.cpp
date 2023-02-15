#include "Multimedia.h"
#include <sstream>
// Implementatin of all methods declared in Multimedia.h

Multimedia::Multimedia(std::string name, std::string path){
    this->name = name;
    this->path = path;
}

std::string Multimedia::getName() const {
    return name;
}
std::string Multimedia::getPath() const {
    return path;
}
void Multimedia::setName(std::string name){
    this->name = name;
}
void Multimedia::setPath(std::string path){
    this->path = path;
}
void Multimedia::printValues(std::ostream & s) const {
    s << "Name : " << name << std::endl
      << "Path : " << path << std::endl;    
}