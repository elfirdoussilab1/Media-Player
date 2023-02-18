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
        
        /// @brief Default Constructor of Multimedia
        Multimedia(){};

        /// @brief constructor of Multimedia object
        /// @param name 
        /// @param path 
        Multimedia(string const & name, string const & path) ;

        // destructor is virtual because the method printValues is virtual
        virtual ~Multimedia(){};
        

        /// @brief getter of name
        /// @return the name of the Multimedia object
        string const & getName() const ;

        /// @brief getter of path
        /// @return the path to the Multimedia file
        string const & getPath() const ;

        /// @brief a setter of the name
        /// @param name (string)
        void setName(string const & name) ;

        /// @brief Setter of the path
        /// @param path (string)
        void setPath(string const & path) ;
        
        /// @brief This method is virtual because we will redefine it in subclasses of Multimedia
        /// @param s (ostram &)
        virtual void printValues(ostream & s) const;  

        /// @brief an abstract method to play the Media 
        virtual void playMedia() const = 0; 
        

};
typedef shared_ptr<Multimedia> MultimediaPtr;

#endif

