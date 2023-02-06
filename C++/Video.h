// To avoid multiple inclusions of Multimedia
#ifndef Media_Video
#define Media_Video

#include "Multimedia.h"
using namespace std;

class Video:public Multimedia {
    private:
        int duration{};
    
    public:
        Video():Multimedia(){};

        Video(string name, string path, int duration) : Multimedia(name,path), duration(duration){};

        virtual ~Video() {cerr << "Good Bye Video \n";};

        int getDuration() const {return duration;};

        void setDuration(int duration){this->duration = duration;};
        
        void printValues(ostream & s) override {
            Multimedia::printValues(s); 
            s << "Duration : " << duration << std::endl;
              
        };

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
