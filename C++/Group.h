
#ifndef Group_h
#define Group_h

#include <list>
#include "Multimedia.h"

using namespace std;
class Group:public list<MultimediaPtr>{
    private :
        string name;
    
    public:
        // constructors
        Group(){};
    
        Group(string name): list<MultimediaPtr>(), name(name){};
        
        // Getter
        string getName() const{
            return name;
        }
        
        // Printing values of attibuts of each element of this group
        void display(ostream & s) const {
            if (this->size() == 0){
                s << "There is no element in this group : " << name << endl;;
            }
            else{
                for (auto & it: *this){
                    it->printValues(s);
                }
            }
        
        }

        // Now we will define a method that returns 1 if a Multimedia object exists in the list and 0 otherwise 
        int containsMultimedia(string name){

            for (auto & it : *this){
                if (it->getName().compare(name)== 0){
                    return 1;
                }
            }
            return 0;
        }
        
        
};

typedef shared_ptr<Group> GroupPtr;
#endif /* Group_h */
