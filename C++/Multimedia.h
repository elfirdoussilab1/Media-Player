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
        // constructor that doesn't take any argumet
        Multimedia(){};

        /// @brief constructor of Multimedia object
        /// @param name 
        /// @param path 
        Multimedia(string name, string path) ;

        // destructor is virtual because the method printValues is virtual
        virtual ~Multimedia(){};
        

        /// @brief getter for name
        /// @return the name of the Multimedia object
        string getName() const ;

        /// @brief getter of path
        /// @return the path to the Multimedia file
        string getPath() const ;

        /// @brief a setter for the name
        /// @param name 
        void setName(string name) ;

        /// @brief Setterfor the path
        /// @param path 
        void setPath(string path) ;
        
        /// @brief This method is virtual because we will redefine it in subclasses of Multimedia
        /// @param s 
        virtual void printValues(ostream & s) const;  

        /// @brief 
        virtual void playMedia() const = 0; 
        // This method is abstract because we use different command to play
        // each type of Multimedia object. So it cannot be defined here.
        // Using this method we can play our Multimdia object.

};
typedef shared_ptr<Multimedia> MultimediaPtr;

#endif

