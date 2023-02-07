// To avoid multiple inclusions of Multimedia
#ifndef Media_Multimedia
#define Media_Multimedia

#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Multimedia {
    protected :
        string name{}; // object name
        string path{}; // path to object to be read
    
    public:
        Multimedia(){};

        Multimedia(string name, string path) ;// constructor

        virtual ~Multimedia(){};
        // destructor is virtual because the method printValues is virtual

        string getName() const ;

        string getPath() const ;

        void setName(string name) ;

        void setPath(string path) ;
        
        virtual void printValues(ostream & s); 
        // this method is virtual because we will redefine it in subclasses of Multimedia

        virtual void playMedia() const = 0; 
        // This method is abstract because we use different command to play
        // each type of Multimedia object. So it cannot be defined here.
        // Using this method we can play our Multimdia object.

};
typedef shared_ptr<Multimedia> MultimediaPtr;

#endif

