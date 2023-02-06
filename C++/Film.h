#ifndef Media_Film
#define Media_Film

#include "Video.h"
using namespace std;

class Film:public Video{
    private:

        int n_chapters{};
        int* chapters;

    public :

    Film():Video(){};

    Film(string name, string path, int duration, int n_chapters, int* chapters_): Video(name,path, duration), n_chapters(n_chapters){
        chapters = new int[n_chapters];
        for (int i=0; i<n_chapters; i++){
            chapters[i] = chapters_[i];
        }
    };
    
    ~Film(){
        delete[] chapters;
        cout << "Good bye Film \n";
    }

    // Getters
    const int * getChapters() const { // this array should not be changed by the user exept by the function setChapters
        return chapters;
    };

    int getNumberOfChapters() const{
        return n_chapters;
    };

    // Setters
    void setChapters(int new_n_chapters, int * new_chapters){
        // verify if one of the parameters are null
        if ((new_n_chapters ==0) || (new_chapters == nullptr)){
            n_chapters = 0;
            delete[] chapters;
            chapters = nullptr;
        }
        // If parameters are not null
        if ((new_n_chapters !=0) && (new_chapters != nullptr)){
            
                // the new number of chapters is not 0
                n_chapters = new_n_chapters;
                chapters = new int[n_chapters];
                for (int i=0; i<n_chapters; i++){
                    chapters[i] = new_chapters[i];
                
            }
        }
    };

    void printValues(ostream & s) final {
        Video::printValues(s);
        for (int i=0; i<n_chapters; i++){
            s << " Duration of Chapter " << i+1 << " : " << chapters[i] << std::endl;
        }
    }

};
typedef shared_ptr<Film> FilmPtr;
#endif
