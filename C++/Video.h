// To avoid multiple inclusions of Multimedia
#ifndef Media_Video
#define Media_Video

#include "Multimedia.h"
using namespace std;

class Video:public Multimedia {
    private:
        int duration{};
    
    public:
        /// @brief Constructors of a Video object
        Video() : Multimedia(){};

        Video(string name, string path, int duration) : Multimedia(name,path), duration(duration){};

        /// @brief Destructor that displays "Good Bye Video " when we destroy a video object
        virtual ~Video() {cerr << "Good Bye Video \n";};

        /// @brief Getter for duration
        /// @return duration
        int getDuration() const {return duration;};

        /// @brief Setter for 
        /// @param duration 
        void setDuration(int duration){this->duration = duration;};
        
        /// @brief displaying the values of instance variables in the terminal
        /// @param s which is an ostream &
        void printValues(ostream & s) const override {
            Multimedia::printValues(s); 
            s << "Duration : " << duration << std::endl;
              
        };

        /// @brief 
        void playMedia() const override{
            // command linux
            string com_linux = "mpv " + path + " &";
            // linux command
            //system(com_linux.data()); 
            // mac command
            string com_mac = "open -a" + path + " &";
            system(com_mac.data());
        }
};
typedef shared_ptr<Video> VideoPtr;
#endif
