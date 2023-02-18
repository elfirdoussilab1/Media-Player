
#ifndef Group_h
#define Group_h

#include <list>
#include "Multimedia.h"

using namespace std;
class Group:public list<MultimediaPtr>{
    private :
        string name;
    
    public:
        /// @brief Default constructor of Group
        Group(){};
    
        /// @brief Constructor of Group
        /// @param name 
        Group(string const & name): list<MultimediaPtr>(), name(name){};
        
        
        /// @brief Getter of the name of a Group
        /// @return the name of this Group
        string const & getName() const{
            return name;
        }
        
        /// @brief Adding a Multimedia to this group
        /// @param m 
        void addMultimedia(MultimediaPtr m){
            this->push_back(m);
        }
        /// @brief Printing values of attibuts of each element of this group
        /// @param s 
        void display(ostream & s) const {
            if (this->size() == 0){
                s << "There is no element in this group : " << name << endl;;
            }
            else{
                for (auto & it: *this){ // 'it' is a MultimediaPtr
                    it->printValues(s);
                }
            }
        
        }

        /// @brief This function tells us whether a Multimedia object belong to this Group or not
        /// @param name 
        /// @return 1 if Multimedia belongs to this Group, 0 otherwise
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
