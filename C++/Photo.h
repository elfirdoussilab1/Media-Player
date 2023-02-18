// To avoid multiple inclusions of Multimedia

#ifndef Media_Photo
#define Media_Photo

#include "Multimedia.h"
using namespace std;

class Photo:public Multimedia {
    private:
        int length{};
        int height{};

    public:

        /// @brief Default Constructor of Photo
        Photo() : Multimedia(){};

        /// @brief Constructor of Photo
        /// @param name 
        /// @param path 
        /// @param length 
        /// @param height 
        Photo(string const & name, string const & path, int length, int height) : Multimedia(name,path),length(length),height(height){};

        
        /// @brief Destructor of photo
        ~Photo(){cerr << "Good Bye photo \n";}

        
        /// @brief Getter of length
        /// @return length of the photo (int)
        int getLength() const {return length;}

        /// @brief getter of height
        /// @return height of the photo (int)
        int getHeight() const {return height;}

        /// @brief Setter of length
        /// @param length 
        void setLength(int length){this->length = length;}

        /// @brief setter of height
        /// @param height 
        void setHeight(int height){this->height = height;}

        
        /// @brief Dsiplaying values of instance variables
        /// @param s 
        void printValues(ostream & s) const override {
            Multimedia::printValues(s); 
            s << "Length : " << length << std::endl
              << "Height : " << height << std::endl;
              
        }

        /// @brief Opening the Photo and showing it
        void playMedia() const override {
            // command linux
            string com_linux = "imagej " + path + " &";
            // linux command
            //system(com_linux.data()); 
            // mac command
            string com_mac = "open " + path + " &";
            system(com_mac.data()); 

        }

};
typedef shared_ptr<Photo> PhotoPtr;
#endif
