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

        // constructors
        Photo(){};

        Photo(string name, string path, int length, int height) : Multimedia(name,path),length(length),height(height){};

        // destructor
        ~Photo(){cerr << "Good Bye photo \n";};

        // Getters ans setters
        int getLength() const {return length;};

        int getHeight() const {return height;};

        void setLength(int length){this->length = length;};

        void setHeight(int height){this->height = height;};

        // override the method printValues
        void printValues(ostream & s) override {
            Multimedia::printValues(s); 
            s << "Length : " << length << std::endl
              << "Height : " << height << std::endl;
              
        };
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
